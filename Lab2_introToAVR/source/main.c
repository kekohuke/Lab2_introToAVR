/*	Author: jxie031
 *  Partner(s) Name: Xichao Wang
 *	Lab Section:
 *	Assignment: Lab 2  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#define A0 (PINA & 0x01)
enum States {stateB0, stateB1} state;

void TickFct_Latch(){
	switch(state){
	 case stateB0:
		if(A0) state = stateB1;
		else if(!A0) state = stateB0;
		break;
	 case stateB1:
		 
	}

}
int main(void) {
DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs			// Initialize output on PORTB to 0x00
	while(1) {
		button = PINA & 0x01;
		tempB = PORTB;
		if(button){
			if(tempB == state0)
				tempB = state1;
			else	tempB = state0;
		}
		PORTB = tempB;
	
	}
	return 1;
}
