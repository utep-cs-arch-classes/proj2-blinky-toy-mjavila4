#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char toggleRedState = 0;

char toggleRed(){

  switch(toggleRedState) {
  case 0:
    red_on = 1;
    toggleRedState = 1;
    break;
  case 1:
    red_on = 0;
    toggleRedState = 0;
    break;
  }
  return 1;
}

char toggleGreen(){

  static char state = 1;

  switch(state){
  case 0:
    green_on = 1;
    state = 0;
    break;
  case 1:
    green_on = 1;
    state = 0;
    break;
  }
  return 1;
}


void state_advance(){

  static char state = 0;

  switch(state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }

  led_changed = 1;
  led_update();
  
} 








