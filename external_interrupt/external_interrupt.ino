#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL

ISR(INT0_vect) //function which gets executed when the code is interrupted
{
  _delay_ms(500);  //to give some time for button debouncing
  PORTB ^= (1<<PB2);  // to toggle the led on each button press
}

int main(void)
{
  DDRB = (1<<PB2); // to set the  pin d as output pin to toggle the led on pb2(digital pin0)
  DDRD = (0<<PD2);  // to set the port d as input so that we can take interrupt on pd2(digital pin10) 
  PORTD = (1<<PD2); //to activate the internal pull up resistor in the pin pd2
  
   
  sei();     //to turn on the global interrupt
  EICRA |=(1<<ISC00); //to interrupt the code on logic level change on int0
  EIMSK |=(1<<INT0); // to turn the int0 interrupt on

  while(1)
  {}
  
}


