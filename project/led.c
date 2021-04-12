#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

unsigned char redOn = 0, greenOn = 0;
unsigned char ledChanged = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void ledInit(){

  P1DIR |= LEDS;
  switchStateChanged = 1;
  ledUpdate();

}

void ledUpdate(){

  if(switchStateChanged || ledChanged){
    
    char ledFlags = redVal[redOn] | greenVal[greenOn];

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;

  }

  switchStateChanged = 0;
  ledChanged = 0;

}
