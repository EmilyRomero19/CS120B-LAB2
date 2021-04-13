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
	
	// THREE PORTS. A,B & C
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	
        // TEMPS TO HOLD DATA 
        unsigned char tmp1 = 0x00;
	unsigned char tmp2 = 0x00;
	unsigned char tmp3 = 0x00;
	unsigned char tmp4 = 0x00;
	unsigned char tmp5 = 0x00;
	unsigned char weight = 0x00;


    while (1) {

        //read inputS
	tmp1 = PINA;
	tmp2 = PINB;
	tmp3 = PINC;
	    
	weight = tmp1 + tmp2 + tmp3; // The weight is what is sensed by the three sensors 

	if(weight > 0x8C){ //if weight is bigger than 140 
		tmp4 = 0x01; // PD0 = 1 "TRUE"
    }
	else{
		tmp4 = 0x00; // PD0 = 0 "FALSE"
       }

	if((tmp1 - tmp3) > 0x50){ // A - C > 80
		
		tmp5 = 0x01; //PD1
	
	}
		PORTD = (weight & 0x00FC) | tmp4 | tmp5;		
    }
    return 1;
}
