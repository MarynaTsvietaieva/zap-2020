#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hangman.h"

int main(){
char sec[15];
get_word(sec);
hangman(sec);
}
