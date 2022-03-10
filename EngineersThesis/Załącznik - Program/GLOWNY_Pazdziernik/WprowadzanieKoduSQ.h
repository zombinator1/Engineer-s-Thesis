#include <avr/io.h>

#define KEY_E (1<<PD5)
#define KEY_SPI (1<<PD0)
#define KEY_D (1<<PD4)
#define KEY_C (1<<PD3)
#define KEY_B (1<<PD2)
#define KEY_A (1<<PD1)

void zmianaTablicyKoduSSR(char,uint8_t,uint8_t*);
uint8_t dodaj(uint8_t);

void Switch_Init();

uint8_t key_lockA;
uint8_t key_lockB;
uint8_t key_lockC;
uint8_t key_lockD;
uint8_t key_lockE;
uint8_t key_lockEWyl;
uint8_t A;
uint8_t B;
uint8_t C;
uint8_t D;
uint8_t key_lockSPI;
uint8_t key_lockSPI2;