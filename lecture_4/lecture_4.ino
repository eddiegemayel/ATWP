void setup(){
  pinMode(A0, INPUT);
  pinMode(10, INPUT);
  
  Serial.begin(57600);
}


void loop(){
  int val = analogRead(A0);
  
  
  Serial.print("A0 = ");
  Serial.println(val);
  
  //new range of numbers for the analog
  //map(variable, from low, from high, to low, to high)
//  int mappedVal = map(val, 0 , 1023, 0 ,255);

  int mappedVal = map(val, 300 , 1000, 0 ,255);

  
  analogWrite(10, mappedVal);
  
  delay(100);

}
