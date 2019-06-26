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

int main(void) {
DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs
DDRC = 0x00; PORTC = 0xFF;
DDRD = 0xFF; PORTD = 0x00;
				// Initialize output on PORTB to 0x00
	unsigned char shift;
	unsigned char temp_A;
	unsigned char temp_B;
	unsigned char temp_C;
	unsigned char D;
	while(1) {
		temp_A = PINA;
		temp_B = PINB;
		temp_C = PINC;
		D = (temp_A + temp_B+temp_C) > 140;
		D = D + ((abs(temp_A-temp_C)>80)<<1);
		shift =(temp_A +temp_B+temp_C)/3;
		PORTD = (shift <<2 )+ (D & 0x03);
	}
	return 1;
}
