/*
 * menu_callbacks.c
 *
 *  Created on: Feb 27, 2020
 *      Author: user
 */
#include "menu_callbacks.h"
#include "main.h"
//#include <arm_math.h>

#include "menu.h"
#include "../WS2812B/ws2812b_fx.h"
#include "../WS2812B/ws2812b.h"
#include "public_include.h"


#define map(x,inmin,inmax,outmin,outmax) (((x)-(inmin))*((outmax)-(outmin))/((inmax)-(inmin))+(outmin))

void (*temp_key_down_func)(void);
void (*temp_key_up_func)(void);
void (*temp_key_enter_func)(void);
void (*temp_key_left_func)(void);
void (*temp_key_right_func)(void);
void (*temp_refresh_func)(void);

uint8_t value_cursor=0;



/*****************************************************************************************************************************************
														EDYCJA ZMIENNYCH
*****************************************************************************************************************************************/

void value_change_refresh(void){
	menu_refresh();
	if(currentPointer->variable->type==_RTC_Time){
		GFX_DrawFillRoundRectangle(10, 10, 107, 43, 5, WHITE);
		wchar_t *str[20];
		swprintf(str,sizeof(str),L"%ls",currentPointer->name);
		uint8_t x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(str)/2;
		GFX_DrawString(x_pos, 13, str, BLACK, WHITE);
		wchar_t *str_g[3];
		wchar_t *str_m[3];
		swprintf(str_g,sizeof(str_g),L"%02d",(currentPointer->variable)->tab[0]);
		swprintf(str_m,sizeof(str_m),L"%02d",(currentPointer->variable)->tab[1]);
		//swprintf(str,sizeof(str),L"%ls:%ls",(RtcTime.SubSeconds%127>90)&&value_cursor==0?L"   ":str_g,(RtcTime.SubSeconds%127>90)&&value_cursor==1?L"   ":str_m);
		//x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(str)/2;
		//GFX_DrawString(x_pos, 15+GFX_GetFontHeight(), str, BLACK, WHITE);
		uint8_t dot_x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(L":")/2;
		GFX_DrawString(dot_x_pos,  15+GFX_GetFontHeight(), L":", BLACK, WHITE);
		if(!((RtcTime.SubSeconds%127>90)&&value_cursor==0))
			GFX_DrawString(dot_x_pos-GFX_GetStringWidth(str_g),  15+GFX_GetFontHeight(), str_g, BLACK, WHITE);
		if(!((RtcTime.SubSeconds%127>90)&&value_cursor==1))
			GFX_DrawString(dot_x_pos+GFX_GetStringWidth(L":"),  15+GFX_GetFontHeight(), str_m, BLACK, WHITE);

	}



	//GFX_DrawLine(90, (lcd_row_pos+2)*GFX_GetFontHeight(), 127, (lcd_row_pos+2)*GFX_GetFontHeight(), 1);
}

void value_save(void){
	key_down_func=temp_key_down_func;
	key_up_func=temp_key_up_func;
	key_enter_func=temp_key_enter_func;
	key_left_func=temp_key_left_func;
	key_right_func=temp_key_right_func;
	refresh_func=temp_refresh_func;
	menu_variable_t *ptr=currentPointer->variable;

	if(ptr==&customEfekt_color1||ptr==&customEfekt_color2||ptr==&customEfekt_color3){
		//WS2812BFX_SetColorHSV(0, customEfekt_color1.color_hsv.h, customEfekt_color1.color_hsv.s, customEfekt_color1.color_hsv.v);
		//WS2812BFX_SetColorHSV(1, customEfekt_color2.color_hsv.h, customEfekt_color2.color_hsv.s, customEfekt_color2.color_hsv.v);
		//WS2812BFX_SetColorHSV(2, customEfekt_color3.color_hsv.h, customEfekt_color3.color_hsv.s, customEfekt_color3.color_hsv.v);
		//WS2812BFX_SetMode(0, customEfekt_numer.byte);
		//WS2812BFX_Start(0);
	}
	if(ptr==&customEfekt_numer){

		//WS2812BFX_Start(0);
	}

	if(ptr==&godzina_var||ptr==&data_var){

	  RTC_TimeTypeDef teraz;
	  teraz.Hours=godzina_var.tab[0];
	  teraz.Minutes=godzina_var.tab[1];
	  teraz.Seconds=0;
	  teraz.TimeFormat=0;
	  teraz.SubSeconds=0;
	  teraz.SecondFraction=255;
	  teraz.DayLightSaving=0;
	  teraz.StoreOperation=0;
	  // dzien tygodnia,miesiac,dzien,rok
	  RTC_DateTypeDef teraz_data;
	  teraz_data.WeekDay=1;
	  teraz_data.Date=data_var.tab[0];
	  teraz_data.Month=data_var.tab[1];
	  teraz_data.Year=data_var.tab[2];

	  HAL_RTC_SetDate(&hrtc, &teraz_data, RTC_FORMAT_BIN);
	  HAL_RTC_SetTime(&hrtc,&teraz , RTC_FORMAT_BIN);

	}
	menu_variables_save_eeprom();
	menu_refresh();
}

void contrast_refresh(void){
	uint32_t contrast=map(displayContrast.byte,0,100,0,255);
	while(!(hi2c1.hdmatx->State == HAL_DMA_STATE_READY));
	while(!(hi2c1.State==HAL_I2C_STATE_READY));
	SSD1306_SetContrast(contrast);
}

void value_decrease(void){
	if(currentPointer->variable){
		switch((currentPointer->variable)->type){		//_bool, _byte, _float, _int, _uint, _RTC_Time, _RTC_Date, _Color_RGB, _Color_HSV, _string
		case _byte:
			((currentPointer->variable)->byte)--;
			if(currentPointer->variable==&customEfekt_numer){
				//WS2812BFX_PrevMode(0);
				if((currentPointer->variable)->byte>57)(currentPointer->variable)->byte=57;
				//WS2812BFX_SetMode(0, (currentPointer->variable)->byte);
			}
			if(currentPointer->variable==&displayContrast){
				if((currentPointer->variable)->byte<1)(currentPointer->variable)->byte=1;
				contrast_refresh();
			}
			break;
		case _float:
			((currentPointer->variable)->float_)-=0.1;
			break;
		case _int:
			((currentPointer->variable)->int32)--;
			break;
		case _uint:
			((currentPointer->variable)->uint32)--;
			if((currentPointer->variable)->uint32<=10)((currentPointer->variable)->uint32)=10;
			//WS2812BFX_Stop(0);
			//WS2812BFX_SetSpeed(0,(currentPointer->variable)->uint32);
			//WS2812BFX_Start(0);
			break;
		case _RTC_Time:
			((currentPointer->variable)->tab[value_cursor])--;
			if(value_cursor==0){//godzina
				if((currentPointer->variable)->tab[0]>=24)(currentPointer->variable)->tab[0]=23;
			}else{//minuta
				if((currentPointer->variable)->tab[1]>=60)(currentPointer->variable)->tab[1]=59;
			}
			break;
		case _RTC_Date:
			((currentPointer->variable)->tab[value_cursor])--;
			uint8_t *temp_tab=(currentPointer->variable)->tab;

			if(value_cursor==0){		//dzień
				switch (temp_tab[1]) {
					case 2:		//28 lub 29 dni
						if(temp_tab[2]%4){	//rok nieprzestępny
							if(temp_tab[value_cursor]<1)temp_tab[value_cursor]=28;
						}else{	//rok przestępny
							if(temp_tab[value_cursor]<1)temp_tab[value_cursor]=29;
						}
						break;
					case 4:
					case 6:
					case 9:
					case 11:	//30 dni
						if(temp_tab[value_cursor]<1)temp_tab[value_cursor]=30;
						break;
					default:	//31 dni
						if(temp_tab[value_cursor]<1)temp_tab[value_cursor]=31;
						break;
				}
			}if(value_cursor==1){		//miesiąc
				if(temp_tab[value_cursor]<1)temp_tab[value_cursor]=12;
			}else{						//rok
				if(temp_tab[value_cursor]>250)temp_tab[value_cursor]=99;
			}
			break;
		case _Color_RGB:
			switch(value_cursor){
			case 0:
				((currentPointer->variable)->color_rgb.red)++;
				break;
			case 1:
				((currentPointer->variable)->color_rgb.green)++;
				break;
			case 2:
				((currentPointer->variable)->color_rgb.blue)++;
				break;
			}
			break;
		case _Color_HSV:
			switch(value_cursor){
			case 0:
				((currentPointer->variable)->color_hsv.h)--;
				if((currentPointer->variable)->color_hsv.h>359)(currentPointer->variable)->color_hsv.h=359;
				break;
			case 1:
				((currentPointer->variable)->color_hsv.s)--;
				break;
			case 2:
				((currentPointer->variable)->color_hsv.v)--;
				break;
			}
			break;
		case _string:
			//swprintf(value,sizeof(value),L"%ls", (temp->variable)->string);
			break;
		}
	}
	value_change_refresh();
}

void value_increase(void){

	if(currentPointer->variable){
		switch((currentPointer->variable)->type){		//_bool, _byte, _float, _int, _uint, _RTC_Time, _RTC_Date, _Color_RGB, _Color_HSV, _string
		case _byte:

			((currentPointer->variable)->byte)++;
			if(currentPointer->variable==&customEfekt_numer){
				if((currentPointer->variable)->byte>57)(currentPointer->variable)->byte=0;
			}
			if(currentPointer->variable==&displayContrast){
				if((currentPointer->variable)->byte>100)(currentPointer->variable)->byte=100;
				contrast_refresh();
			}
			break;
		case _float:
			((currentPointer->variable)->float_)+=0.1;
			break;
		case _int:
			((currentPointer->variable)->int32)++;
			break;
		case _uint:
			((currentPointer->variable)->uint32)++;
			if((currentPointer->variable)->uint32>65535)((currentPointer->variable)->uint32)=65535;
			break;
		case _RTC_Time:
			((currentPointer->variable)->tab[value_cursor])++;
			if(value_cursor==0){//godzina
				if((currentPointer->variable)->tab[value_cursor]>=24)(currentPointer->variable)->tab[value_cursor]=0;
			}else{//minuta
				if((currentPointer->variable)->tab[value_cursor]>=60)(currentPointer->variable)->tab[value_cursor]=0;
			}
			break;
		case _RTC_Date:
			(currentPointer->variable)->tab[value_cursor]++;
			uint8_t *temp_tab=(currentPointer->variable)->tab;

			if(value_cursor==0){		//dzień
				switch (temp_tab[1]) {
					case 2:		//28 lub 29 dni
						if(temp_tab[2]%4){	//rok nieprzestępny
							if(temp_tab[value_cursor]>28)temp_tab[value_cursor]=1;
						}else{	//rok przestępny
							if(temp_tab[value_cursor]>29)temp_tab[value_cursor]=1;
						}
						break;
					case 4:
					case 6:
					case 9:
					case 11:	//30 dni
						if(temp_tab[value_cursor]>30)temp_tab[value_cursor]=1;
						break;
					default:	//31 dni
						if(temp_tab[value_cursor]>31)temp_tab[value_cursor]=1;
						break;
				}
			}if(value_cursor==1){		//miesiąc
				if(temp_tab[value_cursor]>12)temp_tab[value_cursor]=1;
			}else{						//rok
				if(temp_tab[value_cursor]>99)temp_tab[value_cursor]=0;
			}

			break;
		case _Color_RGB:
			switch(value_cursor){
			case 0:
				((currentPointer->variable)->color_rgb.red)++;
				break;
			case 1:
				((currentPointer->variable)->color_rgb.green)++;
				break;
			case 2:
				((currentPointer->variable)->color_rgb.blue)++;
				break;
			}
			break;
		case _Color_HSV:
			switch(value_cursor){
			case 0:
				((currentPointer->variable)->color_hsv.h)++;
				if((currentPointer->variable)->color_hsv.h>359)(currentPointer->variable)->color_hsv.h=0;
				break;
			case 1:
				((currentPointer->variable)->color_hsv.s)++;
				break;
			case 2:
				((currentPointer->variable)->color_hsv.v)++;
				break;
			}
			break;
		case _string:
			//swprintf(value,sizeof(value),L"%ls", (temp->variable)->string);
			break;
		}
	}
	value_change_refresh();
}

void cursor_left(void){
	uint8_t currentType=(currentPointer->variable)->type;
	if(currentType==_RTC_Time){
		if(value_cursor==0)value_cursor=1;
		else value_cursor--;
	}
	if(currentType==_Color_HSV||currentType==_Color_RGB||currentType==_RTC_Date){
		if(value_cursor==0)value_cursor=2;
		else value_cursor--;
	}
}

void cursor_right(void){
	uint8_t currentType=(currentPointer->variable)->type;
	if(currentType==_RTC_Time){
		if(value_cursor==1)value_cursor=0;
		else value_cursor++;
	}
	if(currentType==_Color_HSV||currentType==_Color_RGB||currentType==_RTC_Date){
		if(value_cursor==2)value_cursor=0;
		else value_cursor++;
	}
}

void value_change(void){

	temp_key_down_func=key_down_func;
	temp_key_up_func=key_up_func;
	temp_key_enter_func=key_enter_func;
	temp_key_left_func=key_left_func;
	temp_key_right_func=key_right_func;
	temp_refresh_func=refresh_func;

	key_up_func=value_increase;
	key_down_func=value_decrease;
	key_enter_func=value_save;
	key_left_func=cursor_left;
	key_right_func=cursor_right;
	refresh_func=value_change_refresh;

	value_cursor=0;
	value_change_refresh();

	if((currentPointer->parent)==&menu_1_1/*Tryb Ledów*/&&currentPointer->variable->type==_select){
		currentPointer->variable->byte=menu_get_index(currentPointer);
		if(currentPointer->variable->byte==3)dzien_noc_flag.byte=1;
		else dzien_noc_flag.byte=0;

		value_save();
	}
	if(((currentPointer->variable)->type)==_bool){
		if((currentPointer->variable)->byte){
			(currentPointer->variable)->byte=0;
		}else{
			(currentPointer->variable)->byte=1;
		}

		if(currentPointer->variable==&dzien_noc_flag){
			trybLed_var.byte=3;
		}
		value_save();
	}

}

/*Menu kodu serwisowego--------------------------------------------------------------------------*/
union Code_t{
	uint32_t uint;
	uint8_t tab[4];
};// 					 0x-3-2-1-0
union Code_t CODE=		{0x00000000};
uint8_t code_cursor=3;

void code_increase(void){
	if(CODE.tab[code_cursor]<9)CODE.tab[code_cursor]++;
	else CODE.tab[code_cursor]=0;
}
void code_decrease(void){
	if(CODE.tab[code_cursor]>0)CODE.tab[code_cursor]--;
	else CODE.tab[code_cursor]=9;
}
void enter_secret_menu(void){
	key_down_func=temp_key_down_func;
	key_up_func=temp_key_up_func;
	key_enter_func=temp_key_enter_func;
	key_left_func=temp_key_left_func;
	key_right_func=temp_key_right_func;
	refresh_func=temp_refresh_func;

	switch (CODE.uint) {
		case 0x01020304: //SNAKE PLAY
			snake_play();
			break;
		default:
			break;
	}
}
void code_cursor_right(void){
	if(code_cursor>0)code_cursor--;
	else code_cursor=3;
}
void code_cursor_left(void){
	if(code_cursor<3)code_cursor++;
	else code_cursor=0;
}
void code_menu_refresh(void){
	SSD1306_Clear(BLACK);
	int x_to_center=0;
	x_to_center = (SSD1306_LCDWIDTH / 2) - ((GFX_GetStringWidth((currentPointer->name))*GFX_GetFontSize()) /2);
	GFX_DrawString(x_to_center, 0, (currentPointer->name), WHITE, WHITE);
	GFX_DrawLine(0, GFX_GetFontHeight()*GFX_GetFontSize(), 127,  GFX_GetFontHeight()*GFX_GetFontSize(), WHITE);
	//GFX_SetFontSize(3);
	tFont *tempFont=GFX_GetFont();
	GFX_SetFont(&Font_LED);
	wchar_t numer[3];
	for(int i=3;i>=0;i--){
		if(!((RtcTime.SubSeconds%127>90)&&i==code_cursor)){
		swprintf(numer,sizeof(numer),L"%d",CODE.tab[i]);
		GFX_DrawString(0+((3-i)*32), 10, numer, WHITE, WHITE);
		}
	}
	GFX_SetFont(tempFont);
}

void refresh_dateTime(void){
	data_var.tab[0]=RtcDate.Date;
	data_var.tab[1]=RtcDate.Month;
	data_var.tab[2]=RtcDate.Year;

	godzina_var.tab[0]=RtcTime.Hours;
	godzina_var.tab[1]=RtcTime.Minutes;

}

void code_menu(void){
	temp_key_down_func=key_down_func;
	temp_key_up_func=key_up_func;
	temp_key_enter_func=key_enter_func;
	temp_key_left_func=key_left_func;
	temp_key_right_func=key_right_func;
	temp_refresh_func=refresh_func;


	key_up_func=code_increase;
	key_down_func=code_decrease;
	key_enter_func=enter_secret_menu;
	key_left_func=code_cursor_left;
	key_right_func=code_cursor_right;
	refresh_func=code_menu_refresh;
	CODE.uint=0x00000000;
	code_cursor=3;
}

