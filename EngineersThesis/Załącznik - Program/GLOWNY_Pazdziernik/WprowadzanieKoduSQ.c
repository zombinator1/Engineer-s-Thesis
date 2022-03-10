#include <avr/io.h>
#include "WprowadzanieKoduSQ.h"

void zmianaTablicyKoduSSR(char literaSQUAWK, uint8_t wartoscPrzyLiterzeSQWUAWK,uint8_t* wskSygnal){
	uint8_t poczatek; //zaleznie czy to jest A B C lub D
	//litera kodu squawk
	uint8_t tabSQUAWK[3];
	tabSQUAWK[0] = (wartoscPrzyLiterzeSQWUAWK%0b10);
	tabSQUAWK[1] = (wartoscPrzyLiterzeSQWUAWK-tabSQUAWK[0])%0b100;
	tabSQUAWK[2] = (wartoscPrzyLiterzeSQWUAWK%0b1000)-tabSQUAWK[1]-tabSQUAWK[0];
	if(tabSQUAWK[1]) tabSQUAWK[1]=1; //nie chce miec tutaj wartosci 4
	if(tabSQUAWK[2]) tabSQUAWK[2]=1; //nie chce miec tutaj wartosci 8
	//mamy tablice intow ktora przekaze do duzego sygnalu
	//zalezy w ktorym miejscu wstawic najmlodszy bit
	if(literaSQUAWK =='A' || literaSQUAWK=='a' ){
		poczatek = 3;
	}
	if(literaSQUAWK =='B' || literaSQUAWK=='b' ){
		poczatek = 9;
	}
	if(literaSQUAWK =='C' || literaSQUAWK=='c' ){
		poczatek = 2;
	}
	if(literaSQUAWK =='D' || literaSQUAWK=='d' ){
		poczatek = 10;
	}
	//================================================
	wskSygnal+=poczatek;
	*wskSygnal=tabSQUAWK[0];
	wskSygnal+=2;
	*wskSygnal=tabSQUAWK[1];
	wskSygnal+=2;
	*wskSygnal=tabSQUAWK[2];
	wskSygnal+=2;
}//koniec funkcji

uint8_t dodaj(uint8_t ABClubD){
	if (ABClubD>=7) return 0;
	else
	return ABClubD+1;
}

void Switch_Init(){
	PORTD |= KEY_A|KEY_B|KEY_C|KEY_D|KEY_SPI|KEY_E; 

}






