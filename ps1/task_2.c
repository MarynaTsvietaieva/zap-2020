#include <superkarel.h>
void go();
void go_back();
void turn_right();

int main (){
turn_on("task_2.kw");
set_step_delay(50);

while(no_beepers_present()){
 go();
 }
 pick_beeper();
 turn_right();
 turn_right();
while(front_is_clear() || right_is_clear() ){
 go_back();
}
turn_off();

return 0;
}

void go(){
 if  (front_is_clear()){
 step();
 }
 else{
 turn_left();
 }
 }

 void go_back(){
  do {
  step();
  } while (front_is_clear());
  if (right_is_clear()){
  turn_right();
  }
  }

  void turn_right(){
  set_step_delay(0);
  turn_left();
  turn_left();
  turn_left();
  set_step_delay(50);
  }
