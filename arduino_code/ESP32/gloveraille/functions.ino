void update_letter(int i){
  int index;
    switch(i){
        case P6:
            index=0;
            break;
        case P7:
            index=1;
            break;
        case P8:
            index=2;
            break;
        case P9:
            index=3;
            break;
        case P10:
            index=4;
            break;
        case P11:
            index=5;
            break;
    }
    Serial.print(index);
  // update the alphabet
  alpha[index]=1;
}

// function to init the alpha array
void init_alpha(){
  for(int i=0;i<6;i++){
    alpha[i]=0;
  }
}

// function that will print the letter
void print_letter(char t){
  long n=0;
  long mult=100000;
  for(int i=0;i<6;i++){
    n+=mult*alpha[i];
    alpha[i]=0;
    mult/=10;
  }
  Serial.println(n);

  // edit the letter or send the Enter char
  if(t=='e'){
    if(n!=0){
      init_alpha(); //edit the letter
      Serial.println(" <<Letter edited>> ");
       
    }else{
      Serial.println();
      Serial.println(" <<Enter pressed>>");
       bleKeyboard.press(KEY_RETURN);
      
    }
    
    bleKeyboard.releaseAll();
    return; // no need to print the letter
  }
  

  char c;  // the character to be printed
  
  switch(n){
    case 100000:
      c=(t=='a')?'A':'1'; // if the argument is equal to 'a' then the user want to print a character, else a number
      break;
    case 110000:
      c=(t=='a')?'B':'2';
      break;
    case 100100:
      c=(t=='a')?'C':'3';
      break;
    case 100110:
      c=(t=='a')?'D':'4';
      break;
    case 100010:
      c=(t=='a')?'E':'5';
      break;
    case 110100:
      c=(t=='a')?'F':'6';
      break;
    case 110110:
      c=(t=='a')?'G':'7';
      break;
    case 110010:
      c=(t=='a')?'H':'8';
      break;
    case 10100:
      c=(t=='a')?'I':'9';
      break;
    case 10110:
      c=(t=='a')?'J':'0';
      break;
    case 101000:
      c='K';
      break;
    case 111000:
      c='L';
      break;
    case 101100:
      c='M';
      break;
    case 101110:
      c='N';
      break;
    case 101010:
      c='O';
      break;
    case 111100:
      c='P';
      break;
    case 111110:
      c='Q';
      break;
    case 111010:
      c='R';
      break;
    case 11100:
      c='S';
      break;
    case 11110:
      c='T';
      break;
    case 101001:
      c='U';
      break;
    case 111001:
      c='V';
      break;
    case 10111:
      c='W';
      break;
    case 101101:
      c='X';
      break;
    case 101111:
      c='Y';
      break;
    case 101011:
      c='Z';
      break;
    case 11001:
      c='?';
      break;
    case 11010:
      c='!';
      break;
    case 10000:
      c='\'';
      break;
    case 1111:
      c='#';
      break;
    case 1:
      c='.';
      break;
    case 10010:
      c=':';
      break;
    case 1100:
      c='/';
      break;
      
    default:
      c=' '; // the default character is space.
      
        

  }

  if(c==' ' && t=='n')
    bleKeyboard.press(KEY_BACKSPACE);
  else
   bleKeyboard.write(c);
  bleKeyboard.releaseAll(); 
  Serial.print(c);
  delay(100);
}
