
#define F_CPU 400000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {

	 DDRB = (1<<PB0); //Pin B0 as OUT

	  while(1){
	      PORTB |= (1<<PB0); // PBO High
        _delay_ms(1000);
	      PORTB &= ~(1<<PB0); // PB0 Low
        _delay_ms(1000);
	   }

   return 0;
}
