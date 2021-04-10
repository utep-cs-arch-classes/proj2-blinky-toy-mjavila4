#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

void main(void){

  configureClocks();
  ledInit();
  switchInit();

  enableWDTInterrupts();

  or_sr(0x18);

}
