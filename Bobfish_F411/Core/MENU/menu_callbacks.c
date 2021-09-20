/*
 * menu_callbacks.c
 *
 *  Created on: Feb 27, 2020
 *      Author: user
 */
#include "menu_callbacks.h"
#include "main.h"
//#include <arm_math.h>

#include "adc.h"
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


/*****************************************************************************************************************************************
														WYŚWIETLANIE PRZEBIEGU ADC
*****************************************************************************************************************************************/

void showADC_back(void){
	key_down_func=temp_key_down_func;
	key_up_func=temp_key_up_func;
	key_enter_func=temp_key_enter_func;
	key_left_func=temp_key_left_func;
	key_right_func=temp_key_right_func;
	refresh_func=temp_refresh_func;
}
uint8_t adaptiveHeight=1;
uint8_t dot_style=1;
uint16_t triger=1500;
uint32_t max=0;
uint32_t min=4095;
void showADC_refresh(void){
	SSD1306_Clear(BLACK);
	uint16_t tempADC_read[SAMPLE_NUM];
	uint32_t adc=0;
	uint16_t triger_index=63;
	max=0;
	min=4095;
	static uint32_t maxall=0;
	static uint32_t minall=4095;
	///KOPIOWANIE PRÓBKI///
	for(uint16_t i=0;i<SAMPLE_NUM;i++){
		tempADC_read[i]=ADC_read[i].word;
		adc+=tempADC_read[i];
	}
	adc=adc/SAMPLE_NUM;
	//////////////////////////////////////////////////  FFT  //////////////////////////////////////////////////////
//	// Wystarczą deklaracje dwóch struktur
//	arm_rfft_instance_f32 S;
//	arm_cfft_radix4_instance_f32 S_CFFT;
//
//	// oraz inicjalizacja, gdzie:
//	//  arg#3 – liczba próbek w buforze wejściowym; możliwe wartości to: 128, 512, 2048
//	//  arg#4 – kierunek transformacji: 0 – prosta, 1 – odwrotna
//	//  arg#5 – uporządkowanie wartości w buforze wyjściowym: 0 – odwrócone, 1 - normalne
//	arm_rfft_init_f32(&S, &S_CFFT, 512, 0, 1);
//
//	// Wyznaczenie transformaty Fouriera
//	arm_rfft_f32(&S, tempADC_read, buffer_output);
//	// Obliczenie modułów
//	arm_cmplx_mag_f32(buffer_output, buffer_output_mag, 512);
//	// Znalezienie składowej harmonicznej sygnału o największej amplitudzie
//	arm_max_f32(buffer_output_mag, 512, &maxvalue, &maxvalueindex);
//	// Skalowanie wartości modułów
//	for(i=0; i<512; ++i){
//		buffer_output_mag[i] = 100*buffer_output_mag[i]/maxvalue;
//	}
//

//	arm_rfft_instance_q15 S;
//	q15_t buffer_output[1024];
//	q15_t buffer_output_mag[512];
//
//	arm_cfft_radix4_instance_q15 S_CFFT;
//
//	arm_rfft_init_q15(&S, 512, 0, 1);
//	arm_rfft_q15(&S, (q15_t*)tempADC_read, buffer_output);
//	arm_cmplx_mag_q15(buffer_output, buffer_output_mag, 512);

	///SKALOWANIE WYKRESU (w Y)///
	if(adaptiveHeight){
		for (int i = 0; i < SAMPLE_NUM; ++i) {
			maxall=(tempADC_read[i]>maxall)?tempADC_read[i]:maxall;
			minall=(tempADC_read[i]<minall)?tempADC_read[i]:minall;
			max=(tempADC_read[i]>max)?tempADC_read[i]:max;
			min=(tempADC_read[i]<min)?tempADC_read[i]:min;
		}
	}else{
		min=minall;
		max=maxall;
	}
	///TRIGER///
	for(int i=63;i<256+63;i++){
		if((tempADC_read[i]>=triger)&&(tempADC_read[i+1]<triger)){
			triger_index=i;
			break;
		}
	}

	///WYŚWIETLANIE WYKRESU///

	for(int i=triger_index-63;i<triger_index+127-63;i++){
		if((max-min)==0)max++;
		uint32_t y1=map( (uint32_t)tempADC_read[i], min, max, 0, 63);
		if(dot_style){
			SSD1306_DrawPixel(i-(triger_index-63), y1, 1);
		}else{
			uint32_t y2=(map( (uint32_t)tempADC_read[i+1], min, max, 0, 63));
			GFX_DrawLine(i-(triger_index-63), y1, i+1-(triger_index-63), y2, 1);
		}
	}
	///RYSOWANIE TRIGERA///
	for(int i=0;i<127;i+=2){
		int32_t trig_y=map( (uint32_t)triger, min, max, 0, 63);
		if(trig_y>63)trig_y=63;
		if(trig_y<0)trig_y=0;
		SSD1306_DrawPixel(i, trig_y, 1);
	}

	wchar_t string[20];
	swprintf(string,sizeof(string),L"%04d|%04d|%04d",adc,min,max);
	GFX_DrawString(0, 0, string, 1, 0);

}
void switch_adaptiveHeight(void){
	if(adaptiveHeight)adaptiveHeight=0;
	else adaptiveHeight=1;
}
void switch_showStyle(void){
	if(dot_style)dot_style=0;
	else dot_style=1;
}
void increase_triger(void){
	triger+=10;
	if(triger>max)triger=max;
}
void decrease_triger(void){
	triger-=10;
	if(triger<min)triger=min;
}
void showADC(void){
	temp_key_down_func=key_down_func;
	temp_key_up_func=key_up_func;
	temp_key_enter_func=key_enter_func;
	temp_key_left_func=key_left_func;
	temp_key_right_func=key_right_func;
	temp_refresh_func=refresh_func;

	key_up_func=increase_triger;
	key_down_func=decrease_triger;
	key_enter_func=showADC_back;
	key_left_func=switch_adaptiveHeight;
	key_right_func=switch_showStyle;
	refresh_func=showADC_refresh;
}

