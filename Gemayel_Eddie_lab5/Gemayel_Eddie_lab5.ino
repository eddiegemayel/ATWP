// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int btnInput = 2;
int led = 5;
int led2= 6;
int led3 = 11;

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   pinMode(btnInput, INPUT_PULLUP);
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
  Serial.begin(57600);
} 
 
 
void loop() 
{ 
 
    
    while(digitalRead(btnInput) == HIGH){
       digitalWrite(led,LOW);
     digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      
    }
  
   if(digitalRead(btnInput)== LOW){
    Serial.println("1");
    
    digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
     digitalWrite(led, HIGH);
     digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);

  
    
       
    for(pos = 0; pos < 180; pos += 1){  // goes from 0 degrees to 180 degrees 
                                    // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    
   digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
     digitalWrite(led, HIGH);
     digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
  
    
    for(pos = 180; pos>=1; pos-=1){     // goes from 180 degrees to 0 degrees 
                                    
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(15);                       // waits 15ms for the servo to reach the position 
    } 
    
   
   digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
     digitalWrite(led, HIGH);
     digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(100);
  
 
  
    }else{
      Serial.println("0");
    }
    delay(100);
} 
