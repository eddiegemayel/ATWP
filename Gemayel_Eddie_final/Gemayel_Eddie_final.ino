
#include <SPI.h>
#include <Ethernet.h>

int led = 8;
//String POST = ""; 
boolean SET = true;

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
digitalWrite(led, HIGH); 
if (client) { Serial.println("new client");
// an http request ends with a blank line
boolean currentLineIsBlank = true; 
while (client.connected()) { 
if (client.available()) { 
char c = client.read(); 
Serial.write(c); // if you've gotten to the end of the line (received a newline // character) and the line is blank, the http request has ended, 
// so you can send a reply 
if (c == '\n' && currentLineIsBlank) { 
// it is after the double cr-lf that the variables are 
// read another line! 
String POST = ""; 
while(client.available()) { 
  c = client.read(); 
  // save the variables somewhere 
  POST += c; 
} 
if(POST != "") { 
if(POST == "status=1"){ 
  SET = true; 
  Serial.println("onnnnnnnnnnnnn"); 
  digitalWrite(led, HIGH);
}else{ 
  SET = false; 
  digitalWrite(led, LOW);
  Serial.println("offffffffffff");
} 
} 

// send a standard http response header 
client.println("HTTP/1.1 200 OK"); 
client.println("Content-Type: text/html"); 
client.println("Connnection: close"); 
client.println(); client.println(""); 
client.println("Eddie's Arudino"); 
client.println(""); 
client.println(""); 
client.println(""); 

if (digitalRead(8)){
          client.print(" LED is <font color='green'>ON</font>");
        }else{
          client.print(" LED is <font color='red'>OFF</font>");
        }
          client.println("<br />");

          client.print("<FORM action=\”http://192.168.1.177/\” >");
          client.print("<P> <INPUT type=\"radio\" name=\"status\" value=\"1\">ON");
          client.print("<P> <INPUT type=\"radio\" name=\"status\" value=\"0\">OFF");
//          client.print("<p></form>");
          client.print("<P> <INPUT type=\"submit\" value=\"Submit\"> </FORM>");
          




client.println(""); 
//break; 
}





if (c == '\n') { 
// you're starting a new line 
currentLineIsBlank = true;
} else if (c != '\r') { 
// you've gotten a character on the current line 
currentLineIsBlank = false;
} 
} 
}
// give the web browser time to receive the data 
delay(1); // close the connection: 
client.stop(); 
Serial.println("client disconnected"); 
} 
if(SET == true){ 
digitalWrite(led, HIGH); 
}else{ 
digitalWrite(led, LOW); 
} 
}
