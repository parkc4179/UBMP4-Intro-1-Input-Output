/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.

int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        // If SW2 is pressed, make a flashy light pattern
        if(SW2 == 0)
         /*{
            LED3 = 1;
            LED6 = 1;
            __delay_ms(200);
            LED4 = 1;
            LED5 = 1;
            __delay_ms(100);
            LED4 = 0;
            LED5 = 0;
            __delay_ms(200);
            LED4 = 1;
            LED5 = 1;
            __delay_ms(100);
            LED3 = 0;
            LED6 = 0;
            __delay_ms(100);
            LED4 = 0;
            LED5 = 0;

        }*/

        
        // Add code for your Program Analysis and Programming Activities here:

        if (SW3 ==0)
       {
           LATC=0b11110000;
           __delay_ms(50);
           LATC=0;
           __delay_ms(50);
       }
      { 
        if(SW2 == 0) //Note G1
        {
            BEEPER = 1;
            __delay_us(1420);
            BEEPER = 0;
            __delay_us(1420);
        }
        else
        if(SW3 == 0) //Note C0
        {
            BEEPER = 1;
            __delay_us(474);
            BEEPER = 0;
            __delay_us(474);
        }
        else
        if(SW4 == 0) //Note D4
        {
            BEEPER = 1;
            __delay_us(8512);
            BEEPER = 0;
            __delay_us(8512);
        }
        else
        if(SW5 == 0) //Note E0
        {
            BEEPER = 1;
            __delay_us(597);
            BEEPER = 0;
            __delay_us(597);
        }
      }   

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

/* Program Analysis
*
* 1. How many times do the LEDs flash if SW2 is quickly pressed and released?
*    Do the LEDs keep flashing when SW2 is held? Look at the program and
*    explain why this happens when SW2 is held.
* The LEDs flash only one time if SW2 is pressed only one time, but the LEDS keep flashing when SW2 is keep heldng. It is because the program built that when SW2 is pressed, all LEDS flashes and off for a delayed sec, so as the buttons is pressing this program is repeating.
* 2. Explain the difference between the statements: LED3 = 0; and LED3 = 1;
* The difference between the statement LED3 = 0; and LED3 = 1; is that LED3 = 0 is the statement when LED is turned off because there are no differences of charge, and LED3 = 1 is the statement that LED is on.
* 3. What voltage do you expect the microcontroller to output to LED D3 when
*    the statement LED3 = 0; runs? What voltage do you expect the output to be
*    when the statement LED3 = 1; runs?
* The voltage will be 0 when LED equals to 0, and the voltage will be 5 when the LED equals to 1.
*    You can confirm the output voltage with a voltmeter if you have access
*    to one. If you tried that, did the voltage match your prediction?
* As I checked the voltage through the voltmeter, my prediction was right. Each statements measured close to 0 and 5 when it was measured on the circuit.
* 4. The statement 'if(SW2 == 0)' uses two equal signs, while the statement
*    'LED3 = 1;' uses a single equal sign. What operation is performed by one
*    equal sign? What operation is performed by two equal signs?
* The two equal signs represents for the conditional check so this tells they equals each other, and one equal sign is an assignment operator that we assign code to another.
* 5. The following program code includes instructions that write to the PORTC
*    output latches directly. Try it by copying and pasting this code below
*    the existing SW2 'if' structure, at the location shown by the comment.
 
       if(SW3 == 0)
       {
           LATC = 0b00000000;
           __delay_ms(100);
           LATC = 0b11110000;
           __delay_ms(100);
       }
 
*    What happens when pushbutton SW3 is pressed? Identify at least one
*    advantage and one disadvantage of controlling the LEDs using 'LATC' writes
*    rather than through individual 'LEDn = x;' statements.
When SW3 is pressed, all the LEDs quickly flashs. As using LATc it is easier and more fast to code program,but this can not control detailed. This can not control the delay between LEDs, and the speed of each LEDs.
* 6. Next, compare the operation of 'if' and 'while' structures to simulate
*    momentary buttons. Replace the code you added in 5, above, with this code:
 
       // Momentary button using if structure
       if(SW3 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
       // Momentary button using while structure
       while(SW4 == 0)
       {
           LED5 = 1;
       }
       LED5 = 0;
 
*    First, try pressing and releasing SW3 and SW4 one at a time.
* Both LEDs flashs and off at the same time
*    Next, press and hold SW3 while pressing and releasing SW4. Does it work
*    as expected?
* It works as expected, while the sw3 is pressing LED 5 is flahsing quick. 
*    Next, try press and holding SW4 while pressing and releasing SW3. Does it
*    work as expected? Explain the difference in operation between the 'if' and
*    'while' structures making up the momentary button code.
* While the sw4 is keep presssing, the LED 4 is not flashing. The switch that used the 'if' statement was able to control the other LED at the same time but the statement used'while' is not able to control another.
* 7. Let's explore logical conditions using 'if' statements. Replace the code
*    added in 6, above, with this nested if code to make a logical AND
*    condition that will light LED D4 only if both SW3 and SW4 are pressed:
 
       // Nested if 'AND' code
       if(SW3 == 0)
       {
           if(SW4 == 0)
           {
               LED4 = 1;
           }
           else
           {
               LED4 = 0;
           }
       }
       else
       {
           LED4 = 0;
       }
 
*    Test the code to ensure it works as expected. Does the order of the if
*    conditions matter? (eg. swap the conditional checks for SW3 and SW4)
* The order does not matter, only light flash when the both bottons are pressed.
* 8. Next, replace the code from 7 with the following code which implements a
*    logical AND conditional operator composed of two ampersands '&&':
       // Conditional 'AND' code
       if(SW3 == 0 && SW4 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
*    Does '&&' work the same way as the nested if structures? Can you think of
*    at least one advantage of using a logical conditional operator instead of
*    nested if structures?
* It does work the same way as the nested if structures. The logical conditional operator code is much simpler than the nested if structures. It is easier to code.
* 9. Replace the double ampersand '&&' with double vertical bars '||)' to make
*    a logical OR conditional operator. Your code should look like this:
        // Conditional 'OR' code
       if(SW3 == 0 || SW4 == 0)
       {
           LED4 = 1;
       }
       else
       {
           LED4 = 0;
       }
 
*    Describe the conditions under which LED4 turns on.
* The LED4 turns on when the button SW3 is pressed. It does not have to be pressed together with the button SW4.
* The LED4 turns on when the button SW4 is pressed. It does not have to be pressed together with the button SW3.


 * Programming Activities
 * 
 * 1. The statement '__delay_ms(100);' creates a 100ms delay. Try changing one
 *    or more of the delay values in the program to 500ms and see what happens.
 * As the number of delay values change, the amount of time delay increases when the led flashs. 
 *    Can the delay be made even longer? Try 1000 ms. How big can the delay be
 *    before MPLAB-X produces an error message? (Hint: can you think of a fast
 *    and efficient way of guessing an unknown number?)
 * The maximum delay value is 4205, when the number is greater than 4205 the program will produces an error message.
 * 2. The '__delay_ms();' function only accepts integers as delay values. To
 *    make delays shorter than 1ms, specify a delay in microseconds using the
 *    '__delay_us();' function. You won't be able to see such short LED flashes
 *    with your eyes, but you could measure them using an oscilloscope, or hear
 *    them if they are used to turn the piezo beeper on and off. Try this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = 1;
            __delay_us(567);
            BEEPER = 0;
            __delay_us(567);
        }

 *    Try changing the delay values in both of the __delay_us(); functions.
 *    Does the pitch of the tone increase or decrease if the delay value is
 *    made smaller?
 * If the delay value gets smaller, the pitch of the tone increases. 
 * 3. This code demonstrates a more compact way of toggling the beeper output
 *    using a logical NOT operator '!'. Replace the code above, with this code:
 
        // Make a tone while SW5 is held
        if(SW5 == 0)
        {
            BEEPER = !BEEPER;
            __delay_us(567);
        }

 *    One difference between this code and the code in 2, above, is the state
 *    of the BEEPER pin when SW5 is released. What state will the BEEPER output
 *    be in after this code runs? While one advantage of this method is smaller
 *    code, can you think of one or more disadvantages based on its output when
 *    the button is released?
 * The disadvantage of this code is that you can not define the state of the code. When the button is pressed, the beeper can be at state 1 or state 0.
 * 4. Using modified versions of the original SW2 'if' structure, create a
 *    program that makes a unique LED flashing pattern for each pushbutton.
 *
    // Modified versions of the original SW2 'if' structure
     if(SW2 == 0)
        {
            LED3 = 1;
            LED6 = 1;
            __delay_ms(200);
            LED4 = 1;
            LED5 = 1;
            __delay_ms(100);
            LED4 = 0;
            LED5 = 0;
            __delay_ms(100);
            LED4 = 1;
            LED5 = 0;
            __delay_ms(100);
            LED3 = 0;
            LED6 = 0;
            __delay_ms(100);
            
        }

 *    Test each of your flashing patterns. Describe what happens when more than
 *    one button is held. Do all of the patterns try to flash the LEDs at the
 *    same time, or sequentially? Explain why this is.
 * All the patterns try to flash at the same time, it is because the computer needs more specific information to program the seperate patterns. 
 * 5. Create a program that makes a different tone for each pushbutton.
 *   if(SW2 == 0) //Note G1
        {
            BEEPER = 1;
            __delay_us(1420);
            BEEPER = 0;
            __delay_us(1420);
        }
        else
        if(SW3 == 0) //Note C0
        {
            BEEPER = 1;
            __delay_us(474);
            BEEPER = 0;
            __delay_us(474);
        }
        else
        if(SW4 == 0) //Note D4
        {
            BEEPER = 1;
            __delay_us(8512);
            BEEPER = 0;
            __delay_us(8512);
        }
        else
        if(SW5 == 0) //Note E0
        {
            BEEPER = 1;
            __delay_us(597);
            BEEPER = 0;
            __delay_us(597);
        }

 *    Test each tone by pressing each button individually. Next, press two or
 *    more buttons at the same time. Describe what the tone waveform would look
 *    like when more than one button is held.
 * 
 * 6. Use individual 'if' structures to simulate 'Start' and 'Stop' buttons for
 *    an industrial machine. LED D4 should turn on when SW3 is pressed, stay on
 *    even after SW3 is released, and turn off when SW4 is pressed. Test your
 *    program to make sure it works.
 * 
 * 7. Running your program from 6, above, describe what happens when both SW3
 *    and SW4 are pressed. Does LED D4 stay on? If so, how does the brightness
 *    of LED D4 compare between its normal on state following SW3 being pressed
 *    to this new state when both SW3 and SW4 are bing held? Can you explain
 *    why it changes?
 * 
 * 8. As you can imagine, an industrial machine that is able to turn on even
 *    while its 'Stop' button is pressed represents a significant safety hazard.
 *    Using a logical conditional operator, modify the start-stop program from
 *    activity 5 to make it safer. SW3 should only turn on LED D4 if SW4 is
 *    released.
 * 
 * 9. LED D1 is normally used to indicate that a program is running, but it can
 *    be controlled by your program as well. If you take a look at the UBMP4
 *    schematic, you will see that LED D1's cathode (or negative) pin is
 *    connected to the microcontroller instead of the anode (positive) pin as
 *    with the other LEDs. This means that you need to make D1's output a zero
 *    to turn D1 on. Try it! Make a program that controls or flashes LED D1.
 */
