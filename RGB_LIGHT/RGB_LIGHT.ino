String voice;

#define GREEN 10
#define BLUE 9
#define RED 11
#define LIGHT 6
#define AC 7

void setup() 
{                                            
  Serial.begin(9600);
   pinMode(LIGHT, OUTPUT);
  pinMode(AC, OUTPUT);
   analogWrite(LIGHT,255);                    // Since LED must be off in the beginning
   analogWrite(AC,255);
   pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
   analogWrite(RED,255); 
   analogWrite(GREEN,255);                    // Since LED must be off in the beginning
   analogWrite(BLUE,255);
}

  int redVal;
  int greenVal;
  int blueVal;
  int lightVal;
  int acVal;
void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);

       if(voice == "*red")                               
     {
     analogWrite(RED,0); 
     analogWrite(GREEN,255);
     analogWrite(BLUE,255);
     }  
  else if(voice == "*green")                            
     {
    analogWrite(GREEN,0);
    analogWrite(RED,255);
    analogWrite(BLUE,255);
     }
  else if(voice == "*blue")                    
     {
    analogWrite(RED,255);
    analogWrite(BLUE,0);
    analogWrite(GREEN,255);
     }
  
  else if(voice == "*white")                            
     {
    analogWrite(RED,0);
    analogWrite(GREEN,0);
    analogWrite(BLUE,0);
     }
   else if(voice == "*good night")                       
     {
    analogWrite(RED,255);
    analogWrite(GREEN,255);
    analogWrite(BLUE,255);
    analogWrite(LIGHT,255);                   
   analogWrite(AC,255);
     }
     else if(voice == "*start")
     {
     analogWrite(LIGHT,0);                
   analogWrite(AC,0);
     }
     else if(voice == "*stop")                      
     {
       analogWrite(LIGHT,255);                  
   analogWrite(AC,255);
     }
     else if(voice == "*light")                        
     {
   analogWrite(LIGHT,0);    
   analogWrite(AC,255);
     }
     else if(voice == "*fan")                         
     {
      analogWrite(AC,0);
     analogWrite(LIGHT,255);  
     }
    
    else if(voice == "*dance")                     
     {
     redVal = 255; 
     blueVal = 0;
     greenVal = 0;
     for(int i = 0; i < 255; i += 1) 
    {
    greenVal += 1;
    redVal -= 1;
    analogWrite(GREEN, 255 - greenVal);
    analogWrite(RED, 255 - redVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWrite(BLUE, 255 - blueVal);
    analogWrite(GREEN, 255 - greenVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);
    delay(10);
  }
   }
voice="";                                                       //Reset the variable after initiating
}
}
