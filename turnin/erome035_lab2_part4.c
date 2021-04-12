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
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

        unsigned char tmp1 = 0x00;
	unsigned char tmp2 = 0x00;
	unsigned char tmp3 = 0x00;
	unsigned char tmp4 = 0x00;
	unsigned char tmp5 = 0x00;
	unsigned char weight = 0x00;


    while (1) {

        //read input
	tmp1 = PINA;
	tmp2 = PINB;
	tmp3 = PINC;
	tmp4 = 0x00;
	tmp5 = 0x00;
	
	weight = tmp1 + tmp2 + tmp3;	

	if(weight > 0x008C){
		tmp4 = 0x01;
    }
	else{
		tmp4 = 0x02;
       }

	if(tmp1 > tmp3){
		if((tmp3 - tmp1) > 0x50){
			tmp5 = 0x02;
		}
	}
	
	else{
		if((tmp3 - tmp1) > 0x50){
			tmp5 = 0x02;
		}
	}
		PORTD = (weight & 0x00FC) | tmp4 || tmp5;
				
    }
    return 1;
}
