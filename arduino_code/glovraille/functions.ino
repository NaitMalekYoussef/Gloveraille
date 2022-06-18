
void update_letter(int i){
  
  int index=i-2;
  l.alpha[index]=1;
  
 /*for(int i=0;i<3;i++){
    Serial.print(l.alpha[i]);
    Serial.print("\t");
    Serial.println(l.alpha[i+3]);
   
  }  Serial.println();*/
}

void print_letter(char t){
  long n=0;
  long mult=100000;
  for(int i=0;i<6;i++){
    n+=mult*l.alpha[i];
    l.alpha[i]=0;
    mult/=10;
  }
 //Serial.print("n= ");
  //Serial.println(n);
  char c;
  switch(n){
    case 100000:
      c=(t=='a')?'A':'1';
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
      c=' ';
  }
  //Serial.print("c= ");
  Serial.print(c);
  //Serial.println();
  delay(100);
}
