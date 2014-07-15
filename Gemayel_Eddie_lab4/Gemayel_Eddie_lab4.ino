/*
  This code turns off or on led light with knob
 */

int potVal = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600
  //set LED pin number
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("Brightness Level: ");
  Serial.println(sensorValue);
  
  //sensor values divided by 42 so the led will fully turn off
  potVal = analogRead(sensorValue);            // read the value from the sensor
  potVal = map(potVal/42, 0, 1023, 0, 255);  // scale it to use it with the LED
   
   //rewrite led light with new value
  analogWrite(11, potVal);  
  delay(50);        // delay in between reads for stability
}

