int led1 = 13;
int led2 = 12;
int led3=11;
int led4=10;
int led5=9;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);    
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(50);               // wait for a second
  digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(50);     
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(100);  
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(50);
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(50);
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(50);
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(50);
   digitalWrite(led1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(50);
}
