/*
 * EXTERNAL INTERRUPT 2.c
 *
 * Created: 29-07-2024 15:01:55
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Interrupt Service Routine for INT2*/
ISR(INT2_vect) 
{
	PORTC	=	PORTC ^ (1<<0);		/* Toggle PORTC */
	_delay_ms(50);					/* Software debouncing control delay */
}

int main(void) 
{
	DDRC	=	DDRC | (1<<0);		/* Make PORTC as output PORT*/
	PORTC	=	PORTC | (0<<0);		/* Make pull down low */

	DDRB	=	DDRB & (~(1<<2));	/* PORTD as input */
	PORTB	=	PORTB | (1<<2);		/* Make pull up high */

	GICR	=	1<<INT2;			/* Enable INT2*/
	MCUCSR	=	MCUCSR | (1 << ISC2);

	sei();							/* Enable Global Interrupt */

	/* Replace with your application code */
	while (1)
	{
		
	}
}
