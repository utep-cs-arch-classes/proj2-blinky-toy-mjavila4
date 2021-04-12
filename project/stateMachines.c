#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "dimmer.h"

void redToggle(){

  static char state = 0;

  if(state == 0){
    dimRed = 1;
    state = 1;
  }else{
    dimRed = 0;
    state = 0;
  }

}

void greenToggle(){

  static char state = 0;

  if(state == 0){
    dimGreen = 1;
    state = 1;
  }else{
    dimGreen = 0;
    state = 0;
  }

}

void stateAdvance(){

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
  
}
