
/****************************************************************
Example: Blinky
Microcontroller: PIC16F628A
****************************************************************/

// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
// CONFIG
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000 // Clock frequency

int main(){
    
     //*********************
    //Port configuration
    //*********************
    
    TRISBbits.TRISB3 = 0; // RB3 bit as output
    // TRISB = 0b00000000; // It is configured to all the bits of port B, as outputs
     
    //************************
    // Sending data to ports
    //************************
    
     while (1) // Loop
     {
       //  PORTB = 0b00000000; // The 0X00 data is sent to the entire B port
         PORTBbits.RB3 = 0;    // The data "0" is sent to the RB3 bit
         __delay_ms(50);
         
       //  PORTB = 0b11111111; // The 0XFF data is sent to the entire B port
         PORTBbits.RB3 = 1;    // The data "1" is sent to the RB3 bit
         __delay_ms(50);
    
    }
    
    return 0;
}
