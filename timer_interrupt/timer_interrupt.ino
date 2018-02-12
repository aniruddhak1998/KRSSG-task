#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL

ISR(TIMER1_OVF_vect)  // to interrupt the code when timer1 overflows
{
  PORTB ^=(1<<PB2);   // toogle the led after each overflow of the counter
}

int main(void)
{
  DDRB = (1<<PB2); //set PB2(dgital pin 10) pin as output for led

  sei();  //to start the global interrupt
  TCCR1B |= (1<<CS12); // to set the prescaler of the clock tcnt1 to 256 so that we can measure a value of 1 second
  TIMSK1 |= (1<<TOIE1);//to enable the interrupt on overflow of tcnt1 timer
  TCNT1 =0;          //to start the timer

  while(1)
  {}
}

