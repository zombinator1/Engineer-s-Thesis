//#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

void lcd_cmd(unsigned char cmd)
{
	PORTC = cmd;		//portB do przesylania danych i polecen
	PORTA &=~RS;	//RS = 0
	PORTA |= E;	//set E
	_delay_ms(10);
	PORTA &=~ E; //clr E
}
void lcd_data(unsigned char data)  //sending data to lcd
{
	PORTC = data;		//portB do przesylania danych i polecen
	PORTA |= RS;  //RS = 1
	//	PORTC &=~(1<<PC1);	//RW ale to chyba usune
	PORTA |= E;	//set E
	_delay_ms(10);
	PORTA &=~ E; //clr E
}
void lcd_init(){
	DDRC = 0xff;
	DDRA = 0xff;
	lcd_cmd(0x38);	//8 bit mod
	lcd_cmd(0x0e);	//enable cursor
	lcd_cmd(0x06);	//cursor increment
	lcd_cmd(0x01);	//CLEAR lcd
	lcd_cmd(0x80);	//1st row 1st column
	
}

//-------------------------------------------------------------------------------------------------
//
// Funkcja wy?wietlenia napisu na wyswietlaczu.
//
//-------------------------------------------------------------------------------------------------
void LCD_WriteText(char * text)
{
	while(*text)
	lcd_data(*text++);
}
//-------------------------------------------------------------------------------------------------
//
// Funkcja ustawienia wspó?rz?dnych ekranowych
//
//-------------------------------------------------------------------------------------------------
void LCD_GoTo (unsigned char x, unsigned char y)
{
	lcd_cmd(LCDC_SET_DDRAM | (x + (0x40 * y)));
}
void probneWyswTablicy(uint8_t * wskSygnal){
	LCD_GoTo(0,1);
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
		lcd_data(*wskSygnal+48);
		wskSygnal++;
		lcd_data(*wskSygnal+48);
		wskSygnal++;
		lcd_data(*wskSygnal+48);
		wskSygnal++;
		lcd_data(*wskSygnal+48);
		wskSygnal++;
		lcd_data(*wskSygnal+48);
		wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal++;
	lcd_data(*wskSygnal+48);
	wskSygnal+=4;
lcd_data(*wskSygnal+48);
wskSygnal++;
	
}