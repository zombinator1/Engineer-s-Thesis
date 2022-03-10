#include <avr/io.h>
#include <avr/interrupt.h> 
#include "koder_m.h"
//uint8_t sygnal[19] =  {0, 1,1,1,1,1,1,1 ,1, 1,1,1,1,1,1,1, 0,0,1};
//uint8_t sygnal[19] =  {0, 1,0,0,0,0,0,0 ,1, 0,0,0,0,0,0,1, 0,0,1};
uint8_t sygnal[20];// =  { 1,1,1,1,1,1,1 ,0, 1,1,1,1,1,1,1, 0,0,1,0}; //0 to wysoki
static uint8_t i;
uint8_t t;
void wprowadzanieTablicy(uint8_t * wskMain){
	for(t=0;t<=20;t++){
	sygnal[t]=*wskMain;
	wskMain++;
	}
}

//=====ustawienia poczatkowe==
void ustawienia_TIMER0_8bit(){
	TCCR0 |= (1<<WGM01);	//TRYB CTC
	wylacz_TIMER0_8bit();
	TIMSK |= (1<<OCIE0); //compare match
	OCR0 = 125;//1ms
}
void ustawienia_TIMER1_16bit(){
	TCCR1B |=(1<<WGM12);//trybCTC
	wylacz_TIMER1_16bit();
	TIMSK |= (1 << OCIE1A);
	//OCR1A=27100;	//0,45ms
	OCR1A=28000;
}

void ustawienia_TIMER2_8bit(){
		TCCR2|=(1<<WGM21);
		wylacz_TIMER2_8bit();
		TIMSK|=(1<<OCIE2);
		OCR2=56;//0,45
}
//=============================
ISR(TIMER0_COMP_vect){
	PORTB = sygnal[i];
	
	wlacz_TIMER2_8bit();
	wylacz_TIMER0_8bit();
	i++;
	
}
ISR(TIMER2_COMP_vect){
	PORTB = 0;
	wylacz_TIMER2_8bit();
	wlacz_TIMER0_8bit();
	
}
ISR(TIMER1_COMPA_vect){

		PORTB = 0;
  ustawienia_TIMER0_8bit();
  ustawienia_TIMER1_16bit();
  ustawienia_TIMER2_8bit();
  ustawienia_portow();
   //powrot adresu na [0]
		i=0;
	
}	


void wlacz_TIMER0_8bit(){
	TCCR0 |= (1<<CS01)|(1<<CS00);
}
void wylacz_TIMER0_8bit(){
	TCCR0 &= ~(1<<CS00); TCCR0 &= ~(1<<CS01); TCCR0 &= ~(1<<CS02);
}
void wlacz_TIMER1_16bit(){
	TCCR1B |= (1<<CS11);
}
void wylacz_TIMER1_16bit(){
	TCCR1B&= ~(1<<CS10); TCCR1B&= ~(1<<CS11); TCCR1B&= ~(1<<CS12);
}
void wlacz_TIMER2_8bit(){
	TCCR2|=(1<<CS22);
}
void wylacz_TIMER2_8bit(){
	TCCR2 &= ~(1<<CS20); TCCR2 &= ~(1<<CS21); TCCR2 &= ~(1<<CS22);
}
void ustawienia_portow(){
	DDRB = 0xFF;
	PORTB = 0;
	i=0;
	}
