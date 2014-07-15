int btnInput = 2;
int outputLed = 13;

void setup(){
//  pinMode(btnInput, INPUT);
  pinMode(btnInput, INPUT_PULLUP);
  pinMode(outputLed, OUTPUT);
  Serial.begin(57600);
}

//millis()

void loop(){
  if(digitalRead(btnInput)== LOW){
    Serial.println("1");
    digitalWrite(outputLed, HIGH);
  }else{
    Serial.println("0");
    digitalWrite(outputLed, LOW);
  }
  delay(100);
}
