#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char dimState = 0;

char redToggle(){
  static char state = 0;
  if(state == 0){
    red_on = 1;
    state = 1;
  }else{
    red_on = 0;
    state = 0;
  }
  return 1;
}

char greenToggle(){
  static char state = 0;
  if(state == 0){
    green_on = 1;
    state = 1;
  }else{
    green_on = 0;
    state = 0;
  }
  return 1;
}

void state_advance(){

  static char state = 1;

  redToggle();
  
  switch(state){
    case 0:
      greenToggle();
      state = 1;
      break;
    case 1:
      state = 0;
      break;
  }

  led_changed = 1;
  led_update();

} 

void dimming(){

  static char state = 0;
  
  if(dimState){

    green_on = 0; 
    
    if(state++ == 1){

      green_on = 1;
      state = 0;

    }

    led_changed = 1;
    led_update();
    
  }

}






