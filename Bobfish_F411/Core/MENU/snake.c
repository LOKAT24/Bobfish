/*
 * snake.c
 *
 *  Created on: Apr 12, 2020
 *      Author: user
 */

#include <stdint.h>
#include "snake.h"
#include "menu.h"
#include "../BITMAPS/bitmaps.h"
//#include "../SSD_1306_lib/fonts/fonts.h"

void (*temp_key_down_func)(void);
void (*temp_key_up_func)(void);
void (*temp_key_enter_func)(void);
void (*temp_key_left_func)(void);
void (*temp_key_right_func)(void);
void (*temp_refresh_func)(void);


#define GAME_WIDTH 23
#define GAME_HEIGHT 13
#define FIELD_SIZE 4
#define BOARD_X_TO_SCREEN_X(x) (2+(x)*FIELD_SIZE)
#define BOARD_Y_TO_SCREEN_Y(y) (10+(y)*FIELD_SIZE)

uint8_t wait(uint32_t time);
void snake_exit(void);


typedef struct snake_part_struct snake_part;
struct snake_part_struct{
	int8_t x;
	int8_t y;
	const tImage** image;
	uint8_t rotation;
};
enum { DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT };
enum { ROT_RIGHT, ROT_UP, ROT_LEFT, ROT_DOWN ,};


uint8_t snake_dir=DIR_RIGHT;
uint8_t game_over=0;
uint16_t snake_length=3;
snake_part* snake_tab;
snake_part point_part={ .x=GAME_WIDTH-1, .y=GAME_HEIGHT-1, .image=snake_point_image, .rotation=0};
uint8_t is_eaten_flag=0;
int score=0;

void snake_part_set(uint16_t id, int8_t _x, int8_t _y, const tImage**  _image, uint8_t _rotation){
	snake_tab[id].x=_x;
	snake_tab[id].y=_y;
	snake_tab[id].image=_image;
	snake_tab[id].rotation=_rotation;

}

void snake_init(void){
	game_over=0;
	snake_length=4;
	snake_dir=DIR_RIGHT;
	snake_tab=malloc(snake_length*sizeof(*snake_tab));
	for(int i=0;i<snake_length;i++){
		if(i==0)snake_part_set(i, (snake_length-1)-i, 0, snake_head_image, ROT_RIGHT);
		else if(i==snake_length-1)snake_part_set(i, (snake_length-1)-i, 0, snake_tail_image, ROT_RIGHT);
		else snake_part_set(i, (snake_length-1)-i, 0, snake_body_image, ROT_RIGHT);
	}
}

void snake_changeSize(uint16_t size){
	snake_tab=realloc(snake_tab,size*sizeof(*snake_tab));
	snake_part_set(size-1,-1,-1,snake_tail_image,ROT_RIGHT);
}

void snake_draw(void){
	for(int id=0;id<snake_length;id++){
		//GFX_ImageRotate(BOARD_X_TO_SCREEN_X(snake_tab[id].x), BOARD_Y_TO_SCREEN_Y(snake_tab[id].y), snake_tab[id].image->data, snake_tab[id].image->width, snake_tab[id].image->height, 1,snake_tab[id].angle);
		//GFX_Image(BOARD_X_TO_SCREEN_X(snake_tab[id].x), BOARD_Y_TO_SCREEN_Y(snake_tab[id].y), snake_tab[id].image->data, snake_tab[id].image->width, snake_tab[id].image->height, 1);
		//GFX_Image(0, 0, snake_tab[id].image->data, snake_tab[id].image->width, snake_tab[id].image->height, 1);
		const tImage* temp_img=snake_tab[id].image[snake_tab[id].rotation];
		GFX_Image(BOARD_X_TO_SCREEN_X(snake_tab[id].x), BOARD_Y_TO_SCREEN_Y(snake_tab[id].y), temp_img->data, temp_img->width, temp_img->height, 1);


	}
	GFX_Image(BOARD_X_TO_SCREEN_X(point_part.x), BOARD_Y_TO_SCREEN_Y(point_part.y), point_part.image[0]->data, point_part.image[0]->width, point_part.image[0]->height, 1);

}

void snake_make_point(void){
	point_part.x=rand()%GAME_WIDTH;
	point_part.y=rand()%GAME_HEIGHT;
}

void snake_core(void){
	if(wait(100)){
		static uint8_t prew_dir=DIR_RIGHT;
		for(int id=snake_length-1;id>0;id--){
			const tImage** _image=snake_tab[id-1].image;
			uint8_t _rotation=snake_tab[id-1].rotation;
			if(id==snake_length-1){
				_rotation=snake_tab[id-1].rotation;
				_image=snake_tail_image;
			}
			if(id==1){
				//if((snake_tab[0].x!=snake_tab[1].x)&&(snake_tab[0].y!=snake_tab[1].y))
				if(prew_dir!=snake_dir){
					_image=snake_corner_image;
					if((snake_dir==DIR_RIGHT&&prew_dir==DIR_UP)||(snake_dir==DIR_DOWN&&prew_dir==DIR_LEFT)){
						_rotation=0;
					}
					if((snake_dir==DIR_RIGHT&&prew_dir==DIR_DOWN)||(snake_dir==DIR_UP&&prew_dir==DIR_LEFT)){
						_rotation=2;
					}
					if((snake_dir==DIR_LEFT&&prew_dir==DIR_DOWN)||(snake_dir==DIR_UP&&prew_dir==DIR_RIGHT)){
						_rotation=3;
					}
					if((snake_dir==DIR_LEFT&&prew_dir==DIR_UP)||(snake_dir==DIR_DOWN&&prew_dir==DIR_RIGHT)){
						_rotation=1;
					}
				}else{
					_image=(is_eaten_flag)?snake_bodyFull_image:snake_body_image;
					if(is_eaten_flag==1)is_eaten_flag=0;
				}
			}
			snake_part_set(id, snake_tab[id-1].x, snake_tab[id-1].y, _image, _rotation);
		}
		prew_dir=snake_dir;
		switch(snake_dir){
		case DIR_DOWN:
			snake_tab[0].rotation=ROT_DOWN;
			snake_tab[0].y++;
			if(snake_tab[0].y>=GAME_HEIGHT)snake_tab[0].y=0;
			break;
		case DIR_LEFT:
			snake_tab[0].rotation=ROT_LEFT;
			snake_tab[0].x--;
			if(snake_tab[0].x<0)snake_tab[0].x=GAME_WIDTH-1;
			break;
		case DIR_UP:
			snake_tab[0].rotation=ROT_UP;
			snake_tab[0].y--;
			if(snake_tab[0].y<0)snake_tab[0].y=GAME_HEIGHT-1;
			break;
		case DIR_RIGHT:
			snake_tab[0].rotation=ROT_RIGHT;
			snake_tab[0].x++;
			if(snake_tab[0].x>=GAME_WIDTH)snake_tab[0].x=0;
			break;
		}

		for(int id=1;id<snake_length;id++){
			if(snake_tab[0].x==snake_tab[id].x&&snake_tab[0].y==snake_tab[id].y){
				game_over=1;
				snake_exit();
			}
		}
		if(snake_tab[0].x==point_part.x&&snake_tab[0].y==point_part.y){
			is_eaten_flag=1;
			score+=4;
			snake_length++;
			snake_changeSize(snake_length);
			uint8_t correct_point=0;

			while(!correct_point){

				snake_make_point();
				correct_point=1;
				for(int id=0;id<snake_length;id++){
					if((snake_tab[id].x==point_part.x&&snake_tab[id].y==point_part.y)){
						correct_point=0;
					}
				}
			}
		}
	}
}
void snake_refresh(void){

	SSD1306_Clear(0);

	wchar_t score_string[20];
	tFont* tempFont=GFX_GetFont();
	uint8_t tempFontSize=GFX_GetFontSize();
	GFX_SetFont(&Font_small);
	GFX_SetFontSize(1);
	swprintf(score_string,sizeof(score_string),L"Score:%d",score);
	GFX_DrawString(0, 0, score_string, 1, 1);
	GFX_SetFont(tempFont);
	GFX_SetFontSize(tempFontSize);

	GFX_DrawRectangle(0, 8, 96, 56, 1);

	snake_core();
	snake_draw();


}

void snake_logo(void){
	SSD1306_Clear(0);
	GFX_Image(0, 0, Snake_StartScreen.data, Snake_StartScreen.width, Snake_StartScreen.height, 1);
	if(wait(2000))refresh_func=snake_refresh;
}

void snake_up(void){
	if(snake_dir!=DIR_DOWN)snake_dir=DIR_UP;
}

void snake_down(void){
	if(snake_dir!=DIR_UP)snake_dir=DIR_DOWN;
}

void snake_left(void){
	if(snake_dir!=DIR_RIGHT)snake_dir=DIR_LEFT;
}

void snake_right(void){
	if(snake_dir!=DIR_LEFT)snake_dir=DIR_RIGHT;
}

void snake_lose(void){
	free(snake_tab);
	//refresh_func=
}

uint8_t exit_cursor=0;
void snake_exit_question_menu(void);

void snake_exit(void){
	if(exit_cursor==1||game_over==1){
		free(snake_tab);

		key_down_func=temp_key_down_func;
		key_up_func=temp_key_up_func;
		key_enter_func=temp_key_enter_func;
		key_left_func=temp_key_left_func;
		key_right_func=temp_key_right_func;
		refresh_func=temp_refresh_func;
	}else{
		key_up_func=snake_up;
		key_down_func=snake_down;
		key_enter_func=snake_exit_question_menu;
		key_left_func=snake_left;
		key_right_func=snake_right;
		refresh_func=snake_refresh;
	}

}
void snake_exit_question_menu_cursorChange(void){
	if(exit_cursor==0)exit_cursor=1;
	else exit_cursor=0;
}

void snake_exit_question_menu_refresh(void){
	uint8_t w=90;
	uint8_t h=40;
	uint8_t x=SSD1306_LCDWIDTH/2 - w/2;
	uint8_t y=SSD1306_LCDHEIGHT/2 - h/2;
	GFX_DrawFillRoundRectangle(x, y, w, h, 6, WHITE);
	//tFont *tempFont=GFX_GetFont();
	wchar_t* str1=L"Wyjść?";
	int x_to_center = (SSD1306_LCDWIDTH / 2) - ((GFX_GetStringWidth(str1)*GFX_GetFontSize()) /2);
	GFX_DrawString(x_to_center, 16, L"Wyjść?", BLACK, WHITE);
	wchar_t *str2=L"Nie";
	if(!((RtcTime.SubSeconds%127>90)&&exit_cursor==0)){
		x_to_center = 64-24 - ((GFX_GetStringWidth(str2)*GFX_GetFontSize()) /2);
		GFX_DrawString(x_to_center, 32, str2, BLACK, WHITE);
	}
	wchar_t *str3=L"Tak";
	if(!((RtcTime.SubSeconds%127>90)&&exit_cursor==1)){
		x_to_center = 64+24 - ((GFX_GetStringWidth(str3)*GFX_GetFontSize()) /2);
		GFX_DrawString(x_to_center, 32, str3, BLACK, WHITE);
	}
}

void snake_exit_question_menu(void){
	key_down_func=NULL;
	key_up_func=NULL;
	key_enter_func=snake_exit;
	key_left_func=snake_exit_question_menu_cursorChange;
	key_right_func=snake_exit_question_menu_cursorChange;
	refresh_func=snake_exit_question_menu_refresh;
}

void snake_play(void){
	snake_init();

	temp_key_down_func=key_down_func;
	temp_key_up_func=key_up_func;
	temp_key_enter_func=key_enter_func;
	temp_key_left_func=key_left_func;
	temp_key_right_func=key_right_func;
	temp_refresh_func=refresh_func;

	key_up_func=snake_up;
	key_down_func=snake_down;
	key_enter_func=snake_exit_question_menu;
	key_left_func=snake_left;
	key_right_func=snake_right;
	refresh_func=snake_logo;

}

uint32_t temp_time=0;
uint8_t return_flag=1;
uint8_t wait(uint32_t time){
	if(return_flag){
		temp_time=HAL_GetTick();
		return_flag=0;
	}
	if((temp_time+time)<=HAL_GetTick())return_flag=1;
	return return_flag;
}
