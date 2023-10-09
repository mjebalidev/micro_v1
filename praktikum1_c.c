// Praktikum Micro
// Aufgabe 1.c

#define F_CPU 16000000UL
#include <avr/io.h>

//#define INIT_LED_RED DDRB |= (1 << DDB1)
#define INIT_LED_GREEN DDRB |= (1 << DDB2)
//#define INIT_LED_BLUE DDRB |= (1 << DDB3)

#define INIT_BUTTON1 PIND &= ~(1<<PIND2)
#define INIT_BUTTON2 PIND &= ~(1<<PIND3)

#define LED_GREEN_ON PORTB |= (1 << PORTB2)
#define LED_GREEN_OFF PORTB &= ~(1 << PORTB2)


int main(void)
{
    
    INIT_LED_GREEN;
    INIT_BUTTON1;
    INIT_BUTTON2;

    char oldStatusPinD3 = 1;
    char newStatusPinD3 = 1;
    char oldStatusPinD2 = 1;
    char newStatusPinD2 = 1;


    while (1)
    {
        // Edge detection for Button 2
        newStatusPinD3 = (PIND & (1 << PIND3));
        if ((!newStatusPinD3) && (oldStatusPinD3))
        {
            LED_GREEN_ON;
        }
        oldStatusPinD3 = newStatusPinD3;

        // Edge detection for Button 1
        newStatusPinD2 = (PIND & (1 << PIND2));
        if ((!newStatusPinD2) && (oldStatusPinD2))
        {
            LED_GREEN_OFF;
        }
        oldStatusPinD2 = newStatusPinD2;
    }

}