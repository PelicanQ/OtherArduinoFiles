void json(char keys[4][15], char *values[4]){
  foo[0] = '{';
  for(int i = 0; i < 4; i++){
    strcat(foo, "\"");
    strcat(foo, keys[i]);
    strcat(foo, "\"");
    strcat(foo, ":");
    strcat(foo, "\"");
    strcat(foo, *values[i]);
    strcat(foo, "\"");
   
    if(keys[i+1][0] == '\0' || keys[i+1][0] == '\0'){
      break;
    }
    strcat(foo, ",");
  }
    
  strcat(foo, "}");
}

char *int2char(int num){ 
  static char asChar[20]; 
  //static char* ptr = asChar;
  itoa(num, asChar, 10);
  return asChar;
}
int intlen(int num){
  int len;
  while(num > 10){
    num/=10;
    len++;
  }
  return len;
}
