#include <reg51.h>
#include "LCD.h"

sbit CENTRALA = P3^7;

void volt_to_celsius (unsigned char);
extern void button(void);

void main()
{
	unsigned char val, temp = 0x80;
	lcd_init();
	P1 = 0xFF;
	P2 = 0x00;
	while(1) {
		val = P1;
		lcd_command(0x80);
		lcd_string("Temp:");
		volt_to_celsius(val);
		lcd_command(0xc0); /* Move on the next line. */
		lcd_string("Set:");
		B = temp;
		button();/* Call for interrupt on button pins. */
		temp = B;
		volt_to_celsius(temp);
		CENTRALA = (temp > val) ? 1 : 0; /* Semnal catre centrala. */
	}
}

void volt_to_celsius (unsigned char val)
{
	unsigned char c1, c2, x1, x2, x3, deg;
	c1 = (val / 8) + 8;
	c2 = val % 8;
	x1 = c1 / 10;
	x1 += 0x30;
	x2 = c1 % 10;
	x2 += 0x30;
	x3 = (c2 > 4) ? 0x35 : 0x30;
	deg = 0xDF;
	lcd_data(x1);
	lcd_data(x2);
	lcd_data('.');
	lcd_data(x3);
	lcd_data(deg);
	lcd_data('C');
}