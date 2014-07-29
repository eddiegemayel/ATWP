

/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>

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
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
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


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while(client.connected()) {
      if (client.available()) {
        int digitalRequests = 0;  
        int analogRequests = 0;
     
        
        
        
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
	 // client.println("Refresh: 10");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          
       if (digitalRead(8)){
          client.print(" LED is <font color='green'>ON</font>");
        }else{
          client.print(" LED is <font color='red'>OFF</font>");
        }
          client.println("<br />");

          client.print("<FORM action=\”http://192.168.1.177/\” >");
          client.print("<P> <INPUT type=\"radio\" name=\"status\" value=\"1\">ON");
          client.print("<P> <INPUT type=\"radio\" name=\"status\" value=\"0\">OFF");
          client.print("<P> <INPUT type=\"submit\" value=\"Submit\"> </FORM>");
          
          char c = client.read();
          
          if (c == '\n') {

//          currentLineIsBlank = true;
//          buffer="";
//          } else if (c == '\r') {
//          if(buffer.indexOf("GET /?status=1")>=0)
//            digitalWrite(8,HIGH);
//
//          if(buffer.indexOf("GET /?status=0")>=0)
//            digitalWrite(8,LOW);
//          }
//          
//          
//          
//          break;
        
      }
      
      
      
      
    }
    
    
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

