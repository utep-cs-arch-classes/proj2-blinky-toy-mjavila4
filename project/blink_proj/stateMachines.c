#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char redOn = 0;
static char greenOn = 0;
static char stateCycle = 0;

char redToggle(){
  static char state = 0;
  if(state == 0){
    red_on = 1;
    state = 1;
    redOn = 1;
  }else{
    red_on = 0;
    state = 0;
    redOn = 0;
  }
  return 1;
}

char greenToggle(){
  static char state = 0;
  if(state == 0){
    green_on = 1;
    state = 1;
    greenOn = 1;
  }else{
    green_on = 0;
    state = 0;
    greenOn = 0;
  }
  return 1;
}

void state_advance(){
  static char state = 1;
  static char counter = 1;

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
  
  if(counter++ == 3){
    counter = 0;
    if(stateCycle++ == 3){
      stateCycle = 0;
    }
  }
  
  led_changed = 1;
  led_update();

} 

void dimState(){
  static state = 0;
  switch(stateCycle){
    case 0:
      if(state++ == 3){  
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
        state = 0;
      }else{
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
      }
      break;
    case 1:
      if(state++ == 1){  
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
        state = 0;
      }else{
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
      }
      break;
    case 2:
      if(state++ == 3){  
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
        state = 0;
      }else{
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
      }
      break;
  }
  
  led_changed = 1;
  led_update();

}








