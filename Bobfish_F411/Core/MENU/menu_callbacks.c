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
	//wchar_t temp_string[20];
	if(currentPointer->variable->type==_Color_HSV){
		//swprintf(temp_string,sizeof(temp_string),L"H:%03d|S:%03d|V:%03d",currentPointer->variable->color_hsv.h,currentPointer->variable->color_hsv.s,currentPointer->variable->color_hsv.v);
		//uint8_t char_width=GFX_GetFontMaxWidth();


		GFX_DrawFillRoundRectangle((127-60)+20*value_cursor, (lcd_row_pos+1)*GFX_GetFontHeight(), 20, GFX_GetFontHeight(), 2, INVERSE);


	}else{
		GFX_DrawLine(90, (lcd_row_pos+2)*GFX_GetFontHeight(), 127, (lcd_row_pos+2)*GFX_GetFontHeight(), 1);
	}

}

void value_save(void){
	key_down_func=temp_key_down_func;
	key_up_func=temp_key_up_func;
	key_enter_func=temp_key_enter_func;
	key_left_func=temp_key_left_func;
	key_right_func=temp_key_right_func;
	refresh_func=temp_refresh_func;

	if(currentPointer->variable==&customEfekt_color1||currentPointer->variable==&customEfekt_color2||currentPointer->variable==&customEfekt_color3){
		//WS2812BFX_SetColorHSV(0, customEfekt_color1.color_hsv.h, customEfekt_color1.color_hsv.s, customEfekt_color1.color_hsv.v);
		//WS2812BFX_SetColorHSV(1, customEfekt_color2.color_hsv.h, customEfekt_color2.color_hsv.s, customEfekt_color2.color_hsv.v);
		//WS2812BFX_SetColorHSV(2, customEfekt_color3.color_hsv.h, customEfekt_color3.color_hsv.s, customEfekt_color3.color_hsv.v);
		//WS2812BFX_SetMode(0, customEfekt_numer.byte);
		//WS2812BFX_Start(0);
	}
	if(currentPointer->variable==&customEfekt_numer){

		//WS2812BFX_Start(0);
	}
	menu_refresh();
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
			break;
		case _RTC_Date:
			((currentPointer->variable)->tab[value_cursor])--;
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
			//WS2812BFX_Stop(0);
			//WS2812BFX_SetColorHSV(0, (currentPointer->variable)->color_hsv.h, (currentPointer->variable)->color_hsv.s, (currentPointer->variable)->color_hsv.v);
			//WS2812BFX_SetMode(0, FX_MODE_STATIC);
			//WS2812BFX_Start(0);
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
				//WS2812BFX_SetMode(0, (currentPointer->variable)->byte);
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
			//WS2812BFX_Stop(0);
			//WS2812BFX_SetSpeed(0,(currentPointer->variable)->uint32);
			//WS2812BFX_Start(0);
			break;
		case _RTC_Time:
			((currentPointer->variable)->tab[value_cursor])++;
			break;
		case _RTC_Date:
			((currentPointer->variable)->tab[value_cursor])++;
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
			//WS2812BFX_Stop(0);
			//WS2812BFX_SetColorHSV(0, (currentPointer->variable)->color_hsv.h, (currentPointer->variable)->color_hsv.s, (currentPointer->variable)->color_hsv.v);
			//WS2812BFX_SetMode(0, FX_MODE_STATIC);
			//WS2812BFX_Start(0);
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
		value_save();
	}
	if(((currentPointer->variable)->type)==_bool){
		if((currentPointer->variable)->byte){
			(currentPointer->variable)->byte=0;
		}else{
			(currentPointer->variable)->byte=1;
		}
		value_save();
	}

}

/*Menu kodu serwisowego--------------------------------------------------------------------------*/
union Code_t{
	uint32_t uint;
	uint8_t tab[4];
};
union Code_t CODE={0x01020304};
union Code_t SECRET_CODE={0x06090609};

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
	if(CODE.uint==SECRET_CODE.uint){
		currentPointer=&menu_1_1_3;
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
	GFX_SetFont(&Font_Harry_Potter_h48);
	wchar_t numer[3];
	for(int i=3;i>=0;i--){
		if(!(RtcTime.SubSeconds>230&&i==code_cursor)){
		swprintf(numer,sizeof(numer),L"%d",CODE.tab[i]);
		GFX_DrawString(0+((3-i)*32), 16, numer, WHITE, WHITE);
		}
	}
	GFX_SetFont(tempFont);
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
	CODE.uint=0x01020304;
	code_cursor=3;
}

