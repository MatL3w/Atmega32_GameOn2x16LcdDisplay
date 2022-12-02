/*
 *       Autor: Lecik
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <util/delay.h>
#include "biblioteki/lcd_01.h"
int randommm(int min, int max)
{
    int tmp;
    if (max>=min)
        max-= min;
    else
    {
        tmp= min - max;
        min= max;
        max= tmp;
    }
    return max ? (rand() % max + min) : min;
};
uint8_t klawisz_wcisniety(void);
#define KEY_PIN (1<<PC6)
#define KEY_DOWN (PINC & KEY_PIN)
int main(void)
{
lcd_init();
lcd_cls();
DDRC &= ~KEY_PIN;
PORTC |= KEY_PIN;

int b,punkty,opoznienie;
lcd_str("Moja ");
_delay_ms(1000);
lcd_str("pierwsza");
_delay_ms(1000);
lcd_locate(1,0);
lcd_str("GRA ");
_delay_ms(1000);
lcd_str(":D");
_delay_ms(1000);
lcd_cls();
lcd_str("3");
_delay_ms(1000);
lcd_cls();
lcd_str("2");
_delay_ms(1000);
lcd_cls();
lcd_str("1");
_delay_ms(1000);
lcd_cls();
lcd_str("START");
_delay_ms(1000);
lcd_cls();
punkty = 0;
opoznienie=2;
while(1)
{
b=randommm(0,2);
	for(int i =15;i>=2;i--)
			{
					lcd_locate(b,i);
					lcd_str("\x83");
					lcd_locate(1,0);
					lcd_str("P.");
					lcd_locate(0,0);
					lcd_int(punkty);
					_delay_ms(100-opoznienie);
					lcd_locate(b,i);
					lcd_str("\x81");
					lcd_locate(1,0);
										lcd_str("P.");
										lcd_locate(0,0);
										lcd_int(punkty);
						if(klawisz_wcisniety())
							{
							lcd_cls();
								lcd_locate(0,2);
								lcd_str("\x82");
							}
							else
							{
								lcd_cls();
								lcd_locate(1,2);
										lcd_str("\x82");
							}

			}
if(klawisz_wcisniety() && (b==0))break;
if(klawisz_wcisniety()==0 && (b==1 || b==2))break;
punkty++;
}


lcd_cls();
lcd_str("koniec");
lcd_locate(1,0);
lcd_str("ilosc pkt: ");
lcd_int(punkty);
}


uint8_t klawisz_wcisniety(void)
{
	if( KEY_DOWN )					// klawisz wciœniêty ?
	{
		_delay_ms(80);				// czas drgañ styków
		if( KEY_DOWN ) return 1;   	// jeœli wciœniêty?  zakoñcz funkcjê - rezultat = 1
	}

	return 0;	// jeœli nie wciœniêty klawisz, zakoñcz funkcjê, rezultat = 0
}
