
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
void Gpio_init(void);       // Init port
void Uart_init(void);       // Init UART
void Interrupt_init(void);

void main(){
    
    Gpio_init();
    Uart_init();
    
    while(1);  // Loop
}

void Gpio_init(void){
    
        TRISBbits.TRISB1 = 1; // RB4 bit as input. RX
        TRISBbits.TRISB2 = 0; // RB4 bit as input. TX
                   
}

void Uart_init(void){
     
//    PIR1  = 0b00000000;  // This register contains interrupt flag bits. RCIF and TXIF
    RCSTA = 0b10010000;  // RECEIVE STATUS AND CONTROL REGISTER. SPEN = 1; RX9 = 0, CREN = 1;  
 //   TXREG = 0b01100101;  // USART Transmit Data Register
    PIE1  = 0b00010000;  // This register contains interrupt enable bits. TXIE = 1.  Enables the USART transmit interrupt
    TXSTA = 0b00100110;  // TRANSMIT STATUS AND CONTROL REGISTER   
    SPBRG = 0b00011001;  // USART Baud Rate Generator (25). 9600 baudios con oscilador de 4MHz
    
    Interrupt_init();
}

void Interrupt_init(void){
    
    INTCONbits.GIE   =  1; 
    INTCONbits.PEIE  =  1; 
    
}

void interrupt int_usart(){
    
    if(PIR1bits.TXIF==1)
        TXREG = 0b01100101;  // USART Transmit Data Register
        
 } 