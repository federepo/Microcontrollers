/*******************************************************************************************************
 * This code use Pic microcontroller for sensor SR-04. If the distance exceeds 2 cm an LED lights up 
 * PIC: PIC16F628A
 * 
 * Note: The Timer1 module is a 16-bit timer/counter consisting of two 8-bit registers (TMR1H and TMR1L) 
         which are readable and writable
 *******************************************************************************************************/

// PIC16F628A Configuration Bit Settings

#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.

#include <xc.h>

#define TRIGGER      PORTAbits.RA0
#define ECHO         PORTAbits.RA1
#define LED_RED      PORTAbits.RA2

#define _XTAL_FREQ 4000000

/************
 Prototipes
 ************/

void init_port(void);
void init_timer_1(void);

void main(void) {   
    
    int count = 0;
    
    init_port();
    init_timer_1();    
    
    TRIGGER = 1;  // Start Trigger for 10 micro seconds
    __delay_us(10);  
    TRIGGER = 0;
    
    while(!ECHO);                      // Waiting for Echo goes HIGH
    TMR1ON = 1;                        // Start the count 
    while(ECHO);                       // Waiting for Echo goes LOW
    TMR1ON = 0;                        // Stop the count

    count = TMR1L | (TMR1H<<8);        //Reads Timer Value
    count = count/58.82;               //Converts Time to Distance
    
    if(count>=2 && count<=400){        //Check whether the result is valid or not
        LED_RED = 1;
    }        
        
    return;
}


void init_port(void){
    
  TRISA = 0b00000010;         // RB1 as Input PIN (ECHO)
                              // RB0 as Output PIN (TRIGGER)  
}

void init_timer_1(void){
    
    TMR1H = 0;                //Sets the Initial Value of Timer
    TMR1L = 0;
    
    T1CON = 0x10;               //Initialize Timer Module
}
