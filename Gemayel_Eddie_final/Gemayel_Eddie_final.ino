
#include <SPI.h>
#include <Ethernet.h>

int led = 8;
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
  pinMode(led,OUTPUT);
//  digitalWrite(led,HIGH);
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
         
          client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
          client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");        
 
          client.println("</BODY>");
          client.println("</HTML>");
 
          delay(1);
          //stopping client
          client.stop();
 
          ///////////////////// control arduino pin
          if(readString.indexOf("?lighton") >0)//checks for on
          {
            digitalWrite(8, HIGH);    
            Serial.println("Led On");
          }
          else{
          if(readString.indexOf("?lightoff") >0)//checks for off
          {
            digitalWrite(8, LOW);    
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

