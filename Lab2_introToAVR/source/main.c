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
#define A1 (PINA & 0x02)
enum States {start, init,A0press, A0release, A1press, A1release,reset} state;
unsigned char x;
void TickFct_Latch(){
	unsigned char A0 = PINA0;
	switch(state){
	 case start:
		state = init;
		break;
	 case init:
		if(A0 && !A1) state = A0press;
		else if(!A0 && A1) state = A1press;
		else if(A0 &&A1) state = reset;
		else state = init;
		break;
	case A0press:
		if(A0 && A1) state = reset;
		else if(A0) state = A0press;
		else if(!A0 && !A1) state = A0release;
		else if(A1) state = A1press;
		else state = A0press; 
		break;
	case A0release:
		if(!A0 ) state = led0press;
		else state = led2on;
		break;
	case led2press:
		if(A0) state - led2press;
		else state = led0on;
		break;
		
	default:
		state = led0on;
		break; 
	}
	switch(state){
	case start:
		break;
	case led0on:
		PORTB= 1;
		break;
	case led0press:
		PORTB = 2;
		break;
	case led2on:
		PORTB = 2;
		break;
	case led2press:
		PORTB = 1;
		break;
	default:
		break;
	
	}

}
int main(void) {
DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs			
	state = start;
	
	// Initialize output on PORTB to 0x00
	while(1) {
		TickFct_Latch();
	}
	return 1;
}
