#include <avr/io.h>
#define F_CPU 16000000UL

int main()
{
  DDRD = 255; // to set all the pins of D to output mode

  TCCR1B |= (1<<CS12); //this is used to set the prescaler of the tcnt1 clock to 256 so that we can measure a value of 1 seconds using it
  TCNT1 =0;

   while(1)
   {
    if(TCNT1>62549)
    {
      PORTD ^=(1<<PD0);
      TCNT1 =0;
    }
   }
}

