#include <avr/io.h>
#include <avr/interrupt.h>

#define BUTTON_PIN PIND2
#define LIGHT_PIN PORTB5

ISR(INT0_vect){
	// Interrupt when the state of PD2 is changed
	if(PIND & (1 << BUTTON_PIN)){
		// Turn on the built-in light
		PORTB |= (1 << LIGHT_PIN);
	} else {
		// Turn off the built-in light
		PORTB &= ~(1 << LIGHT_PIN);
	}
}

int main(void) {
	// Set button pin to input and light pin to output
	DDRD &= ~(1 << BUTTON_PIN);
	DDRB |= (1 << LIGHT_PIN);
	
	// 
	EICRA |= (1 << ISC01);
	EIMSK |= (1 << INT0);
	sei();
	
	PORTB &= ~(1 << LIGHT_PIN);
	while (1) {
	}
}

