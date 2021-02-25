#include <avr/io.h>
#include <avr/interrupt.h>

// Tick duration based on CPU Frequency and Prescaler
#define TICK_DURATION 0.064
// Time in ms between light toggle
#define DELAY 1000
// Timer count for appropriately timed interrupts
#define START_TIMER_COUNT (65536 - ((uint16_t)(DELAY / TICK_DURATION)))

#define LIGHT_PIN PORTB5

ISR(TIMER1_OVF_vect){
	// Toggle built-in Arduino light
	PORTB ^= (1 << LIGHT_PIN);
	TCNT1 = START_TIMER_COUNT;
}

int main(void) {
	// Set light pin to output
	DDRB |= (1 << LIGHT_PIN);
	
	TCNT1 = START_TIMER_COUNT;
	
	TCCR1A = 0x00;
	TCCR1B = (1 << CS10) | (1 << CS12); // Set the pre-scalar to 1024
	TIMSK1 = (1 << TOIE1);
	sei();
	
	while (1) {
		// Put anything here and the blink code will interrupt whenever nessecary
	}
}