#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

void ledInit(){

  P1DIR |= LEDS;
  switchStateChanged = 1;
  ledUpdate();

}

void ledUpdate(){

  if(switchStateChanged){

    char ledFlags = 0;
    
    ledFlags |= switchStateDown ? LED_GREEN : 0;
    ledFlags |= switchStateDown ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;

  }

  switchStateChanged = 0;

}
