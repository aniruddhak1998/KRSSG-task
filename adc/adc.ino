#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void)
{
  ADMUX |= (1<<ADLAR)|(1<<REFS0)|(1<<REFS1); 
  /*we use the internal voltage for reference so no change to refs and we want to store 8 bits in adch so adlar =1 and we take 
  adc input in pin0 of mux pins also all zero*/
  
  ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); 
  /*set aden 1 to set the selcted pin as adc pin and adsp2,adsp1,adsp0 are used to set the prescaling factor for adc conversion 
  set to 128 as for lesser than 200khz prescaler of atleast 80 is required*/

  while (1)
  {
    ADCSRA |= (1<<ADSC);   //to start the adc conversion
    while(ADCSRA&(1<<ADSC));  //to stop till the adc conversion is over
    a = (ADCH<<2)|(ADCL>>6);

    
  }

}

