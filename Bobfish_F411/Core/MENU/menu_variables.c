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

allColor_t kolorDzien={.type=_ColorRGB,.rgb={.r=255,.g=255,.b=255},.hsv={.h=0,.s=0,.v=255},.temp=6500};
allColor_t kolorDzien2={.type=_ColorRGB,.rgb={.r=255,.g=255,.b=255},.hsv={.h=0,.s=0,.v=255},.temp=6500};
allColor_t kolorNoc={.type=_ColorRGB,.rgb={.r=255,.g=255,.b=255},.hsv={.h=0,.s=0,.v=255},.temp=6500};
allColor_t kolorNoc2={.type=_ColorRGB,.rgb={.r=255,.g=255,.b=255},.hsv={.h=0,.s=0,.v=255},.temp=6500};

menu_variable_t godzina_var={ .type=_RTC_Time, .tab={16,20}};
menu_variable_t data_var={ .type=_RTC_Date, .tab={9,4,20}};
menu_variable_t buzzer_state={ .type=_bool, .byte=1};
menu_variable_t change_time_flag={ .type=_bool, .byte=0};
menu_variable_t trybLed_var={ .type=_select, .byte=0};
menu_variable_t displayContrast={.type=_byte, .byte=1};
menu_variable_t czas_rano={ .type=_RTC_Time, .tab={6,0}};
menu_variable_t czas_wieczor={ .type=_RTC_Time, .tab={18,0}};
menu_variable_t dzien_noc_flag={ .type=_bool, .byte=0};
menu_variable_t eeprom_firstInit={ .type=_uint, .uint32=0xabababab};
menu_variable_t kolorDzien_var={ .type=_color, .color=&kolorDzien};
menu_variable_t kolorDzien2_var={ .type=_color, .color=&kolorDzien2};
menu_variable_t kolorNoc_var={ .type=_color, .color=&kolorNoc};
menu_variable_t kolorNoc2_var={ .type=_color, .color=&kolorNoc2};
menu_variable_t GammaCorrectionRGB_var={ .type=_bool, .byte=0};
menu_variable_t GammaCorrectionHSV_var={ .type=_bool, .byte=0};
menu_variable_t GammaCorrectionTEMPERATURE_var={ .type=_bool, .byte=0};






menu_variable_t build_date={ .type=_string, .string=build_date_wstring};
menu_variable_t build_time={ .type=_string, .string=build_time_wstring};

menu_variable_t *eeprom_variables[]={
		&eeprom_firstInit,
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


	uint8_t data[4];
	ee_read(0, 4, data);

	if(!(data[0]==0xab&&data[1]==0xab&&data[2]==0xab&&data[3]==0xab)){ //pierwsze wgranie programu
		menu_variables_save_eeprom();
	}else{
		menu_variables_read_eeprom();
	}

}
