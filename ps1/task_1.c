#include <superkarel.h>
void turn_right();
void jump_over();
void go_back();

int main() {
 turn_on("task_1.kw" );
 set_step_delay(50);

 put_beeper();
 if(front_is_clear()){
 step();
 }
 else{
 turn_left();
 step();
 turn_right();
 if(front_is_clear()){
 step();
 if(right_is_clear()){
  turn_right();
  step();
  turn_left();
  }
 }
 }
 while (no_beepers_present()){
 if (front_is_clear()){
 step();
 }
 else {
   jump_over();
   }
 }
 pick_beeper();
 turn_left();
 turn_left();

 while (no_beepers_present()){
 if (front_is_clear()){
 step();
 }
 else{
 go_back();
 }
 }

 pick_beeper();

 if (facing_south()){
 turn_left();
 }
 if (facing_east()){
 turn_left();
 turn_left();
 }

 turn_off();

 return 0;
 }


 void jump_over(){
 turn_left(); 
 do {
  step();
 } while( right_is_blocked());
 turn_right();
 do {
  step();
  } while(right_is_blocked());
  turn_right();
  do{
  step();
  } while(front_is_clear());
  turn_left();
  }

void go_back(){
 turn_right();
 do {
  step();
 }while (left_is_blocked());
 turn_left();
 do {
 step();
 } while (left_is_blocked());
 turn_left();
  do {
 step();
 } while (front_is_clear());
 turn_right();
 }

void turn_right(){
 set_step_delay(0);
 turn_left();
 turn_left();
 turn_left();
 set_step_delay(50);
 }
