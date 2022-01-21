#include <superkarel.h>
void turn_right();
void looking_for();
void repear();

int main(){

turn_on("task_4.kw");
set_step_delay(100);

turn_left();

while (right_is_clear() || front_is_clear()){
while (no_beepers_present()){
looking_for();
}
if(front_is_blocked() && right_is_blocked()){
if(beepers_present()){
pick_beeper();
}
break;
}

while(front_is_clear()){
step();
}

if (front_is_blocked()){
turn_right();
turn_right();
}

do{
repear();
} while (front_is_clear());

if (no_beepers_present()){
put_beeper();
}

turn_left();

if (front_is_clear()){
step();
turn_left();
}
if(front_is_blocked() && right_is_blocked()){
turn_off();
return 0;
}
}
turn_off();

return 0;

}

void turn_right(){
turn_left();
set_step_delay(0);
turn_left();
turn_left();
set_step_delay(100);
}

void looking_for(){
  do {
  step();
   } while (front_is_clear() && no_beepers_present());

   if(front_is_blocked() && right_is_clear() && no_beepers_present()){
    turn_right();
     step();
    turn_right();
    }
   if(front_is_blocked() && right_is_blocked() && no_beepers_present()){
    turn_left();
    turn_left();
    }
  while (front_is_clear() && no_beepers_present()){
  step();
  }
  if (front_is_blocked() && left_is_blocked()){
  turn_left();
  put_beeper();
  return;
  }
  if (front_is_blocked() && no_beepers_present() && left_is_clear()){
    turn_left();
    step();
    turn_left();
   }
   }
   
   
void repear(){
 if (no_beepers_present()){
 put_beeper();
 }
 if(beepers_present()){
  step();
  }
}
