#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Delay in ms between stepper motor steps
#define STEP_DELAY 10

// Stepper motor pins, PB0 - PB3
#define MOTOR_PINS 0b00001111

int main(void) {
	// Set motor pins to output
	DDRB |= MOTOR_PINS;
	uint8_t motor_state = 0b0011;
	while (1) {
		// Forward the stepper motor state
		motor_state = ((motor_state << 1) | (motor_state >> 3)) & MOTOR_PINS;
		// Clear the previous state
		PORTB &= ~MOTOR_PINS;
		// Turn on the current state
		PORTB |= motor_state;
		_delay_ms(STEP_DELAY);
	}
}

