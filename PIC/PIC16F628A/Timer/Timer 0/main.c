/****************************************************************
Example: Timero 0. Counter 
Microcontroller: PIC16F628A
****************************************************************/

// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

/***********
 Functions
 ***********/
void Init_TMR0(void);    // Init Timer 0
void Init_Ports(void);    // Init Ports


void main(){
    
    Init_TMR0();  // Function that initializes the Timer
    Init_Ports(); // Function that initializes the Ports
     
    while(1);  // Wait for interruption of the TMR0
    
    return;
}

void Init_Ports(void){
    
    TRISBbits.TRISB4 = 0; // RB4 bit as output
    
    PORTBbits.RB4 = 0;  // RB4 is Clear
    
}

void Init_TMR0(void){
    
   
   TMR0=0;                   // The value is loaded from where the timer will count
   INTCON=0b11100000;        // GIE = 1; PEIE = 1; T0IE = 1; Another bits clear
   OPTION_REG = 0b00000000;  // T0CS = 0, PSA = 0; PS = 000
  
    
}

/****************
 * Interruptions
 ****************/

void interrupt Timer0_ISR(void){
    
     if(T0IF==1)              // T0IF is the interrupt flag. This is set to 0 if there was overflow.
    {
        T0IF=0;               // Clear interrupt flag
        TMR0=0;               // The value is loaded from where the timer will count
    
        PORTBbits.RB4 =!PORTBbits.RB4; //Change the state of RB3 
        
     }
      
}