#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hangman.h"



int get_word(char secret[]){
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        long int random = (rand() % size) + 1;
        fseek(fp, random, SEEK_SET);
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
size_t s = strlen(letters_guessed);
size_t l = strlen(secret);

char result[s];

 for (int i=0; i < l; i++){
  for(int j=0; j < s+1; j++){
   if(secret[i] == letters_guessed[j]){
    result[i] = secret[i];
  }
}
}

for(int i=0; i < l; i++){
 if(secret[i] != result[i]){
  return 0;
  }
}
return 1;
}


void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){

size_t s = strlen(secret);
size_t l = strlen(letters_guessed);
guessed_word[s]= 0;

for (int j=0; j <l; j++){
 for(int i=0; i <s; i++){
  if(secret[i] == letters_guessed[j]){
    guessed_word[i] = secret[i];

  }
}
}

for(int idx=0; idx<s; idx++){
 if(guessed_word[idx]!=secret[idx]) {
  guessed_word[idx]='_';
 }
 }

printf("%s", guessed_word);
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
char pipi[] = {"abcdefghijklmnopqrstuvwxyz"};
available_letters[26] = '\0'; 
for(int i=0; i< 26; i++){
 available_letters[i]=pipi[i];
 }

size_t s = strlen(available_letters);
size_t l = strlen(letters_guessed);

if(l !=0){
 for ( int i=0; i < s; i++){
  for(int j=0; j < l; j++){
   if(letters_guessed[j] == available_letters[i]){
    for(int p = i; p < s;p++ ){
    available_letters[p]=available_letters[p+1];
    }
    s--;
    }
 }
}
}
}

void hangman(const char secret[]){
size_t l = strlen(secret);
char available_letters[27];
printf("Welcome to the game, Hangman!\nI am thinking of a word that is %ld letters long.\n", l);
char letters_guessed[26]= {' '};
int b = 0;
char alf[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char al[]={"abcdefghijklmnopqrstuvwxyz"};

int idx=8;
while(!is_word_guessed(secret,letters_guessed) && idx!=0){
printf("-------------\n");
printf("You have %d guesses left.\n", idx);

get_available_letters(letters_guessed, available_letters);
printf("Available letters: %s\n" , available_letters);

printf("Please guess a letter: ");
char c[l];
scanf("%s", c);
size_t p = strlen(c);

if(p>1){
int k = 0;
for(int i=0; i<l; i++){
 if(secret[i] != c[i]){
  printf("\nSorry, bad guess. The word was %s.\n", secret);
  k=1;
  break;
 }
 }
 if(k==0){
 printf("\nCongratulations, you won!\n");
 break;
}
break;
}

char f = c[0];
int super=0;
for(int i=0; i<26; i++){
if(al[i]== f){
 super=0;
}
}


for(int i=0; i<26; i++){
 if(alf[i]== f){
 super=1;
}
}

for(int i=0; i<26; i++){
 if(al[i] != f){
 super=3;
 if(alf[i] == f){
  super=1;
  break;
 }
}
 if(al[i] == f){
 super=0;
  break;
}
}


if(super==1){
 for(int i=0; i<26; i++){
  if(f == alf[i]){
  alf[i]=al[i];
  f=al[i];
  }
 }
}

if(super==3){
 char x[26];
 printf("Oops! '%c' is not a valid letter: ", f);
 get_guessed_word(secret,letters_guessed, x);
 idx++;
}

int o=0; 

if(super==1 || super==0){
int p = strlen(letters_guessed);
for(int i=0; i<p; i++){
 if(letters_guessed[i]==f){
   char x[26];
   printf("Oops! You'ev already guessed that letter: ");
   get_guessed_word(secret,letters_guessed, x);
   idx++;
   o=1;
  }
}
}

if(o==0 && super !=3){
letters_guessed[b] = f;
size_t size = strlen(letters_guessed);
for(int i=0; i<size-1; i++){
 for(int k=0; k<size-i-1; k++){
  if(letters_guessed[k]> letters_guessed[k+1]){
   int d=letters_guessed[k];
   letters_guessed[k]=letters_guessed[k+1];
   letters_guessed[k+1]=d;
   }
  }
 }

int cap;
for(int p=0; p<l;p++){
 if(secret[p] == f){
 cap=1;
 break;
 }
 cap=0;;
}

char x[26];
if(cap==0){
 printf("Oops! That letter is not in my word: ");
 get_guessed_word(secret,letters_guessed, x);
  }
 if(cap==1){
  printf("Good guess:");
  get_guessed_word(secret,letters_guessed, x);
  idx++;
  }
  b++;
}
idx--;
printf("\n");

}

int konec=is_word_guessed(secret,letters_guessed);
if(konec==1){
 printf("Congratulations, you won!\n");
}
else{
 printf("Sorry, you ran of guesses. The word was %s\n.",secret);
}
}

