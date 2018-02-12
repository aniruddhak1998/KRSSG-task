#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void)
{
  Serial.begin(9600);
  DDRD = 255;  //we need to set the pwm pins to output if we are using normal mode pwm
  int a; //to store the value given after adc conversion 

  //adc part
  ADMUX |= (1<<ADLAR); //we use the internal voltage for reference so no change to refs and we want to store 8 bits in adch so adlar =1 and we take adc input in pin0 of mux pins also all zero
  ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //set aden 1 to set the selcted pin as adc pin and adsp2,adsp1,adsp0 are used to set the prescaling factor for adc conversion set to 128 as for lesser than 200khz prescaler of atleast 80 is required

  //pwm part
  TCCR0A |= (1<<COM0A1)|(1<<COM0A0)|(1<<WGM01)|(1<<WGM00);// com is used to set inverting mode and the wgm pins are used to set the mode of pwm(fast)
  TCCR0B |= (0<<CS02)|(0<<CS01)|(1<<CS00);   //to set the prescaling factor for the tcnt0 clock
  TCNT0 =0;      //to start the tcnt0 clock
  OCR0A = 0; //initializing the comparing value to 0
   
  while (1)
  {
    ADCSRA |=(1<<ADSC);//to start the adc conversion
    while(ADCSRA&(1<<ADSC));  // wait til the adc conversion is over
    a = ADCH;
    Serial.println(a);
    OCR0A = a/4;  // to set the comparing value for the pwm generation
    
    
    
  }
}

