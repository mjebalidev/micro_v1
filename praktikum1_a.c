#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <util/delay.h>

#define INIT_LED DDRB |= (1 << DDB5)
#define LED_ON PORTB |= (1 << PORTB5)
#define LED_OFF PORTB &= ~(1 << PORTB5)

// Main program:
// 0.5 Hz => 2000 ms
// 75 % duty cycle => 1500 ms
// 25 % duty cycle => 500 ms
int main(void) 
{                                                    
    // set port direction to output for LED                   
    INIT_LED;                 
    // loop forever                             
    while (1)                                                           
    {              
        // toggle LED on port B5                                                     
        LED_ON;
        // wait 1500ms                                        
        _delay_ms(1500);
        // toggle LED off port B5                                                
        LED_OFF;
        // wait 500ms                                        
        _delay_ms(500);                                                 
    }                                                                   
}