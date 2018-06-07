
#define F_CPU 400000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {

	 DDRB = (1<<PB0); //Pin B5 Salida

	  while(1){
	      PORTB |= (1<<PB0); //Ponemos el pin en alto
        _delay_ms(1000);
	      PORTB &= ~(1<<PB0); //Ponemos el pin en bajo
        _delay_ms(1000);
	   }

   return 0;
}
