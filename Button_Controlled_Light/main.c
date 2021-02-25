#include <avr/io.h>

#define BUTTON_PIN PINB4
#define LIGHT_PIN PORTB5

int main(void) {
	// Set button pin to input and light pin to output
	DDRB &= ~(1 << BUTTON_PIN);
	DDRB |= (1 << LIGHT_PIN);
	
	PORTB &= ~(1 << LIGHT_PIN);
	while (1) {
		// If the input is triggered
		if(PINB & (1 << BUTTON_PIN)){
			// Turn on the built-in light
			PORTB |= (1 << LIGHT_PIN);
		} else {
			// Turn off the built-in light
			PORTB &= ~(1 << LIGHT_PIN);
		}
	}
}

