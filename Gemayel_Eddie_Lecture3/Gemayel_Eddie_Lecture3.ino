
int led = 3; // the pin that the LED is attached to
int led2 = 5;
int led3 = 6;
int brightness = 255;


// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
//  pinMode(led, OUTPUT);
//  pinMode(led2, OUTPUT);
//  pinMode(led3, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
 

  
  for(int fade = 255 ; fade >= 0; fade -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led, fade);         
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }
  
   for(int fade = 0 ; fade<=250; fade +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led, fade);         
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }
  
     for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect 
 
     
    delay(20);                            
  }
  
    for(int fade = 0 ; fade <= 255; fade +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fade);         
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }
  
  
  
     for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led3, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect 
 
     
    delay(20);                            
  }
  
    for(int fade = 0 ; fade <= 255; fade +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led3, fade);         
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }
  
  
  
  
    for(int fade = 255 ; fade >= 0; fade -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fade);   
    analogWrite(led3, fade);    
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }
  
   for(int fade = 0 ; fade<=250; fade +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fade);
    analogWrite(led3, fade);         
    // wait for 30 milliseconds to see the dimming effect 
     
    delay(20);                            
  }

}
