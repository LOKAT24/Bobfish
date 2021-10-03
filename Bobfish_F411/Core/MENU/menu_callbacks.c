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
		GFX_DrawFillRoundRectangle(7, 7, 113, 49, 8, BLACK);
		GFX_DrawRoundRectangle(7, 7, 113, 49, 8, WHITE);
		GFX_DrawFillRoundRectangle(10, 10, 107, 43, 5, WHITE);
		wchar_t str[20];
		swprintf(str,sizeof(str),L"%ls",currentPointer->name);
		uint8_t x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(str)/2;
		GFX_DrawString(x_pos, 13, str, BLACK, WHITE);
		wchar_t str_g[3];
		wchar_t str_m[3];
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
	if(currentPointer->variable->type==_RTC_Date){
			GFX_DrawFillRoundRectangle(7, 7, 113, 49, 8, BLACK);
			GFX_DrawRoundRectangle(7, 7, 113, 49, 8, WHITE);
			GFX_DrawFillRoundRectangle(10, 10, 107, 43, 5, WHITE);
			//GFX_DrawFillRoundRectangle(10, 10, 107, 43, 5, WHITE);
			wchar_t str[20];
			swprintf(str,sizeof(str),L"%ls",currentPointer->name);
			uint8_t x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(str)/2;
			GFX_DrawString(x_pos, 13, str, BLACK, WHITE);
			wchar_t str_d[3];
			wchar_t str_m[3];
			wchar_t str_r[3];
			swprintf(str_d,sizeof(str_d),L"%02d",(currentPointer->variable)->tab[0]);
			swprintf(str_m,sizeof(str_m),L"%02d",(currentPointer->variable)->tab[1]);
			swprintf(str_r,sizeof(str_r),L"%02d",(currentPointer->variable)->tab[2]);

			swprintf(str,sizeof(str),L"%ls/%ls/%ls",(RtcTime.SubSeconds%127>90)&&value_cursor==0?L"___":str_d,(RtcTime.SubSeconds%127>90)&&value_cursor==1?L"___":str_m,(RtcTime.SubSeconds%127>90)&&value_cursor==2?L"___":str_r);
			x_pos=SSD1306_LCDWIDTH/2-GFX_GetStringWidth(str)/2;
			GFX_DrawString(x_pos, 15+GFX_GetFontHeight(), str, BLACK, WHITE);

			/*
			uint8_t dot_x_pos=SSD1306_LCDWIDTH/3-GFX_GetStringWidth(L"/")/3;
			GFX_DrawString(dot_x_pos,  15+GFX_GetFontHeight(), L"/", BLACK, WHITE);
			if(!((RtcTime.SubSeconds%127>90)&&value_cursor==0))
				GFX_DrawString(dot_x_pos-GFX_GetStringWidth(str_d),  15+GFX_GetFontHeight(), str_d, BLACK, WHITE);
			if(!((RtcTime.SubSeconds%127>90)&&value_cursor==1))
				GFX_DrawString(dot_x_pos+GFX_GetStringWidth(L"/"),  15+GFX_GetFontHeight(), str_m, BLACK, WHITE);
			if(!((RtcTime.SubSeconds%127>90)&&value_cursor==1))
				GFX_DrawString(dot_x_pos+GFX_GetStringWidth(L"/"),  15+GFX_GetFontHeight(), str_r, BLACK, WHITE);
				*/


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
	//menu_variables_save_eeprom();
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
	if(currentType==_RTC_Date){
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
	if(currentType==_RTC_Date){
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

/****************************************************************************************************************************************
															Kolor change:
***************************************************************************************************************************************/

uint8_t color_cursorH=0;
uint8_t color_cursorH_max=0;
uint8_t color_cursorV=0;
const uint8_t color_cursorV_max=3;

enum{NONE,RGB,HSV,TEMP};
uint8_t color_change_mode=NONE;//0-NONE, 1-RGB, 2-HSV, 3-TEMP

void color_change_exit(void){
	key_down_func=temp_key_down_func;
	key_up_func=temp_key_up_func;
	key_enter_func=temp_key_enter_func;
	key_left_func=temp_key_left_func;
	key_right_func=temp_key_right_func;
	refresh_func=temp_refresh_func;
}

void color_up(void){
	allColor_t *temp_color=currentPointer->variable->color;

	switch(color_change_mode){
	case NONE:
		if(color_cursorV==0)color_cursorV=color_cursorV_max;
		else color_cursorV--;
		break;
	case RGB:
		switch(color_cursorH){
		case 0:
			temp_color->rgb.r++;
			break;
		case 1:
			temp_color->rgb.g++;
			break;
		case 2:
			temp_color->rgb.b++;
			break;
		}
		RgbToHsv(temp_color);
		break;
	case HSV:
		switch(color_cursorH){
		case 0:
			temp_color->hsv.h++;
			break;
		case 1:
			temp_color->hsv.s++;
			break;
		case 2:
			temp_color->hsv.v++;
			break;
		}
		break;
	case TEMP:
		temp_color->temp+=100;
		break;


	}
}
void color_down(void){
	allColor_t *temp_color=currentPointer->variable->color;

	switch(color_change_mode){
	case NONE:
		if(color_cursorV==color_cursorV_max)color_cursorV=0;
		else color_cursorV++;
		break;
	case RGB:
		switch(color_cursorH){
		case 0:
			temp_color->rgb.r--;
			break;
		case 1:
			temp_color->rgb.g--;
			break;
		case 2:
			temp_color->rgb.b--;
			break;
		}
		RgbToHsv(temp_color);
		break;
	case HSV:
		switch(color_cursorH){
		case 0:
			temp_color->hsv.h--;
			break;
		case 1:
			temp_color->hsv.s--;
			break;
		case 2:
			temp_color->hsv.v--;
			break;
		}
		break;
	case TEMP:
		temp_color->temp-=100;
		break;
	}
}
void color_enter(void){
	allColor_t *temp_color=currentPointer->variable->color;

	if(color_change_mode==NONE){
		color_cursorH_max=2;
		switch(color_cursorV){
		case 0://RGB
			color_cursorH_max=2;
			color_change_mode=RGB;
			temp_color->type=_ColorRGB;
			break;
		case 1://HSV
			color_cursorH_max=2;
			color_change_mode=HSV;
			temp_color->type=_ColorHSV;
			break;
		case 2://TEMPERATURE
			color_cursorH_max=0;
			color_change_mode=TEMP;
			temp_color->type=_ColorTemp;
			break;
		case 3://SAVE
			color_cursorH=0;
			color_cursorH_max=0;
			color_change_exit();
			break;

		}
	}else{
		color_cursorH=0;
		color_cursorH_max=0;
		color_change_mode=NONE;
	}

}
void color_left(void){
	if(color_cursorH==0)color_cursorH=color_cursorH_max;
	else color_cursorH--;
}
void color_right(void){
	if(color_cursorH==color_cursorH_max)color_cursorH=0;
	else color_cursorH++;
}
void color_refresh(void){
 //TODO
}

void color_change(void){
	color_cursorH=0;
	color_cursorV=0;

	temp_key_down_func=key_down_func;
	temp_key_up_func=key_up_func;
	temp_key_enter_func=key_enter_func;
	temp_key_left_func=key_left_func;
	temp_key_right_func=key_right_func;
	temp_refresh_func=refresh_func;


	key_up_func=color_up;
	key_down_func=color_down;
	key_enter_func=color_enter;
	key_left_func=color_left;
	key_right_func=color_right;
	refresh_func=color_refresh;
}


