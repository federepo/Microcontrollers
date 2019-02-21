/************************************************
 *  Program: Blinky in C. Led on Pin 13, 7 and 6
 *
 *  Board: Arduino UNO
 ***********************************************/

#include <avr/io.h>
#include <util/delay.h>

#define DELAY 1000


/***********************
 * Prototipes Functions
 ***********************/

void init_port(void);

/******************
 * Main Function
 *****************/

int main(void) {

	init_port();

    while(1){


     	PORTB = ~PORTB;
     	PORTD = ~PORTD;

        _delay_ms(DELAY);



     }

   return 0;
}


/*
 * Initializing Port
 */

void init_port(void){

	DDRB = (1<<PB5); //Pin B5 as OUT
	DDRD = (1<<PD7); //Pin D7 as OUT


}


