/*	Author: jxie031
 *  Partner(s) Name: Xichao Wang
 *	Lab Section:
 *	Assignment: Lab 2  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
DDRC = 0xFF; PORTC = 0x00;
DDRD = 0xFF; PORTD = 0x00;
				// Initialize output on PORTB to 0x00
	unsigned char cntavail;
	unsigned char temp_A;
	while(1) {
		temp_A = PINA;
		cntavail = ((temp_A & 0x01)==0x01) + ((temp_A & 0x02)==0x02) + ((temp_A & 0x04)==0x04) + ((temp_A & 0x08)==0x08);
		PORTC = cntavail;
	
	}
	return 1;
}
