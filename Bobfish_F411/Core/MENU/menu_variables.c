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
menu_variable_t trybLed_var={ .type=_select, .byte=0};
menu_variable_t displayContrast={.type=_byte, .byte=1};
menu_variable_t czas_rano={ .type=_RTC_Time, .tab={6,0}};
menu_variable_t czas_wieczor={ .type=_RTC_Time, .tab={18,0}};
menu_variable_t dzien_noc_flag={ .type=_bool, .byte=0};


menu_variable_t build_date={ .type=_string, .string=build_date_wstring};
menu_variable_t build_time={ .type=_string, .string=build_time_wstring};

menu_variable_t *eeprom_variables[]={
		&godzina_var,
		&data_var,
		&buzzer_state,
		&trybLed_var,
		&displayContrast,
		&czas_rano,
		&czas_wieczor,
		&dzien_noc_flag
};

uint8_t menu_variables_save_eeprom(void){
	uint8_t fails=0;
	for(int i=0;i<sizeof(eeprom_variables)/sizeof(eeprom_variables[0]);i++){
		fails=fails+ee_write(i*4, 4, eeprom_variables[i]->tab);
	}
	return fails;
}
void menu_variables_read_eeprom(void){
	for(int i=0;i<sizeof(eeprom_variables)/sizeof(eeprom_variables[0]);i++){
		ee_read(i*4, 4, eeprom_variables[i]->tab);
	}
}


void menu_variables_init(void){
	uint8_t i;
	if(trybLed_var.byte==3)dzien_noc_flag.byte=1;
	else dzien_noc_flag.byte=0;

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
