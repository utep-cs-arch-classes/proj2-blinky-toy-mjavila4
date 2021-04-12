## Lab 2 Coded by Mark Avila

## Description

In this lab, we are tasked with working with time and button interrupts to manage a state machine within the controller. For my specific project, the leds follow a timed state machine that counts up to 3 in binary. At any given time, a switch may be pressed to increment the led brightness percentage. These buttons are located on the second layer of the board in which they utilize port 2. Switch 1 sets both leds to 25% brightness. switch 2 sets at 50%, switch 3 75%, and switch 4 to 100% brightness. Every dimming state is accompanied by a sound lower than the next state, but higher then the previous. For example, switch 3 sets the noise at a higher frequency than switch 2. All three aspects come together to create one working toy.

## Running Blinky-Buzzy Toy

Inside the source code is a Makefile in which all .c files are complied and respective .o files created. Running "make" will do this and create an elf. file in which we can then load the file into the MSP430. We do this by running "make load" after. Once the file has successfully loaded, the program begins running inside the MSP430.

## Using the Toy

While there are a total of 6 buttons within the controller, the current code only deals with 4 for now. These buttons are located on the bottom of the screen and are labeled from left to right; switch 1, switch 2, switch 3 and switch 4. The user will see that the leds are already counting in binary, this is a looping state machine that cannot be interrupted. However, state transitons occur as dimming changes, taking output from the port 2 switches. Switch 1 dims the leds to 25%, every switch after increments by 25% as well. Audio played from the speakers will represent the current dim state, 25% brightness emits a low pitched tone while 100% is higher.
