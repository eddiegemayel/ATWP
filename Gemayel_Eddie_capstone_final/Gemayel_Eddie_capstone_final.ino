
#include <SPI.h>
#include <Ethernet.h>

int led = 5;
int led2 = 6;
int led3 = 9;
int brightness = 255;
//String POST = ""; 
boolean SET = true;
String readString;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0x20, 0xc9, 0xd0, 0xb8, 0xdb, 0x41 };
IPAddress ip(192,168,1,177);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
//  pinMode(led,OUTPUT);

 // Open serial communications and wait for port to open
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  
  
}

void loop() { // listen for incoming clients
EthernetClient client = server.available(); 
//digitalWrite(led, HIGH); 
if (client) { Serial.println("new client");
// an http request ends with a blank line
boolean currentLineIsBlank = true; 
while (client.connected()) { 
if (client.available()) { 
char c = client.read(); 
Serial.write(c); 
 readString += c;


 //if HTTP request has ended
        if (c == '\n') {
 
          ///////////////
          Serial.println("NEW LINE");
          Serial.println(readString); //print to serial monitor for debuging
 
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();
 
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE>Eddie's Arduino</TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<H1>House Light Control</H1>");
          client.println("<hr />");
          client.println("<br />");
         
          client.println("<a href=\"/?lightred\"\">Turn On Red Light</a>");
          client.println("<a href=\"/?lightblue\"\">Turn On Blue Light</a>");
          client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");        
 
          client.println("</BODY>");
          client.println("</HTML>");
 
          delay(1);
          //stopping client
          client.stop();
 
          ///////////////////// control arduino pin
          if(readString.indexOf("?lightred") >0)//checks for on
          {
             for(int fade = 255 ; fade >= 0; fade -=5) { 
            // sets the value (range from 0 to 255):
              analogWrite(led, fade);         
              // wait for 30 milliseconds to see the dimming effect 
     
              delay(20);                            
              }
  
               for(int fade = 0 ; fade<=250; fade +=5) { 
              // sets the value (range from 0 to 255):
              analogWrite(led, fade);         
                // wait for 30 milliseconds to see the dimming effect 
     
                delay(20);                            
                }
  
            Serial.println("Red On");
          }
          else{
            if(readString.indexOf("?lightoff") >0)//checks for off
            {
              analogWrite(5, 0);   
              analogWrite(6, 0);
              analogWrite(9, 0); 
              Serial.println("Led Off");
            }
          }
          
          
          
          //clearing string for next read
          readString="";
 



        }
}

}
}
}

