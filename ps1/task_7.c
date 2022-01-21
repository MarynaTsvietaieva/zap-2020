#include <superkarel.h>
void check();
void turn_right();
void turn_up();
void go();

int main(){
turn_on("task_7.kw");
set_step_delay(50);

if(left_is_clear()){
put_beeper();
}

while (front_is_clear()){
step();
if(left_is_clear()){
put_beeper();
}
}
turn_up();
while (front_is_clear()){
step();
}
turn_up();

while(1){
while (left_is_blocked() && front_is_clear()){
 step();
}

if(front_is_blocked() && right_is_blocked() && no_beepers_present()){
turn_off();
return 0;
}

check();

if(front_is_blocked() && right_is_blocked()){
break;
}

}
if(beepers_present()){
pick_beeper();
}

turn_off();
return 0;
}

void check(){
pick_beeper();
turn_left();
step();
put_beeper();
step();

go();

}

void go(){
while (no_beepers_present()){
 while(front_is_clear() && right_is_blocked() && no_beepers_present()){
  step();
} 
 if(right_is_clear() && no_beepers_present()){
  turn_right();
  step();
 }
 if(front_is_blocked() && right_is_blocked() && no_beepers_present()){
  turn_left();
}
}

if(front_is_clear()){
pick_beeper();
step();
}
else{
turn_up();
step();
put_beeper();
turn_up();
step();
pick_beeper();
}

if(left_is_clear()){
turn_left();
step();
}
else {
turn_left();
return;
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
