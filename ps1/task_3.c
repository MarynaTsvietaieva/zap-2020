#include <superkarel.h>

void turn_right();
void go();
void go_back();
void position();

int main(){

turn_on ("task_3.kw");

set_step_delay(50);

while(front_is_clear()){
go();
}

turn_left();
turn_left();

while(front_is_clear()){
if(right_is_blocked() && beepers_in_bag()){
put_beeper();
}
step();
}

turn_left();
step();
turn_left();

while(front_is_clear() || right_is_clear()){
go();

turn_left();
turn_left();

go_back();

if(left_is_clear()){
turn_left();
step();
turn_left();
}

else {
break;
}
}

position();

turn_off();

return 0;
}

void go(){
while (front_is_clear()){
 if(beepers_present()){
  pick_beeper();
 }
 step();
}
if(beepers_present()){
pick_beeper();
}
}

void go_back(){
while(front_is_clear()){
turn_right();
step();
if(beepers_present() && beepers_in_bag()){
 turn_left();
 turn_left();
 step();
 put_beeper();
}
else{
 turn_left();
 turn_left();
 step();
}
turn_right();
step();
}
}

void position(){
turn_left();
turn_left();
 while(no_beepers_present()){
 while(front_is_clear() && no_beepers_present()){
  step();
 }
 if(no_beepers_present()){
 turn_left();
 step();
 turn_left();
 }
 while(front_is_clear() && no_beepers_present()){
 step();
 }
 if(no_beepers_present()){
 turn_right();
 step();
 turn_right();
 }
 }
 
if(facing_west()){
 turn_right();
}
if(facing_east()){
turn_left();
}
 while(front_is_clear()){
  step();
 }
 turn_left();
 while(front_is_clear()){
  step();
 }
 turn_left();
 turn_left();
 }

void turn_right(){
set_step_delay(0);
turn_left();
turn_left();
turn_left();
set_step_delay(50);
}

