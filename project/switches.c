#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch1StateDown, switch2StateDown, switch3StateDown, switch4StateDown;
char switchStateChanged;

static char switchUpdateInterruptSense(){

  char p2Val = P2IN;
  P2IES |= (p2Val & SWITCHES);
  P2IES &= (p2Val | ~SWITCHES);
  return p2Val;

}

void switchInit(){

  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  switchUpdateInterruptSense();
  ledUpdate();

}

void switchInterruptHandler(){

  char p2Val = switchUpdateInterruptSense();
  switch1StateDown = (p2Val & SW1) ? 0 : 1;
  switch2StateDown = (p2Val & SW2) ? 0 : 1;
  switch3StateDown = (p2Val & SW3) ? 0 : 1;
  switch4StateDown = (p2Val & SW4) ? 0 : 1;
  switchStateChanged = 1;
  //ledUpdate();
  
}
