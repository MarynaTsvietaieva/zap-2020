#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* second[]){
 FILE *is = fopen(second[1], "r");
 FILE *to = fopen(second[2], "w");


char string1[] = {"START"};
char string2[] = {"STOP"};
char ch = fgetc(is);
int d = 0;
while(ch != EOF){
  if(ch == 'S'){
  char s[5] = {'S','\0', '\0', '\0', '\0'};
    int k;
    for(k=1; k < 5; k++){
      ch = fgetc(is);
      s[k] = ch;
      if(string1[k] != s[k]){
      k++;
      break;
      }
    }
    if(string1[k-1] == s[k-1]){
    ch = fgetc(is);
    while(ch != EOF){
    char s2[16], s1[16];
    int index = 0;
    
    for(int i = 0; i < 16; i++){
      s1[i] = '\0';
       s2[i] = '\0';
      }

   for(int k=0; k < 16; k++ ) {
      char ch = fgetc(is);
      s1[k] = ch;
      if(k < 4){
         if(s1[k] == string2[k]){
         index++;
        }
      }
     if(s1[k] == ' '){
       break;
      }
     }
      if(index == 4){
       break;
      }
      index = 0;
      for(int i=0; i < 16; i++ ) {
        ch = fgetc(is);
        s2[i] = ch;
      if(i < 4){
        if(s2[i] == string2[i]){
         index++;
        }
      }
      if(s2[i] == ' '){
       break;
      }
     }
      if(index == 4){
       break;
      }
if(d !=0){
  fputc(' ',to);
}    
   for(int i=0; s2[i] != ' '; i++ ) {
   fputc(s2[i],to);
   }
d++;
 }
}
}
ch = fgetc(is);
}
fclose(is);
fclose(to);
return 0;
}

