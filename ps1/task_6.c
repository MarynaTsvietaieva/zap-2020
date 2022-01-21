#include <superkarel.h>
void number();
void position();
void turn_right();
void turn_up();
void position();

int main(){
turn_on("task_6.kw");
set_step_delay(50);

number();

turn_off();
return 0;
}


void number(){
while (front_is_clear() && no_beepers_present()){
 step(); 
if(beepers_present()){
 pick_beeper();
 if (facing_south()){
 turn_up();
 }
 if (facing_east()){
 turn_left();
 }
 if (facing_west()){
 turn_right();
 }
}
if( beepers_present()){
 pick_beeper();
 turn_left();
}
if(beepers_present()){
 pick_beeper();
 turn_left();
}
if (beepers_present()){
 pick_beeper();
 turn_left();
}
if(beepers_present()){
pick_beeper();
return;
}
}
}

void turn_right(){
set_step_delay(0);
turn_left();
turn_left();
turn_left();
set_step_delay(50);
}

void turn_up(){
set_step_delay(0);
turn_left();
turn_left();
set_step_delay(50);
}
