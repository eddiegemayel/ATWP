//Eddie Gemayel
//capstone final

//includes
#include <SPI.h>
#include <Ethernet.h>

//pin ints
int green = 5;
int blue = 6;
int red = 9;

//int brightness = 255;
//String POST = ""; 
//boolean SET = true;

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

  
 // Open serial communications and wait for port to open
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  
  // start the Ethernet connection and the server:
  Ethernet.begin(mac);
  server.begin();
  Serial.print("Server is at ");
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
         
         
         //html start
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE>Eddie's Arduino</TITLE>");
          client.println("<link href='http://fonts.googleapis.com/css?family=Lato' rel='stylesheet' type='text/css'>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<H1 class='center'>Remote Light Controller</H1>");
          client.println("<hr/>");
          client.println("<h2 class='center'>Choose a color:</h2>");
          
          
          //confirms to user which led is on
          if (readString.indexOf("?lightblue")>0){
          client.print(" <p>LED is now <font color='blue'>blue.</font></p>");
          }else if(readString.indexOf("?lightred")>0){
            client.print(" <p>LED is now <font color='red'><strong>red</strong>.</font></p>");
          }
           else if(readString.indexOf("?lightgreen")>0){
            client.print(" <p>LED is now <font color='green'><strong>green</strong>.</font></p>");
          }
         
           else if(readString.indexOf("?lightoff")>0){
            client.print("<p> LED is now <strong>off</strong>.</p>");
          }
          
          //couple styles
          client.println("<style>   h1, h2{font-family: 'Lato', sans-serif; color:#FF5951;} h2{color:#A597FF;} a:visited{color: black;} a{color:black; font-family: 'Lato', sans-serif; text-decoration:none; margin-bottom: 2%;} .center{vertical-align:middle; text-align:center;} p{font-family: sans-serif; vertical-align:middle; text-align:center;}</style>");
          
//          .blue{color:#4069E8;} .red{color: #FF1D19;} .green{color:#49E831;} 
//          <span class='blue'>
          client.println();
          
            //links to change led
           client.println("<ul style='vertical-align:middle; margin-left: 45%;' >");
              client.println("<a  href=\"/?lightblue\"\">Blue Light</a><br/>");
              client.println("");
              client.println("<a  href=\"/?lightgreen\"\">Green Light</a><br/>");
               client.println("");
               client.println("<a  href=\"/?lightred\"\">Red Light</a><br/>");
             client.println("<a  href=\"/?lightoff\"\">Turn Off Light</a><br />");  
           client.println("</ul>");
           
           
          client.println("</BODY>");
          client.println("</HTML>");
 
          delay(1);
          //stopping client
          client.stop();
 
          ///////////////////// control arduino pin
          if(readString.indexOf("?lightblue") >0)//checks for on
          {
  
  
              analogWrite(blue, 0); // turn on blue
//           
              analogWrite(green, 255); // turn off blue
              analogWrite(red, 255);
           
            
            Serial.println("blue On");
          }
          else if(readString.indexOf("?lightgreen") >0)//checks for on
          {
  
  
              analogWrite(green, 0); // turn on 
//          
              analogWrite(blue, 255); // turn off 
              analogWrite(red, 255);

           
  
            Serial.println("green On");
          }
          else if(readString.indexOf("?lightred") >0)//checks for on
          {
  
  
              analogWrite(red, 0); // turn on 
//             
              analogWrite(blue, 255); // turn off 
              analogWrite(green, 255);

           
  
            Serial.println("red On");
          }
          
          else if(readString.indexOf("?lightoff")>0){
            analogWrite(red, 255); // turn off 
              analogWrite(blue, 255); // turn off 
              analogWrite(green, 255);
              Serial.println("light off");
          }
          
  
          //clearing string for next read
          readString="";
 

        }
}

}
}
}

