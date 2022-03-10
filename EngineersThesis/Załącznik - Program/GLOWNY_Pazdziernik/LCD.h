#include <avr/io.h>
// Komendy steruj?ce
#define LCDC_CLS					0x01
#define LCDC_HOME					0x02
#define LCDC_ENTRY					0x04
#define LCDC_ENTRYR					0x02
#define LCDC_ENTRYL					0
#define LCDC_MOVE					0x01
#define LCDC_ONOFF					0x08
#define LCDC_DISPLAYON				0x04
#define LCDC_CURSORON				0x02
#define LCDC_CURSOROFF				0
#define LCDC_BLINKON				0x01
#define LCDC_SHIFT					0x10
#define LCDC_SHIFTDISP				0x08
#define LCDC_SHIFTR					0b11100
#define LCDC_SHIFTL					0
#define LCDC_FUNC					0x20
#define LCDC_FUNC8B					0x10
#define LCDC_FUNC4B					0
#define LCDC_FUNC2L					0x08
#define LCDC_FUNC1L					0
#define LCDC_FUNC5x10				0x04
#define LCDC_FUNC5x7				0
#define LCDC_SET_CGRAM				0x40
#define LCDC_SET_DDRAM				0x80
#define LCDC_2COL					0xc0
#define LCDC_1COL                   0x80

#define RS (1<<PA6)
#define E (1<<PA7)

void lcd_cmd(unsigned char); //wysy³anie komend
void lcd_data(unsigned char);  //sending data to lcd
void lcd_init();
void LCD_WriteText(char*);
void LCD_GoTo(unsigned char, unsigned char); // x y
void probneWyswTablicy(uint8_t *);