// Praktikum Micro
// Aufgabe 1.e

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h> 
#include "LCD/main.h"
#include "LCD/i2clcd.h"
#include "LCD/i2cmaster.h"

int counter = 0;
int line = 1;
int col = 1;

ISR (INT0_vect) // Funktion für externen INT0
{
    counter += 1;
} 

int main(void)
{   
    // Initialize Interrupt
    EICRA |= (1 << ISC00); // Configure INT0 to trigger on any logical change
    EIMSK |= (1 << INT0); // Enable INT0 interrupt
    sei(); // Enable global interrupts
    // Initialize LCD
    i2c_init();
    lcd_init(); 
    // Activate light
    lcd_light(true); 
    char string1[] = "Hello World!";
    lcd_printlc(line, col, string1);
    return 0;
}