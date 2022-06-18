/*
 * fx finger x
 * f1 f2 f3
 *  2  5  8  
 *  3  6  9
 *  4  7  10
 * 
 */




struct letter{
  /*
  *   f1   f2
  *    0   3
  *    1   4
  *    2   5
  */
  int alpha[6]={0};
};

letter l;

void setup() {
 
  Serial.begin(9600);
  
  for(int p=2;p<8;p++)
    pinMode(p,INPUT_PULLUP);
 
  for(int p=11;p<14;p++)
    pinMode(p,INPUT_PULLUP);
 
}

void loop() {
  
  for(int p=2;p<14;p++){
    if(!digitalRead(p)){
      if(p<8)
        update_letter(p);
        
      if(p==11)
        print_letter('a');  // a for alphabet and n for numbers
        
      if(p==12)
        print_letter('n');  // a for alphabet and n for numbers
    }
      
     delay(10);
  }

}
