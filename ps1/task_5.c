#include <superkarel.h>
void make_r();
void position();
void turn_right();
void centre();
void recursia();
void turn_up();

int main(){

turn_on("task_5.kw");
set_step_delay(50);

position();
while(front_is_clear()){
step();
}
turn_left();

while (front_is_clear()){
step();
}
turn_left();

make_r();

turn_left();
step();
turn_right();
step();

centre();
position();
turn_right();
centre();

position();

turn_off();

return 0 ;
}

void make_r(){
while (no_beepers_present()){
do{
put_beeper();
step();
}while (front_is_clear());
 turn_left();
}
}

void position(){
set_step_delay(0);
if (facing_south()){
turn_up();
}
if( facing_west()){
turn_right();
}
if (facing_east()){
turn_left();
}
set_step_delay(50);
}

void turn_right(){
 turn_left();
 set_step_delay(0);
 turn_left();
 set_step_delay(50);
 turn_left();
}

void centre(){
step();
 while(no_beepers_present()){
 put_beeper();
 step();
 }
turn_up();
step();
if(beepers_present()){
pick_beeper();
step();
}
else {
return;
}
recursia();
}

void recursia(){
while(beepers_present()){
step();
}
turn_up();
step();
pick_beeper();
step();
if(beepers_present()){
recursia();
}
turn_up();
step();
}

void turn_up(){
set_step_delay(0);
turn_left();
turn_left();
set_step_delay(50);
}
