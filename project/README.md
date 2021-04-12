## Lab 2 Coded by Mark Avila

## Description

In this lab, we are tasked with working with time and button interrupts to manage a state machine within the controller. For my specific project, the leds follow a timed state machine that counts up to 3 in binary. At any given time, a switch may be pressed to increment the led brightness percentage. These buttons are located on the second layer of the board in which they utilize port 2. Switch 1 sets both leds to 25% brightness. switch 2 sets at 50%, switch 3 75%, and switch 4 to 100% brightness. Every dimming state is accompanied by a sound lower than the next state, but higher then the previous. For example, switch 3 sets the noise at a higher frequency than switch 2. All three aspects come together to create one working toy.
