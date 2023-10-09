// Praktikum Micro
// Aufgabe 1.d

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h> 

#define INIT_LED_GREEN DDRB |= (1 << DDB2)
#define INIT_LED_BLUE DDRB |= (1 << DDB3)

#define INIT_BUTTON1 PIND &= ~(1<<PIND2)
#define INIT_BUTTON2 PIND &= ~(1<<PIND3)

#define LED_GREEN_ON PORTB |= (1 << PORTB2)
#define LED_GREEN_OFF PORTB &= ~(1 << PORTB2)
#define LED_BLUE_ON PORTB |= (1 << PORTB3)
#define LED_BLUE_OFF PORTB &= ~(1 << PORTB3)
#define LED_BLUE_INVERT PORTB ^= (1 << PORTB3)

char oldStatusPinD3 = 1;
char newStatusPinD3 = 1;
char oldStatusPinD2 = 1;
char newStatusPinD2 = 1;
char counter = 0;


void init_leds(void)
{
    INIT_LED_GREEN;
    INIT_LED_BLUE;
}

void init_buttons(void)
{
    INIT_BUTTON1;
    INIT_BUTTON2;
}

ISR (INT0_vect) // Funktion für externen INT0
{
    counter += 1;
} 

int main(void)
{
    init_leds();
    init_buttons();

    EICRA |= (1 << ISC00); // Configure INT0 to trigger on any logical change
    EIMSK |= (1 << INT0); // Enable INT0 interrupt
    sei(); // Enable global interrupts

    while (1)
    {
        // Edge detection for Button 2
        newStatusPinD3 = (PIND & (1 << PIND3));
        if ((!newStatusPinD3) && (oldStatusPinD3))
        {
            LED_GREEN_ON;
            if(counter > 0)
            {
                LED_BLUE_OFF;
                counter -= 1;
            }
        }
        oldStatusPinD3 = newStatusPinD3;

        // Edge detection for Button 1
        newStatusPinD2 = (PIND & (1 << PIND2));
        if ((!newStatusPinD2) && (oldStatusPinD2))
        {
            LED_GREEN_OFF;
            if(counter > 0)
            {
                LED_BLUE_ON;
                counter -= 1;
            }
        }
        oldStatusPinD2 = newStatusPinD2;
    }

}