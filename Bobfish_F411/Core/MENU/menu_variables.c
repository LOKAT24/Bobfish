/*
 * menu_variables.c
 *
 *  Created on: Apr 8, 2020
 *      Author: user
 */


#include "menu_variables.h"

char build_time_string[10]=__TIME__;
char build_date_string[15]=__DATE__;
wchar_t build_time_wstring[10];
wchar_t build_date_wstring[15];

menu_variable_t godzina_var={ .type=_RTC_Time, .tab={16,20}};
menu_variable_t data_var={ .type=_RTC_Date, .tab={9,4,20}};
menu_variable_t buzzer_state={ .type=_bool, .byte=1};
menu_variable_t customEfekt_numer={ .type=_byte, .byte=2};
menu_variable_t customEfekt_color1={ .type=_Color_HSV, .color_hsv={ .h=0, .s=255, .v=100}};
menu_variable_t customEfekt_color2={ .type=_Color_HSV, .color_hsv={ .h=120, .s=255, .v=0}};
menu_variable_t customEfekt_color3={ .type=_Color_HSV, .color_hsv={ .h=240, .s=255, .v=0}};
menu_variable_t customEfekt_speed={ .type=_uint, .uint32=50};
menu_variable_t change_time_flag={ .type=_bool, .byte=0};

menu_variable_t build_date={ .type=_string, .string=build_date_wstring};
menu_variable_t build_time={ .type=_string, .string=build_time_wstring};


void menu_variables_init(void){
	uint8_t i;
	for(i=0;build_time_string[i];i++){
		build_time_wstring[i]=build_time_string[i];
	}
	build_time_wstring[i]=L'\0';
	for(i=0;build_date_string[i];i++){
		build_date_wstring[i]=build_date_string[i];
	}
	build_date_wstring[i]=L'\0';

	godzina_var.tab[0]=RtcTime.Hours;
	godzina_var.tab[1]=RtcTime.Minutes;
	data_var.tab[0]=RtcDate.Date;
	data_var.tab[1]=RtcDate.Month;
	data_var.tab[2]=RtcDate.Year;
}
