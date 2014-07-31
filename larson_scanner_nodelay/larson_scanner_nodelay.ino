
long nextUpdate =0;
long updateInterval = 100;
int button = 2;
int nextLedInterval =1;
boolean win = false;
boolean go = true;
int timer = 0;
int currentLed =9;

//setup all pins on the board
//they all start out off
void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  Serial.begin(57600);
}

//loop calls function every time milliseconds is larger than 0
void loop(){
  while(win== false && go==true){
    if(millis()>nextUpdate){
      
      updateLarson();
      
      Serial.println("Going");
      
      //if the user pushes the button on the middle node
      if(digitalRead(button) == LOW && currentLed == 11){
        //stop going
        go = false;
        //tell them they win
        Serial.println("WINNER");
        //win becomes true
        win = true;
        
        //flash winner lights
        delay(200);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(11, HIGH);
        delay(200);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(11, HIGH);
        delay(200);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(11, HIGH);
        delay(200);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(11, HIGH);
        
        //delay before restart
        delay(2700);
        
        //go back to going
        win = false;
        go = true;
        
       //if they pick wrong
       }else if(digitalRead(button) == LOW){
        //tell them they lose the game
        Serial.println("LOSER");
        win =false;
        delay(2500);
      
        }  
      
     }//millis end
   }//while end
    
 }//loop end



//function
void updateLarson(){
  //start at the beggining (LED 9) and move forward
  if (currentLed ==9){
    nextLedInterval = 1;
  }
  
  //if its at the end (LED 13) go the other way
  if(currentLed ==13){
    nextLedInterval = -1;
  }
  
  //the next LED to be activated is equal to
  //the current LED plus the next interval which is either
  //one or negative one
  int nextLed = currentLed += nextLedInterval;
   
   //for loop 
  for(int i =8; i<13; i++){
    //if the looped LED equals the next one
    int loopLed = i+1;
    
    
    if(loopLed == nextLed){
      //then turn it on  
      digitalWrite(loopLed, HIGH);
    }else{
      //otherwise keep it off
      digitalWrite(loopLed, LOW);
    }
  }
  
  //after this runs, the old current LED switches to new current one that needs to be switched on
  //in other words we need to update the currentLED obviously
  currentLed= nextLed;
  
  //the next update is in milliseconds plus 200
  nextUpdate = millis() + updateInterval;

}
