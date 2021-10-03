/*
 * menu_variables.h
 *
 *  Created on: Apr 8, 2020
 *      Author: user
 */

#ifndef MENU_MENU_VARIABLES_H_
#define MENU_MENU_VARIABLES_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "math.h"

enum{_ColorRGB,_ColorHSV,_ColorTemp};

typedef struct colorHSV{
	uint16_t h;
	uint8_t s;
	uint8_t v;
}colorHSV;

typedef struct colorRGB {
	uint8_t r, g, b;
} colorRGB;

typedef struct allColor_t {
	uint8_t type;
	colorRGB rgb;
	colorHSV hsv;
	uint16_t temp;
} allColor_t;
#include "public_include.h"

enum { _bool, _byte, _float, _int, _uint, _RTC_Time, _RTC_Date, _string, _select, _color};

typedef struct{
	uint8_t type;
	union{
		wchar_t* string;
		float float_;
		int32_t int32;
		uint32_t uint32;
		uint8_t tab[4];
		uint8_t byte;
		allColor_t* color;
	};
}menu_variable_t;


extern menu_variable_t godzina_var;
extern menu_variable_t buzzer_state;
extern menu_variable_t trybLed_var;
extern menu_variable_t data_var;
extern menu_variable_t build_date;
extern menu_variable_t build_time;
extern menu_variable_t change_time_flag;
extern menu_variable_t displayContrast;
extern menu_variable_t czas_rano;
extern menu_variable_t czas_wieczor;
extern menu_variable_t dzien_noc_flag;
extern menu_variable_t kolorDzien_var;



void menu_variables_init(void);
uint8_t menu_variables_save_eeprom(void);

#endif /* MENU_MENU_VARIABLES_H_ */
