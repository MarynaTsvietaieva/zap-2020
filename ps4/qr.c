#include <assert.h>
#include <stdio.h>
#include <stdbool.h> 
#include <math.h>
#include <string.h>

void encode_char(const char,bool*);
char decode_byte(const bool*);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main ()
{
bool bits1[8];
encode_char('1', bits1);
for(int i = 0; i < 8; i++){
    printf("%d", bits1[i]);
    }
printf("\n");

bool bits2[8] = {0,1,1,1,1,0,0,1};
printf("%c\n", decode_byte(bits2));

char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len+1][8];
encode_string(text, bytes1);
for(int j = 0; j <= len; j++){
printf("%c: ", text[j]);
for(int i = 0; i < 8; i++){
  printf("%d", bytes1[j][i]);
        }
printf("\n");
}
bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_bytes(7, bytes2, string);
printf("%s\n", string);

int length = 7+1, cols = 2, offset = 4;
bool bytes3[7+1][8] = {
        {0, 1, 1, 1, 0, 0, 1, 0},
	{0, 1, 1, 0, 0, 1, 0, 1},
	{0, 1, 1, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 0, 1},
	{0, 1, 1, 1, 1, 0, 1, 0},
	{0, 1, 1, 0, 0, 1, 0, 1},
	{0, 1, 1, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0}
    };
bool blocks1[offset*8][cols];
bytes_to_blocks(cols, offset, blocks1, length, bytes3);
for(int j = 0; j < offset*8; j++){
    for(int i = 0; i < cols; i++){
        printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
    }
    printf("\n");
    if(j % 8 == 7){
        printf("\n");
    }
}
bool blocks2[2*8][3] = {
    {0,0,0},
    {1,1,1},
    {0,1,1},
    {0,0,0},
    {0,1,1},
    {0,0,1},
    {0,0,1},
    {1,0,1},
    {0,0,0},
    {1,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0}
};
bool bytes4[length][8];
blocks_to_bytes(3, 2, blocks2, length, bytes4);
for(int j = 0; j < length; j++){
    for(int i = 0; i < 8; i++){
        printf("%d", bytes2[j][i]);
    }
    printf("\n");
}
}

void encode_char(const char  character,bool bits[8]){
int i=7, c = character;

bits[8]='\0';

while(c !=1){
bits[i] = ((c%2 == 0) ? false : true);
i--;
c = c/2;
}
bits[i] = true;
i--;
for(int p=i; p>-1; p--){
 bits[p]=false;
  }
}

char decode_byte(const bool bits[8]){
int k=0, d=0, number;

for(int i=0; i<8; i++){
d = ((bits[i]==true) ? 1 : 0);
if(d==1){
 break;
}
number = i;
}

int pos=7-number;

for(int i= number; i<8; i++){
d = ((bits[i]==true) ? 1 : 0);
if(d==1){
k= k + (d*pow(2,pos));
}
pos--;
}

return k;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
char strin[strlen(string)+1];
for(int i =0; i<strlen(string)+1; i++){
strin[i]=string[i];
}
strin[strlen(string)+1] = '\0';

for(int s=0; s< strlen(string)+1; s++){
int c = strin[s], i=7;
bytes[s][8]='\0';
if(s == strlen(string)){
 for(int w=0; w< 8; w++){
  bytes[s][w]=false;
}
}
else{
while(c !=1){
bytes[s][i] = ((c%2 == 0) ? false : true);
i--;
c = c/2;
}
bytes[s][i] = true;
i--;
for(int p=i; p>-1; p--){
 bytes[s][p]=false;
  }
 }
}
 bytes[strlen(string)+1][8] = '\0';
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){

char bits[8];
for(int i=0; i<rows; i++){
 for(int p=0;p<8; p++){
 bits[p] = bytes[i][p];
 }
 bits[8]='\0';

int k=0, d=0, number;

for(int i=0; i<8; i++){
d = ((bits[i]==true) ? 1 : 0);
if(d==1){
 break;
}
number = i;
}

int pos=7-number;

for(int i= number; i<8; i++){
d = ((bits[i]==true) ? 1 : 0);
if(d==1){
k= k + (d*pow(2,pos));
}
pos--;
}
string[i]=k;
}
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
int d=0;

for(int i=rows; i < offset*cols; i++){
  for(int idx=0; idx<8; idx++){
    bytes[i][idx]=false;
  }
 }
for(int i=0; i<offset; i++ ){
  for(int p=0; p<cols; p++){
   int k=0;
   for(int idx = 0+i*8; idx < i*8+8; idx++){
      blocks[idx][p] = bytes[d][k];
      k++;
   }
   d++;
  }
}

blocks[offset*8][cols]='\0';
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
int d=0;
for(int i=0; i<offset; i++ ){
  for(int p=0; p<cols; p++){
   int k=0;
   for(int idx = 0+i*8; idx < i*8+8; idx++){
      bytes[d][k]=blocks[idx][p];
      k++;
   }
   d++;
   if(d==rows){
    break;
  } 
 }
 if(d==rows){
 break;
}
}

}
