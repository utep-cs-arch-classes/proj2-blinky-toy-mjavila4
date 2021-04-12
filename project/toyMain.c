#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "dimmer.h"

void main(void){

  configureClocks();
  switchInit();
  ledInit();
  
  enableWDTInterrupts();

  or_sr(0x18);

}
