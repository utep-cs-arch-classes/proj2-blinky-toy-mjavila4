#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "dimmer.h"
#include "stateMachines.h"

unsigned char dimRed, dimGreen;

void stateDim(){

  redBlink();
  greenBlink();

  ledChanged = 1;
  ledUpdate();

}

void redBlink(){
  static char state = 0;
  if(dimRed){
    if(state++ == 3){
      redOn = 1;
      state = 0;
    }else{
      redOn = 0;
    }
  }else{
    redOn = 0;
  }
}

void greenBlink(){
  static char state = 0;
  if(dimGreen){
    if(state++ == 3){
      greenOn = 1;
      state = 0;
    }else{
      greenOn = 0;
    }
  }else{
    greenOn = 0;
  }
}













