void setup(){
  Serial.begin(57600);
  pinMode(13, OUTPUT);
}

void loop(){
  
  String inputs;
  
  while(Serial.available()>0){
    char thisChar = Serial.read();
   inputs += thisChar;
    Serial.print("You said: ");
    Serial.println(thisChar);
    if(thisChar == ';'){
      ///digitalWrite(13, HIGH);
      Serial.println("GOT IT");
      Serial.println(inputs);
      inputs ="";
    }
//    else{
//      digitalWrite(13,LOW);
//    }
  }
  
}
