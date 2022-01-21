#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* bananas[]){
 FILE *fp = fopen(bananas[1], "r");

  char string1[] = {"ANANAS"};
  char string2[] = {"ananas"};
  int i;
  int sum = 0;
  char ch = fgetc(fp);
if ( argc == 2 ) {
while(ch != EOF){
  if(ch == 'a' || ch == 'A'){
    for(i=1; i<7; i++){
     char ch = fgetc(fp);
      if(i == 6){
       sum++;
       break;
      }
    if((ch == 'a' || ch =='A') && i==1){
      i--;
     }
      if(ch != string1[i] && ch != string2[i]){
        break;
      }
     }
   }
ch = fgetc(fp);
}
}
fclose(fp);

FILE *fps = fopen(bananas[1], "w");
if(sum > 9){
 int sum1 = 49;
 fputc(sum1, fps);
 sum = sum - 10;
}
int sum2 = sum + 48;
fputc(sum2, fps);
fclose(fps);
return 0;
}
