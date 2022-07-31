/*
 * fx finger x
 * f1 f2 f3
 *  2  7  11  
 *  3  5  12
 *  4  6  13
 * 
 */

// array that will hold the user input
int alpha[6]={0}; 

void setup() {
 
  Serial.begin(9600);

  // init the GPIO pins as input with pullups
  for(int p=2;p<8;p++)
    pinMode(p,INPUT_PULLUP);
 
  for(int p=11;p<14;p++)
    pinMode(p,INPUT_PULLUP);
 
}

void loop() {
  
  for(int p=2;p<14;p++){
    if(!digitalRead(p)){
        delay(100);
      // if the GPIO pin is <8 then the user is still taping the letter
      if(p<8)
        update_letter(p);

      // if the GPIO pin is 11 then the user want to show a character
      if(p==11)
        print_letter('a');  // a for alphabet and n for numbers

      // if the GPIO pin is 12 then the user want to show a number
      if(p==12)
        print_letter('n');  // a for alphabet and n for numbers
        
      // if the GPIO pin is 13 then the user want to edit the character or press the Enter button
      if(p==13)
        print_letter('e');
    }
      
     delay(10);
  }

}
