#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <util/delay.h>

#define INIT_LED3 DDRB |= (1 << DDB5)
#define INIT_LED4 DDRB |= (1 << DDB4)
#define LED3_ON PORTB |= (1 << PORTB5)
#define LED3_OFF PORTB &= ~(1 << PORTB5)
#define LED4_ON PORTB |= (1 << PORTB4)
#define LED4_OFF PORTB &= ~(1 << PORTB4)

// Praktikum Micro
// Aufgabe 1.b
// Main program
int main(void) 
{
    // Set all pins of port B to output                                                  
    INIT_LED3;
    INIT_LED4;
                                                    
    while (1)                                                           
    {                                                    
        LED3_ON;
        LED4_OFF;                                       
        _delay_ms(500);                                                 
        LED3_OFF;
        LED4_ON;                                      
        _delay_ms(500);                                                 
    }                                                                   
}