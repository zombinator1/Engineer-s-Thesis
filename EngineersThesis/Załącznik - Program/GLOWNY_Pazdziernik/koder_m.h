#ifndef koder_m_H_
#define koder_m_H_
#include <avr/io.h>
#include <avr/interrupt.h>

void wprowadzanieTablicy(uint8_t*  );

void ustawienia_portow();
void ustawienia_TIMER1_16bit();
void ustawienia_TIMER0_8bit();
void ustawienia_TIMER2_8bit();

void wlacz_TIMER0_8bit();
void wylacz_TIMER0_8bit();
void wlacz_TIMER1_16bit();
void wylacz_TIMER1_16bit();
void wlacz_TIMER2_8bit();
void wylacz_TIMER2_8bit();

ISR(TIMER1_COMPA_vect);
ISR(TIMER0_COMP_vect);
ISR(TIMER2_COMP_vect);

#endif 