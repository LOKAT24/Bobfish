/*
 * menu_variables.h
 *
 *  Created on: Apr 8, 2020
 *      Author: user
 */

#ifndef MENU_MENU_VARIABLES_H_
#define MENU_MENU_VARIABLES_H_

//#include "stdio.h"
//#include "stdlib.h"
//#include "../WS2812B/ws2812b.h"
#include "public_include.h"

//#include "../WS2812B/ws2812b_fx.h"

enum { _bool, _byte, _float, _int, _uint, _RTC_Time, _RTC_Date, _Color_RGB, _Color_HSV, _string, _select};

typedef struct{
	uint16_t h;
	uint8_t s;
	uint8_t v;
}ws2812b_color_hsv;
typedef struct ws2812b_color {
	uint8_t red, green, blue;
} ws2812b_color;

typedef struct{
	uint8_t type;
	union{
		wchar_t* string;
		float float_;
		int32_t int32;
		uint32_t uint32;
		uint8_t tab[4];
		uint8_t byte;
		ws2812b_color color_rgb;
		ws2812b_color_hsv color_hsv;
	};
}menu_variable_t;

//wchar_t* build_date_string;
//wchar_t* build_time_string;

extern menu_variable_t godzina_var;
extern menu_variable_t buzzer_state;
extern menu_variable_t customEfekt_numer;
extern menu_variable_t customEfekt_color1;
extern menu_variable_t customEfekt_color2;
extern menu_variable_t customEfekt_color3;
extern menu_variable_t customEfekt_speed;
extern menu_variable_t trybLed_var;
extern menu_variable_t data_var;
extern menu_variable_t build_date;
extern menu_variable_t build_time;
extern menu_variable_t change_time_flag;
extern menu_variable_t displayContrast;
extern menu_variable_t czas_rano;
extern menu_variable_t czas_wieczor;
extern menu_variable_t dzien_noc_flag;



void menu_variables_init(void);

#endif /* MENU_MENU_VARIABLES_H_ */
