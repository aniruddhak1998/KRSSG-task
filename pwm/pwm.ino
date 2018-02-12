#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void)
{
  DDRD = 255;
  int i;

  TCCR0A |= (1<<COM0A0)|(0<<WGM02)|(0<<WGM01)|(0<<WGM00);// com is used to change that the output toggles on match and the wgm pins are used to set the mode of pwm(normal over here)
  TCCR0B |= (0<<CS02)|(0<<CS01)|(1<<CS00);   //to set the prescaling factor for the tcnt0 clock

  while (1)
  {
    TCNT0 =0;
    for(i=0;i<255;i+10)  //increase the comparing value in steps of 10 to increase the brightness slowly
    {
      OCR0A = i;       //to set the comparing value
      _delay_ms(500);  //to stop after 
    } 
  }
}

