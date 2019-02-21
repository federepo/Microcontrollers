/**********************************************
 *  Program: Blinky in C. Led on Pin 13 is on
 *
 *  Board: Arduino UNO
 **********************************************/
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

   DDRB = (1<<PB5); //Pin B5 as OUT

    while(1){

        PORTB |= (1<<PB5); // PB5 High
        _delay_ms(1000);

        PORTB &= ~(1<<PB5); // PB5 Low
        _delay_ms(1000);
     }

   return 0;
}
