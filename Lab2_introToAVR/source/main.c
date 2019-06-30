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
#define PINA0 (PINA & 0x01)
enum States {stateB0, stateB1} state;
unsigned char x;
void TickFct_Latch(){
	unsigned char A0 = PINA0;
	switch(state){
	 case stateB0:
		if(A0) state = stateB1;
		else if(!A0) state = stateB0;
		break;
	 case stateB1:
		if(A0) state = stateB0;
		else if(!A0) state = stateB1;
		break;
	default:
		state = stateB0;
		break; 
	}
	switch(state){
	case stateB0:
		x = 1;
		PORTB = x;
		break;
	case stateB1:
		x = 2;
		PORTB = x;
		break;
	default:
		break;
	}

}
int main(void) {
DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs			
	state = stateB0;
	PORTB = 1;
	// Initialize output on PORTB to 0x00
	while(1) {
		TickFct_Latch();
	}
	return 1;
}
