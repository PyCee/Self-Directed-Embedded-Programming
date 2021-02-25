#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Time in ms between light toggle
#define DELAY 500
#define LIGHT_PIN PORTB5

int main(void) {
	// Set light pin to output
	DDRB |= (1 << LIGHT_PIN);
	while (1) {
		// Toggle built-in Arduino light
		PORTB ^= (1 << LIGHT_PIN);
		_delay_ms(DELAY);
	}
}

