/*
 * lcd.c
 *
 *  Created on: Sep 30, 2021
 *      Author: M.Eltokhy
 */

#include "lcd.h"

void lcd_init(void) {
	_delay_ms(100);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x06);

}

void lcd_cmd(uint8 cmd) {
	dio_write(RS, low);
	PORTD = cmd;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_ms(100);
}

void lcd_data(uint8 data) {
	dio_write(RS, high);
	PORTD = data;
	dio_write(E, high);
	_delay_ms(3);
	dio_write(E, low);
	_delay_us(10);
}

void lcd_string(uint8 str[12]) {
	uint8 ctr = 0;
	while (str[ctr] != '\n') {
		lcd_data(str[ctr]);
		ctr++;
	}
}

void lcd_start_program(uint8 temp) {
	fan_state state;
	state = (temp >= 30) ? on : off;
	lcd_cmd(0x01);
	lcd_string("   Fan Is \n");
	(state) ? lcd_string("On \n") : lcd_string("Off\n");
	lcd_cmd(0xC0);
	lcd_string("  Temp : \n");
	if (temp > 99) {
		lcd_data(((temp / 100) % 10) + '0');
	}
	lcd_data(((temp / 10) % 10) + '0');
	lcd_data((temp % 10) + '0');
	lcd_string(" C\n");
}

void lcd_display_data(uint8 temp) {
	fan_state state;
	state = (temp >= 30) ? on : off;
	lcd_cmd(0x80);
	lcd_string("   Fan Is \n");
	(state) ? lcd_string("On \n") : lcd_string("Off\n");
	lcd_cmd(0xC0);
	lcd_string("  Temp : \n");
	if (temp > 99) {
		lcd_data(((temp / 100) % 10) + '0');
	}
	lcd_data(((temp / 10) % 10) + '0');
	lcd_data((temp % 10) + '0');
	lcd_string(" C \n");
}
