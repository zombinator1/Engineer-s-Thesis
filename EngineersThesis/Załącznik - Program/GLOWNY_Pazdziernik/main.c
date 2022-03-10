#include <avr/io.h>
#include <util/delay.h>
#include "WprowadzanieKoduSQ.h"
#include "LCD.h"
#include "koder_m.h"


int main(void)
{						//   F1 C1 A1 C2 A2 C4 A4 X  B1 D1 B2 D2 B4 D4 F2 PRZERWA  SPI  
    uint8_t sygnal[20] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,    0, 0, 0}; 
	uint8_t	*wskSygnal = &sygnal[0];
	char ABClubD;
	
_delay_ms(50);
			sei();
			wprowadzanieTablicy(wskSygnal);
			ustawienia_portow();//koder_m
			Switch_Init();
			lcd_init();
			
			ustawienia_TIMER0_8bit();
			ustawienia_TIMER1_16bit();
			ustawienia_TIMER2_8bit();
			
			LCD_GoTo(0,0);
			LCD_WriteText("SQUAWK:");
			LCD_GoTo(7,0);
			lcd_data(A+48);
			lcd_data(B+48);
			lcd_data(C+48);
			lcd_data(D+48);	
			
						
	while(1){
	ABClubD = 0;
	if(!key_lockSPI && !(PIND & KEY_SPI))    {
		key_lockSPI=1; sygnal[18]=0;  LCD_GoTo(0,1); LCD_WriteText("SPI OFF");}
	else if( key_lockSPI && (PIND & KEY_SPI ) ){ key_lockSPI=0;}
	
	if((!key_lockSPI2 && (PIND & KEY_SPI)))    {
		key_lockSPI2=1; sygnal[18]=1;  LCD_GoTo(0,1); LCD_WriteText("SPI ON  ");}
	else if( key_lockSPI2 && !(PIND & KEY_SPI ) ){ key_lockSPI2=0;}	
 
//========================a=======================	 
	 if( !key_lockA && !(PIND & KEY_A ) ) {
		 key_lockA=1;
		ABClubD = 'a';
		 } 
	 else if( key_lockA && (PIND & KEY_A ) ){ key_lockA++;}
//========================B=======================	 
	 if( !key_lockB && !(PIND & KEY_B ) ) {
		 key_lockB=1;
		ABClubD = 'b';
	 }
	 else if( key_lockB && (PIND & KEY_B ) ) {key_lockB++;}
//========================C=======================	 
	 if( !key_lockC && !(PIND & KEY_C ) ) {
		 key_lockC=1;
		 ABClubD = 'c';
	 }
	 else if( key_lockC && (PIND & KEY_C ) ){ key_lockC ++;}
//========================D=======================	 
	 if( !key_lockD && !(PIND & KEY_D ) ) {
		 key_lockD=1;
		 ABClubD = 'd';
	 }
	 else if( key_lockD && (PIND & KEY_D ) ) {key_lockD++;}
//===============Generacja sygna³u=================
	 if( !key_lockE && !(PIND & KEY_E ) ) {
		 key_lockE=1;
			wprowadzanieTablicy(wskSygnal);
			wlacz_TIMER2_8bit();
			wlacz_TIMER1_16bit();
		 }
	 else if( key_lockE && (PIND & KEY_E ) ) {key_lockE++;}
//========================SPI=======================

	
//==================================================
if (ABClubD){
	if(ABClubD=='a') {
		A=dodaj(A);
		zmianaTablicyKoduSSR('a',A,wskSygnal);
		LCD_GoTo(7,0);
		lcd_data(A+48);
	}
	if(ABClubD=='b') {
		B=dodaj(B);
		zmianaTablicyKoduSSR('b',B,wskSygnal);
		LCD_GoTo(8,0);
		lcd_data(B+48);
	}
	if(ABClubD=='c') {
		C=dodaj(C);
		zmianaTablicyKoduSSR('c',C,wskSygnal);
		LCD_GoTo(9,0);
		lcd_data(C+48);
	}
	if(ABClubD=='d') {
		D=dodaj(D);
		zmianaTablicyKoduSSR('d',D,wskSygnal);
		LCD_GoTo(10,0);
		lcd_data(D+48);
	}
	}//if
 }//while
}//end



