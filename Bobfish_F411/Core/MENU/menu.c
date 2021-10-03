/*
 * menu.c
 *
 *  Created on: Feb 26, 2020
 *      Author: user
 */
#include <string.h>
#include "menu.h"

/*	| name | next | prev | child | parent | callback_function |	variable | */

menu_t menu_0 = { L"Start", NULL, NULL, &menu_1, NULL, NULL, NULL}; //ekran startowy
	menu_t menu_1 = { L"* MENU *", NULL, NULL, &menu_1_1, NULL, NULL, NULL}; //menu głowne
		menu_t menu_1_1 = { L"Tryb LED'ów", &menu_1_2, &menu_1_4, &menu_1_1_1, &menu_1, NULL, NULL}; //efekty
			menu_t menu_1_1_1 = { L"Stały kolor D", &menu_1_1_2, &menu_1_1_4, NULL, &menu_1_1, value_change, &trybLed_var}; //Stały kolor 1
			menu_t menu_1_1_2 = { L"Stały kolor N", &menu_1_1_3, &menu_1_1_1, NULL, &menu_1_1, value_change, &trybLed_var}; //Stały kolor 2
			menu_t menu_1_1_3 = { L"Efekt", &menu_1_1_4, &menu_1_1_2, NULL, &menu_1_1, value_change, &trybLed_var}; //Stały efekt
			menu_t menu_1_1_4 = { L"Dzień/noc", NULL, &menu_1_1_3, NULL, &menu_1_1, value_change, &trybLed_var}; //Dzień/noc
		menu_t menu_1_2 = { L"Opcje", &menu_1_3, &menu_1_1, &menu_1_2_1, &menu_1, refresh_dateTime, NULL}; //OPCJE
			menu_t menu_1_2_1 =	{ L"Godzina", &menu_1_2_2, &menu_1_2_7, NULL, &menu_1_2, value_change, &godzina_var}; //Godzina
			menu_t menu_1_2_2 = { L"Data", &menu_1_2_4, &menu_1_2_1, NULL, &menu_1_2, value_change, &data_var}; //DATA
			menu_t menu_1_2_4 = { L"Build", &menu_1_2_5, &menu_1_2_2, &menu_1_2_4_1, &menu_1_2, NULL, NULL}; //Build
				menu_t menu_1_2_4_1 = { L"G:", &menu_1_2_4_2, &menu_1_2_4_2, NULL, &menu_1_2_4, NULL, &build_time}; //Build time
				menu_t menu_1_2_4_2 = { L"D:", NULL, &menu_1_2_4_1, NULL, &menu_1_2_4, NULL, &build_date}; //Build date
			menu_t menu_1_2_5 = { L"Kontrast", &menu_1_2_6, &menu_1_2_4, NULL, &menu_1_2, value_change, &displayContrast}; //Kontrast ekranu
			menu_t menu_1_2_6 = { L"Buzzer", &menu_1_2_7, &menu_1_2_5, NULL, &menu_1_2, value_change, &buzzer_state};
			menu_t menu_1_2_7 = { L"Menu serwis", NULL, &menu_1_2_6, NULL, &menu_1_2, code_menu, NULL}; //Save(time/date)
		menu_t menu_1_3 = { L"Wybór koloru", &menu_1_4, &menu_1_2, &menu_1_3_1, &menu_1, NULL, NULL}; //Kreator efektu
			menu_t menu_1_3_1 = { L"Kolor Dzień", &menu_1_3_2, &menu_1_3_4, NULL, &menu_1_3, color_change, &kolorDzien_var}; //Numer efektu
			menu_t menu_1_3_2 = { L"Kolor Dzień_2", &menu_1_3_3, &menu_1_3_1, NULL, &menu_1_3, value_change, NULL}; //Kolor 1
			menu_t menu_1_3_3 = { L"Kolor Noc", &menu_1_3_4, &menu_1_3_2, NULL, &menu_1_3, value_change, NULL}; //Kolor 2
			menu_t menu_1_3_4 = { L"Kolor Noc_2", NULL, &menu_1_3_3, NULL, &menu_1_3, value_change, NULL}; //Szybkość efektu
		menu_t menu_1_4 = { L"Dzień/Noc", NULL, &menu_1_3, &menu_1_4_1, &menu_1, NULL, NULL};
			menu_t menu_1_4_1 = { L"Praca", &menu_1_4_2, &menu_1_4_3, NULL, &menu_1_4, value_change, &dzien_noc_flag};
			menu_t menu_1_4_2 = { L"Rano", &menu_1_4_3, &menu_1_4_1, NULL, &menu_1_4, value_change, &czas_rano};
			menu_t menu_1_4_3 = { L"Wieczór", NULL, &menu_1_4_2, NULL, &menu_1_4, value_change, &czas_wieczor};

		menu_t menu_2 = { L"Boczne menu", NULL, NULL, NULL, &menu_0, NULL, NULL}; //menu boczne

	menu_t menu_1_X1 = { L"~Oscyloskop~", NULL, NULL, NULL, &menu_1, NULL, NULL}; //Oscyloskop
	menu_t menu_1_X2 = { L"Play \"SNAKE II\"", NULL, NULL, NULL, &menu_1, snake_play, NULL}; //Snake

menu_t *currentPointer = &menu_1;

uint8_t menu_index=0;
uint8_t lcd_row_pos=0;
uint8_t lcd_row_pos_level[10];
uint8_t menu_rows;
uint8_t number_of_submenus;

void menu_refresh(void) {
	menu_t *temp=NULL;
	int x_to_center;
	SSD1306_Clear(BLACK);

/****************************************************************************************************************************************
															Wyświetlanie nagłowka:
***************************************************************************************************************************************/
	if(currentPointer->parent){
		temp=(currentPointer->parent)->child;
		x_to_center = (SSD1306_LCDWIDTH / 2) - ((GFX_GetStringWidth((temp->parent)->name)*GFX_GetFontSize()) /2);
		GFX_DrawString(x_to_center, 0, (temp->parent)->name, WHITE, WHITE);
		GFX_DrawLine(0, GFX_GetFontHeight()*GFX_GetFontSize(), 127,  GFX_GetFontHeight()*GFX_GetFontSize(), WHITE);

		for (int i = 0; i < menu_index-(menu_rows-2); i++) {
			temp = temp->next;
		}

/****************************************************************************************************************************************
															Wyświetlanie podmenu:
***************************************************************************************************************************************/
		for (int i = 1; i < menu_rows; i++)
		{
			uint8_t y_draw=i*GFX_GetFontHeight()+2;
			GFX_DrawString(10, y_draw, temp->name, WHITE, WHITE);

/****************************************************************************************************************************************
														Wyświetlanie warości zmiennych:
***************************************************************************************************************************************/
			if(temp->variable){
				wchar_t value[20];
				switch((temp->variable)->type){		//_bool, _byte, _float, _int, _uint, _RTC_Time, _RTC_Date, _Color_RGB, _Color_HSV, _string
				case _bool:
					swprintf(value,sizeof(value),((temp->variable)->byte)?L"ON":L"OFF");
					break;
				case _byte:
					swprintf(value,sizeof(value),L"%d",(temp->variable)->byte);
					break;
				case _float:
					swprintf(value,sizeof(value),L"%f",(temp->variable)->float_);
					break;
				case _int:
					swprintf(value,sizeof(value),L"%d",(temp->variable)->int32);
					break;
				case _uint:
					swprintf(value,sizeof(value),L"%u",(temp->variable)->uint32);
					break;
				case _RTC_Time:
					swprintf(value,sizeof(value),L": %02d:%02d",(temp->variable)->tab[0],(temp->variable)->tab[1]);
					break;
				case _RTC_Date:
					swprintf(value,sizeof(value),L": %02d/%02d/%02d",(temp->variable)->tab[0],(temp->variable)->tab[1],(temp->variable)->tab[2]);
					break;
				case _string:
					swprintf(value,sizeof(value),L"%ls", (temp->variable)->string);
					break;
				case _select:
					GFX_DrawRectangle(112, y_draw+1, 13, 13, WHITE);
					if(temp->variable->byte==menu_get_index(temp)){
						swprintf(value,sizeof(value),L"x ");
					}else{
						swprintf(value,sizeof(value),L" ");
					}
					break;
				}
				uint8_t x_pos=127-GFX_GetStringWidth(value)*GFX_GetFontSize();
				GFX_DrawString(x_pos, y_draw, value, WHITE, WHITE);
			}

			if (temp == currentPointer){
				//GFX_DrawChar(0, i*GFX_GetFontHeight()+1, '>', WHITE, WHITE); // kursor
				//GFX_DrawFastVLine(RtcTime.SubSeconds%127, i*GFX_GetFontHeight()+1, GFX_GetFontHeight(), BLACK);
				int str_len=GFX_GetStringWidth(temp->name)*GFX_GetFontSize();

				GFX_DrawFillRectangle(10, y_draw, str_len, GFX_GetFontHeight(), INVERSE);
			}

			if(temp)temp = temp->next;
			if (!temp) break;
		}
/****************************************************************************************************************************************
															Wyświetlanie paska przewijania
***************************************************************************************************************************************/
		number_of_submenus=menu_get_numberOfSubmenus(currentPointer);
		uint8_t slider_startX=GFX_GetFontHeight()+2;
		GFX_DrawLine(3, slider_startX, 3, 127, WHITE);
		uint8_t slider_height=64-slider_startX;
		uint8_t rect_height=slider_height/number_of_submenus;

		GFX_DrawFillRectangle(1, slider_startX+2+menu_get_index(currentPointer)*rect_height, 5, rect_height, WHITE);

	}
/****************************************************************************************************************************************
															Wyświetlanie ekranu głownego
***************************************************************************************************************************************/
	else
	{
		temp=&menu_1;
		//GFX_DrawString(0, 0, L"PULPIT", WHITE, WHITE);
		//pulpit

		tFont* tempFont=GFX_GetFont();
		uint8_t tempFontSize=GFX_GetFontSize();
		GFX_SetFont(&Font_Times_New_Roman);
		wchar_t godz_str[10];
		wchar_t data_str[30];
		swprintf(godz_str,sizeof(godz_str),L"%02d%c%02d%c%02d",RtcTime.Hours,(RtcTime.SubSeconds>64&&RtcTime.SubSeconds<192)?L':':' ',RtcTime.Minutes,(RtcTime.SubSeconds>64&&RtcTime.SubSeconds<192)?L':':' ',RtcTime.Seconds);
		swprintf(data_str,sizeof(data_str),L"%02d/%02d/20%02d",RtcDate.Date,RtcDate.Month,RtcDate.Year);
		GFX_DrawString(127/2-GFX_GetStringWidth(data_str)/2, 63-GFX_GetFontHeight()*GFX_GetFontSize(), data_str, WHITE, WHITE);
		GFX_SetFontSize(2);
		GFX_DrawString(127/2-GFX_GetStringWidth(godz_str)*GFX_GetFontSize()/2, 0, godz_str, WHITE, WHITE);
		GFX_SetFont(tempFont);
		GFX_SetFontSize(tempFontSize);
	}
}

uint8_t menu_get_index(menu_t *q) {

	menu_t *temp;
	uint8_t i = 0;

	if (q->parent) temp = (q->parent)->child;
	else temp = &menu_1;

	while (temp != q) {
		temp = temp->next;
		i++;
	}

	return i;
}

uint8_t menu_get_level(menu_t *q) {

	menu_t *temp = q;
	uint8_t i = 0;

	if (!q->parent) return 0;

	while (temp->parent != NULL) {
		temp = temp->parent;
		i++;
	}

	return i;
}

uint8_t menu_get_numberOfSubmenus(menu_t *q){
	uint8_t i=1;

	if (!q->parent) return 0;
	menu_t *temp=q->parent->child;

	while(temp->next!=NULL){
		temp=temp->next;
		i++;
	}
	return i;
}

void menu_next(void) {

	if (currentPointer->next)
	{

		currentPointer = currentPointer->next;
		menu_index++;
		if (++lcd_row_pos > menu_rows - 2) lcd_row_pos = menu_rows - 2;
	}
	else
	{
		menu_index = 0;
		lcd_row_pos = 0;

		if (currentPointer->parent) currentPointer = (currentPointer->parent)->child;
		else currentPointer = &menu_1;
	}

	menu_refresh();

}

void menu_prev(void) {

	if(currentPointer->prev)currentPointer = currentPointer->prev;

	if (menu_index)
	{
		menu_index--;
		if (lcd_row_pos > 0) lcd_row_pos--;
	}
	else
	{
		menu_index = menu_get_index(currentPointer);

		if (menu_index >= menu_rows - 2) lcd_row_pos = menu_rows - 2;
		else lcd_row_pos = menu_index;
	}

	menu_refresh();
}

void menu_enter(void) {

	if (currentPointer->menu_function) currentPointer->menu_function();

	if (currentPointer->child)
	{

		lcd_row_pos_level[ menu_get_level(currentPointer) ] = lcd_row_pos;

		menu_index = 0;
		lcd_row_pos = 0;

		currentPointer = currentPointer->child;

		menu_refresh();
	}
}

void menu_back(void) {

	if (currentPointer->parent) {

		currentPointer = currentPointer->parent;

		lcd_row_pos=lcd_row_pos_level[ menu_get_level(currentPointer) ];
		menu_index = menu_get_index(currentPointer);

		menu_refresh();
	}
}

void menu_init(I2C_HandleTypeDef *i2c) {
	menu_variables_init();
	SSD1306_I2cInit(i2c);
	HAL_Delay(1000);
	GFX_SetFont(&Font_Times_New_Roman);
	GFX_SetFontSize(1);
	menu_rows=SSD1306_LCDHEIGHT/GFX_GetFontHeight();
	key_down_func = &menu_next;
	key_up_func = &menu_prev;
	key_enter_func = &menu_enter;
	key_left_func = &menu_back;
	key_right_func = NULL;
	refresh_func=menu_refresh;
	menu_refresh();
	SSD1306_Clear(BLACK);
	SSD1306_SetContrast(displayContrast.byte);
	SSD1306_Display();
}

void key_press(int key){
	switch(key){
	case KEY_UP:
		if(key_up_func) (*key_up_func)();
		break;
	case KEY_DOWN:
		if(key_down_func) (*key_down_func)();
		break;
	case KEY_LEFT:
		if(key_left_func) (*key_left_func)();
		break;
	case KEY_RIGHT:
		if(key_right_func) (*key_right_func)();
		break;
	case KEY_OK:
		if(key_enter_func) (*key_enter_func)();
		break;
	}
}

/*
void core_loop(void) {
	static int liczba = 0;
	static int num=0;
	static int czas=0;
	static int x_pos=0;
	static int czas_operacji=0;
	wchar_t napis[100]=L"TEST";
	#define liczba_probek 50
	static float FPS[liczba_probek];
	static double sr_FPS=0;
	static uint8_t font_index=0;
	const tFont* fonciki[]={
			//&FontMini,
			//&Font_3D,
			//&Font_8x5,
			//&Font_Big_1,
			//&Font_Harry_Potter_h48,
			//&Font_LED,
			//&Font_Tahoma,
			&Font_Times_New_Roman,
			//&Font_kuchen,
			&Font_small
	};


	int _tick=HAL_GetTick();
//	````````````````````````
	if (hi2c1.hdmatx->State == HAL_DMA_STATE_READY) SSD1306_Display(); //odświerzenie DMA(tym samym wyświetlacza)

	SSD1306_Clear(BLACK);
	//GFX_DrawChar(0, 0, L'ś', WHITE, BLACK);
	//int max_char_on_line=SSD1306_LCDWIDTH/(GFX_GetFontMaxWidth()*GFX_GetFontSize());

	swprintf(napis,sizeof(napis),L"To jest bardzo długi napis z polskimi znakami takimi jak: ÓóĄąĆćĘęŁłŃńŚśŹźŻż FPS:%.2f         ",sr_FPS);

	//swprintf(napis,sizeof(napis),L"%02d%c%02d",czas/60,((num==0)?':':' '),czas%60,sr_FPS);

	//int center = (SSD1306_LCDWIDTH / 2) - ((GFX_GetStringWidth(napis)*GFX_GetFontSize()) /2);

	int max_rows=SSD1306_LCDHEIGHT/(GFX_GetFontHeight()*GFX_GetFontSize());
	for(int i=0;i<max_rows;i++){
		GFX_DrawString(x_pos , (i*SSD1306_LCDHEIGHT/max_rows), napis, WHITE, WHITE);
		//GFX_DrawChar(0, (i*SSD1306_LCDHEIGHT/max_rows), 'Ą', WHITE, BLACK);
	}
	if((-x_pos)<(GFX_GetStringWidth(napis)*GFX_GetFontSize())-128)x_pos-=1;
	else{
		font_index++;
		x_pos=0;
		if(font_index>4)font_index=0;
		GFX_SetFont(fonciki[font_index]);
	}
	//HAL_Delay(10);
	liczba++;
	if(liczba==25){
		liczba=0;
		num=~num;
	}
	czas++;
	if(czas==1440)czas=0;

	//HAL_Delay(1000);
	static int f=0;
	if(czas_operacji)FPS[f]=1000/czas_operacji;
	f++;
	if(f>liczba_probek-1)f=0;
	for(int i=0;i<liczba_probek;i++)sr_FPS+=(double)FPS[i];
	sr_FPS=sr_FPS/liczba_probek;

	czas_operacji=HAL_GetTick()-_tick;

		float vbat=((float)(ADC_read[0].word/4095.0))*3.3;
		wchar_t fps_str[30];
		swprintf(fps_str,sizeof(fps_str),L"fps:%.f|key:%d|VBAT:%.2f|ADC2:%04d",sr_FPS,KEY_STATE,vbat,ADC_read[0].word);
		wchar_t godz_str[30];
		swprintf(godz_str,sizeof(godz_str),L"D:%02d.%02d.20%02d|T:%02d:%02d:%02d",RtcDate.Date,RtcDate.Month,RtcDate.Year,RtcTime.Hours,RtcTime.Minutes,RtcTime.Seconds);

		tFont* oldFont=GFX_GetFont();
		uint8_t oldSize=GFX_GetFontSize();
		//GFX_SetFont(&FontMini);
		GFX_SetFontSize(1);
		GFX_DrawString(128-GFX_GetStringWidth(fps_str),0, fps_str, WHITE, BLACK);
		//GFX_SetFont(&Font_8x5);
		GFX_DrawString(128-GFX_GetStringWidth(godz_str),63-GFX_GetFontHeight(), godz_str, WHITE, BLACK);
		GFX_SetFont(oldFont);
		GFX_SetFontSize(oldSize);
}*/

