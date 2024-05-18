#include <REG51.h>

sfr LCD_Port = 0xA0;
sbit RS = P3^0;
sbit EN = P3^1;

void delay (unsigned int);
void lcd_command (char);
void lcd_data (char);
void lcd_string (char *str);
void lcd_init (void);

void delay (unsigned int cnt)
{
	int i, j;
	for (i = 0; i < cnt; i++)
		for (j = 0; j < 922; j++);
}

void lcd_command (char command)
{
	LCD_Port = command;
	RS = 0;
	EN = 1;
	delay(1);
	EN = 0;
	delay(1);
}

void lcd_data (char writeval)
{
	LCD_Port = writeval;
	RS = 1;
	EN = 1;
	delay(1);
	EN = 0;
	delay(1);
}

void lcd_string (char *str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
		lcd_data(str[i]);
}

void lcd_init (void)
{
	delay(20);
	lcd_command(0x38);
	lcd_command(0x0C);
	lcd_command(0x06);
	lcd_command(0x01);
	lcd_command(0x80);
}