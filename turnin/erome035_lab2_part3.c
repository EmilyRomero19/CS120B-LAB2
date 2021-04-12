/*	Author: erome035
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB - 0x00;

        unsigned char cntavail = 0x00;

    while (1) {

        //read input
	cntavail = PINA;
	
	if(cntavail == 0x00 || cntavail == 0x80){
	PORTC = 0x04;
    }
	else if(cntavail == 0x01 || cntavail == 0x02 || cntavail == 0x04 || cntavail == 0x08){
	PORTC = 0x03;
       }
	
	else if(cntavail == 0x03 || cntavail == 0x06 || cntavail == 0x0C || cntavail == 0x05 || cntavail == 0x0A || cntavail == 0x09){
	PORTC = 0x02;
	}
	else if(cntavail ==  0x07 || cntavail == 0x0B || cntavail == 0x0D || cntavail == 0x0E){
	PORTC = 0x01;
       }
	else{
        // set PC7 to 1 if the entire lot is full   1000 0000
	PORTC = 0x80;
	}
    }
    return 1;
}
