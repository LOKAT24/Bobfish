/*
 * menu.h
 *
 *  Created on: Feb 26, 2020
 *      Author: user
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_


//#include "stdio.h"
//#include "stdlib.h"
//#include "string.h"
//#include "stm32f4xx.h"
//#include "i2c.h"
//#include "wchar.h"
//#include "main.h"
//
//#include "menu_callbacks.h"
//#include "../SSD_1306_lib/GFX_BW.h"
//#include "../SSD_1306_lib/OLED_SSD1306.h"
//#include "../SSD_1306_lib/fonts/fonts.h"
//#include "menu_variables.h"
//#include "keyb.h"

#include "public_include.h"
#include "menu_variables.h"
#include "snake.h"

typedef struct menu_struct menu_t;
struct menu_struct{
	const wchar_t* name;
	menu_t* next;
	menu_t* prev;
	menu_t* child;
	menu_t* parent;
	void (*menu_function)(void);
	menu_variable_t* variable;
};


/*
 * menu_item MENU[]={
			// I,L,U,R,D,O
			{ {0,0,0,0,0,1},NULL,"GODZINA",HOME_MENU},						//0
			{ {1,0,1,1,1,1},NULL,"* Menu *",SELECT_MENU,{2,6,0}}, 	//1
			{ {2,1,1,1,1,1},NULL,"Efekty",SELECT_MENU,{3,4,5,7,0}},				//2
			{ {3,3,3,3,3,2},ValueFunction,"RGB",VALUE_MENU,{3,3,3,0}},				//3
			{ {4,4,4,4,4,2},ValueFunction,"HSV",VALUE_MENU,{4,4,4,0}},							//4
			{ {5,5,5,5,5,2},ValueFunction,"RAINBOW",VALUE_MENU,{5,5,5,0}},					//5
			{ {6,6,6,6,6,1},ValueFunction,"Godzina",VALUE_MENU,{6,6,0}},					//6
			{ {2,7,7,7,7,2},ValueFunction,"OFF",VALUE_MENU},					//7
			{ {8,1,1,1,1,1},NULL,"SUBMENU7",SELECT_MENU}					//8
};
 */

menu_t menu_0;//ekran startowy
	menu_t menu_1;//menu głowne
		menu_t menu_1_1;//efekty
			menu_t menu_1_1_1;//RGB
			menu_t menu_1_1_2;//HSV
			menu_t menu_1_1_3;//RAINBOW
			menu_t menu_1_1_4;//OFF
		menu_t menu_1_2;//OPCJE
			menu_t menu_1_2_1;//Godzina
			menu_t menu_1_2_2;//DATA
			menu_t menu_1_2_3;//Kreator efektu
				menu_t menu_1_2_3_1;//Numer efektu
				menu_t menu_1_2_3_2;//Kolor 1
				menu_t menu_1_2_3_3;//Kolor 2
				menu_t menu_1_2_3_4;//Kolor 3
				menu_t menu_1_2_3_5;//Szybkość
			menu_t menu_1_2_4;//Build
				menu_t menu_1_2_4_1;//Build Time
				menu_t menu_1_2_4_2;//Build Date
			menu_t menu_1_2_5; //Save(time/date)
		menu_t menu_1_3;//Oscyloskop
		menu_t menu_1_4; //Snake
	menu_t menu_2;//menu boczne


extern menu_t *currentPointer;
extern uint8_t menu_index;
extern uint8_t lcd_row_pos;
extern uint8_t lcd_row_pos_level[10];
extern uint8_t menu_rows;

//void key_next_press(void);
//void key_prev_press(void);
//void key_enter_press(void);
//void key_back_press(void);
void key_press(int key);


void menu_init(I2C_HandleTypeDef *i2c);
void menu_refresh(void);
void menu_next(void);
void menu_prev(void);
void menu_enter(void);
void menu_back(void);
void core_loop(void);


void (*key_down_func)(void);// = &menu_next;
void (*key_up_func)(void);// = &menu_prev;
void (*key_enter_func)(void);// = &menu_enter;
void (*key_left_func)(void);// = &menu_back;
void (*key_right_func)(void);// = NULL;
void (*refresh_func)(void);// = NULL;



#endif /* INC_MENU_H_ */
