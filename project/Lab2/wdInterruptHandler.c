#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vecTime(WDT_VECTOR) WDT(){	// 250 interrupts/sec //
  static char blink_count = 0;
  static char dim_count = 0;
  
  if(++blink_count == 125){
    state_advance();
    blink_count = 0;
  }
  
  if(++dim_count == 1){
    dimState();
    dim_count = 0;
  }
  
}
<<<<<<< HEAD

/*void
__interrupt_vecSwitch(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      // did a button cause this interrupt? //
    P1IFG &= ~SWITCHES;		      // clear pending sw interrupts //
    switch_interrupt_handler();	      // single handler for all switches //
  }
}*/
=======
>>>>>>> 053cdd49ab71269030235291c97b4bb045edc099
