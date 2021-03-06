#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "dimmer.h"
#include "stateMachines.h"

unsigned char dimRed, dimGreen, maxCount, highOut, lowOut;
unsigned char dimPer;

void stateDim(){
  switch(dimPer){
    case 0:
      maxCount = 3;
      highOut = 1;
      lowOut = 0;
      break;
    case 1:
      maxCount = 1;
      highOut = 1;
      lowOut = 0;
      break;
    case 2:
      maxCount = 3;
      highOut = 0;
      lowOut = 1;
      break;
    case 3:
      maxCount = 0;
      highOut = 1;
      lowOut = 1;
      break;
  }
  
  redBlink();
  greenBlink();

  ledChanged = 1;
  ledUpdate();

}

void redBlink(){
  static char state = 0; 
  if(dimRed){
    if(state++ == maxCount){
      redOn = highOut;
      state = 0;
    }else{
      redOn = lowOut;
    }
  }else{
    redOn = 0;
  }
}

void greenBlink(){
  static char state = 0;
  if(dimGreen){
    if(state++ == maxCount){
      greenOn = highOut;
      state = 0;
    }else{
      greenOn = lowOut;
    }
  }else{
    greenOn = 0;
  }
}
