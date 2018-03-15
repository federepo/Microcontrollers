/****************************************************************
Programa Ejemplo: Blinky
Microcontrolador: PIC16F630
****************************************************************/
#include <xc.h> 
 
#define _XTAL_FREQ 12000000 // Clock frequency
 
// PIC16F630A Configuration Bit Settings

#pragma config FOSC = HS  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
 
void main ()
{
    //***********************
    //Port configuration
    //***********************
    
    TRISCbits.TRISC2 = 0; // RC2 bit as output
    // TRISC = 0b00000000; // It is configured to all the bits of port C, as outputs
     
    //************************
    // Sending data to ports
    //************************
     while (1) 
     {
       //  PORTC = 0b11111111; // The 0XFF data is sent to the entire C port
         PORTCbits.RC2 = 1; // The data "1" is sent to the RC2 bit
         __delay_ms(60);

      //  PORTC = 0b00000000; // The 0X00 data is sent to the entire C port
         PORTCbits.RC2 = 0; // The data "0" is sent to the RC2 bit
         __delay_ms(60);
         
            } 
}
