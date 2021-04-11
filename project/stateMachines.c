#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void stateAdvance(){

  redOn = 0;
  greenOn = 1;

  ledChanged = 1;
  ledUpdate();

}
