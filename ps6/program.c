#define _POSIX_C_SOURCE 200201L
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <sys/stat.h>

void first_draw(int, char*,char*);
void draw(int, char*);
int win(char*, char*, int);
void cleaning (int);

int main(){
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5,  COLOR_RED,     COLOR_BLACK);
    init_pair(6,  COLOR_BLUE,    COLOR_BLACK);
    init_pair(7,  COLOR_WHITE,   COLOR_BLACK);

    struct timespec tv = {
      .tv_sec = 1
    }; 
    
    char text[18][30] = {{"ddaayy"},{"ffoorr"},{"rreellaaxx"},{"ssmmbb"},{"lloovvee"}, {"yyoouu"}, {"hhaavvee"},{"nniiccee"}, {"ddaayy"}, {"pprraaccttiiccee"}, {"mmaakkeess"}, {"ppeerrffeecctt"}, {"ttaakkee"}, {"hhiigghh"}, {"rrooaadd"}, {"wwiisshh"}, {"yyoouu"}, {"lluucckk"}};
    int number  = (rand()%6) * 3;

    for(int level = 1; level < 4; level++){

      char string[20] = {'\0'};
      int ind;
      for(ind = 0; text[number + level - 1][ind] != '\0'; ind++){
          string[ind] = text[number + level - 1 ][ind];
      }
      char new_string[100] = {'\0'};
      mvprintw(LINES/4 - 5, COLS/4 - 5, "Level %d", level);
      first_draw(ind,string,new_string);  
      int i;
      for(i = 5; i >= 0; i--){
         mvprintw(LINES/4, COLS/4, "You have %d second to remember the position of the letters ", i);
         refresh();
         nanosleep(&tv, NULL);
      }
      char new_new_string[100];
      for(int i = 0; i < 100; i++){
           new_new_string[i] = ' ';
           new_new_string[i+1] = '\0';
       }
      draw(ind, new_new_string);

      for(int i = 4; i > 0; i--){
          mvprintw(LINES/4, COLS/4, "You have %d guesses left                                           ", i);
          refresh();
          nanosleep(&tv, NULL);
          mvprintw(LINES/4, COLS/4, "Enter the positions of the simila letters             "); 
          refresh();
          nodelay(stdscr, FALSE);
          int a1 = getch();
          switch (a1) {
                case 'L':{
                   mvprintw(LINES/4, COLS/4 , "Live the game                                        ");
                   refresh();
                   getchar();
                   endwin();
                   return EXIT_SUCCESS;
                   break;
                  }
           }
         a1 = a1 - 48;
         int a2 = getch();
         a2 = a2 - 48;
         int a3 = getch();
         a3 = a3 - 48;
         int a4 = getch();
         a4 = a4 - 48;

         nodelay(stdscr, TRUE); 
         int number1 = ind/2-a1 + (ind/2)*(a2-1);
         int number2 = ind/2-a3 + (ind/2)*(a4-1);

         if(new_string[number1] == new_new_string[number1] || new_string[number2] == new_new_string[number2] || number1 == number2){
               mvprintw(LINES/4, COLS/4, "already wrote such numbers                                                       ");
               i++;
         }
        else if(a1 > ind/2 || a1 < 1 || a2 > 2 || a2 < 1 || a3 > ind/2 || a3 < 1 || a4 >2 || a4 < 1){
             mvprintw(LINES/4, COLS/4, "wrong numbers                                     ");
             i++;
        }
 
       else{
           new_new_string[number1] = new_string[number1];
           new_new_string[number2] = new_string[number2];

           draw(ind, new_new_string);
           refresh();
           tv.tv_sec = 1;
           nanosleep(&tv, NULL);

           if(new_string[number1] != new_string[number2]){
             new_new_string[number1] = ' ';
             new_new_string[number2] = ' ';
           }
           else{
              i++; 
            }

          draw(ind, new_new_string);
          refresh();
          }

         refresh(); 
         nanosleep(&tv, NULL);

         int winer = win(new_string, new_new_string, ind);

         if(winer == 1){
            mvprintw(LINES/4, COLS/4, "Congratulations, you win !                                           ");
            move(LINES/4 + 4 + level, COLS/4);
            for(int index = 0; index < ind; index++){
              if(index%2 == 0){
                attron(COLOR_PAIR(1));
                printw("%c", text[number+level-1][index]);
                attroff(COLOR_PAIR(1));
                }
            }
            break;
         }
    }

     int winer2 = win(new_string, new_new_string, ind);
     if(winer2 == 0 && i == -1){
           mvprintw(LINES/4, COLS/4, "Sorry, but you lost...                                           ");
           refresh();
           break;
     }
     cleaning(ind);
     refresh();
     nanosleep(&tv, NULL);
   }
   refresh();
   nanosleep(&tv, NULL);
   getchar();
   endwin();
    
}


void first_draw(int ind, char* string, char* new_string){
 struct timespec ts = {  
   .tv_sec = 0,
    .tv_nsec = 0.2 * 1000000000L  
    };     
   int l = ind; 
   int plus = 0;
   int pluss = 0;
   int number_c = 1;

   for(int x = COLS/2 - 5; x < COLS/2 - 3; x++){
       int number_l = l/2;
       for(int i = LINES/2 - l/2;i < LINES/2; i++){
          int index = rand()%ind;
          new_string[l/2-number_l + (l/2)*(number_c-1)] = string[index];
          move(i+pluss, x+plus);
          printw(" ---");
          move(i+pluss+1, x+plus);
          if(x == COLS/2 - 5){
            move(i+1+pluss, x+plus-1);
            printw("%d", number_l);
          }
         number_l--;
         printw ("| %c |",string[index]);
         move(i+pluss+2, x+plus);
         pluss = pluss+1;
         printw(" ---");
         if(i == LINES/2-1){
           move(i+pluss+2, x+plus);
           printw("  %d", number_c);
           number_c++;
         }
         refresh();
         nanosleep(&ts, NULL);
         for(int position = index; position < ind; position++){
          string[position] = string[position + 1];
          string[position + 1] = '\0';
         }
       ind--;
      }
   pluss = 0;
   plus = plus+3;
  }  
}

void draw(int ind, char* new_new_string){
  int l = ind; 
  int plus = 0;
  int pluss = 0;
  int number_c = 1;

 for(int x = COLS/2 - 5; x < COLS/2 - 3; x++){
       int number_l = l/2;
       for(int i = LINES/2 - l/2;i < LINES/2; i++){
          move(i+pluss, x+plus);
          printw(" ---");
          move(i+pluss+1, x+plus);
          if(x == COLS/2 - 5){
             move(i+1+pluss, x+plus-1);
             printw("%d", number_l);
          }
          number_l--;
          int color = 1; //rand()%7 + 1;
          int new_number = l - ind;
          for(int number = 0; number < ind+1; number ++){
             if(new_new_string[number] == new_new_string[new_number] && number != new_number){
                 color = (number > new_number) ? new_number + 2 : number + 2;
             }
          }     
          printw("|");
          attron(COLOR_PAIR(color));
          printw (" %c ", new_new_string[new_number]);
          attroff(COLOR_PAIR(color));
          printw("|");
          move(i+pluss+2, x+plus);
          pluss = pluss+1;
          printw(" ---");
          if(i == LINES/2-1){
              move(i+pluss+2, x+plus);
              printw("  %d", number_c);
              number_c++;
              refresh();
          }
          ind--;
        }
    pluss = 0;
    plus = plus+3;
  }  
}

void cleaning(int l){
   for(int x = COLS/2 - 10; x < COLS/2 ; x++){
       for(int i = LINES/2 - l/2;i < LINES/2 + 20; i++){
            mvprintw(i,x,"        ");
    }
   }       
}


int win(char* new_string, char* new_new_string, int ind){
  int i;
  for(i = 0; i < ind - 1; i++){
    if(new_string[i] != new_new_string[i]){
      break;
    }
   }
  if(i == ind - 1){
    return 1;
  }
 return 0;
} 

