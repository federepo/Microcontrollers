
/*********************************************
Example: Blinky with 3 LEDs on FG PIC BOARD
Microcontroller: PIC16F886
**********************************************/

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000 // Clock frequency

// Blue LED
#define     Config_Blue_LED      TRISAbits.TRISA2  
#define     Blue_LED             PORTAbits.RA2

// Yellow LED
#define     Config_Yellow_LED    TRISAbits.TRISA0
#define     Yellow_LED           PORTAbits.RA0

// Red LED
#define     Config_Red_LED       TRISBbits.TRISB5
#define     Red_LED              PORTBbits.RB5

// Delay
#define     Delay_LED           300        // miliseconds

/*************
  Prototipes
 *************/

void init_port(void); // Config Port as Output

void main(void) {
    
    
    init_port();
    
    while(1){
        
         Blue_LED   = ~Blue_LED;        // Blinky Blue LED
         __delay_ms(Delay_LED);
         
         Yellow_LED = ~Yellow_LED;     // Blinky Blue LED
         __delay_ms(Delay_LED);
         
         Red_LED    = ~Red_LED;       //  Blinky Red LED
         __delay_ms(Delay_LED);
                      
    }
    
    return;
}

void init_port(void){
    
    Config_Blue_LED   = 0;   // Config Bit 2, Porta A, as output
    Config_Yellow_LED = 0;   // Config Bit 0, Porta A, as output
    Config_Red_LED    = 0;   // Config Bit 5, Porta B, as output
            
    ANSEL  = 0;              //Analog Channel is disabled    
    ANSELH = 0;              // Analog Select High Register is disabled
}
