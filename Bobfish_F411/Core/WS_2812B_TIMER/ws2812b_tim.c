/*
 * ws2812b.c
 *
 *  Created on: 13.03.2019
 *      Author: adamc
 */


#include "ws2812b_tim.h"
#define GAMMA_DEF 2

//uint32_t LEDS[NUMBER_OF_LEDS];
//int number_of_leds=NUMBER_OF_LEDS;
#define buffor_size 24*NUMBER_OF_LEDS+RESET_TIME
uint32_t buffor[buffor_size];


#if GAMMA_DEF==1

const uint8_t dim_curve[] = { 0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8,
		8, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12,
		12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 16, 16, 16, 16, 17,
		17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 22, 22, 22, 23, 23,
		24, 24, 25, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 32, 32,
		33, 33, 34, 35, 35, 36, 36, 37, 38, 38, 39, 40, 40, 41, 42, 43, 43, 44,
		45, 46, 47, 48, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
		62, 63, 64, 65, 66, 68, 69, 70, 71, 73, 74, 75, 76, 78, 79, 81, 82, 83,
		85, 86, 88, 90, 91, 93, 94, 96, 98, 99, 101, 103, 105, 107, 109, 110,
		112, 114, 116, 118, 121, 123, 125, 127, 129, 132, 134, 136, 139, 141,
		144, 146, 149, 151, 154, 157, 159, 162, 165, 168, 171, 174, 177, 180,
		183, 186, 190, 193, 196, 200, 203, 207, 211, 214, 218, 222, 226, 230,
		234, 238, 242, 248, 255, };
#endif
#if GAMMA_DEF==2
const uint8_t dim_curve[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
#endif
static const uint32_t kelvin_to_RGB[]= {0xff3800,0xff4700,0xff5300,0xff5d00,0xff6500,0xff6d00,0xff7300,0xff7900,0xff7e00,0xff8300,0xff8912,0xff8e21,0xff932c,0xff9836,0xff9d3f,0xffa148,0xffa54f,0xffa957,0xffad5e,0xffb165,0xffb46b,0xffb872,0xffbb78,0xffbe7e,0xffc184,0xffc489,0xffc78f,0xffc994,0xffcc99,0xffce9f,0xffd1a3,0xffd3a8,0xffd5ad,0xffd7b1,0xffd9b6,0xffdbba,0xffddbe,0xffdfc2,0xffe1c6,0xffe3ca,0xffe4ce,0xffe6d2,0xffe8d5,0xffe9d9,0xffebdc,0xffece0,0xffeee3,0xffefe6,0xfff0e9,0xfff2ec,0xfff3ef,0xfff4f2,0xfff5f5,0xfff6f8,0xfff8fb,0xfff9fd,0xfef9ff,0xfcf7ff,0xf9f6ff,0xf7f5ff,0xf5f3ff,0xf3f2ff,0xf0f1ff,0xeff0ff,0xedefff,0xebeeff,0xe9edff,0xe7ecff,0xe6ebff,0xe4eaff,0xe3e9ff,0xe1e8ff,0xe0e7ff,0xdee6ff,0xdde6ff,0xdce5ff,0xdae4ff,0xd9e3ff,0xd8e3ff,0xd7e2ff,0xd6e1ff,0xd4e1ff,0xd3e0ff,0xd2dfff,0xd1dfff,0xd0deff,0xcfddff,0xcfddff,0xcedcff,0xcddcff,0xccdbff,0xcbdbff,0xcadaff,0xc9daff,0xc9d9ff,0xc8d9ff,0xc7d8ff,0xc7d8ff,0xc6d8ff,0xc5d7ff,0xc4d7ff,0xc4d6ff,0xc3d6ff,0xc3d6ff,0xc2d5ff,0xc1d5ff,0xc1d4ff,0xc0d4ff,0xc0d4ff,0xbfd3ff,0xbfd3ff,0xbed3ff,0xbed2ff,0xbdd2ff,0xbdd2ff,0xbcd2ff,0xbcd1ff,0xbbd1ff,0xbbd1ff,0xbad0ff,0xbad0ff,0xb9d0ff,0xb9d0ff,0xb9cfff,0xb8cfff,0xb8cfff,0xb7cfff,0xb7ceff,0xb7ceff,0xb6ceff,0xb6ceff,0xb6cdff,0xb5cdff,0xb5cdff,0xb5cdff,0xb4cdff,0xb4ccff,0xb4ccff,0xb3ccff,0xb3ccff,0xb3ccff,0xb2cbff,0xb2cbff,0xb2cbff,0xb2cbff,0xb1cbff,0xb1caff,0xb1caff,0xb1caff,0xb0caff,0xb0caff};



void ws2812b_init(TIM_HandleTypeDef *htim, uint32_t Channel) {
	//
	for (int i = 0; i < NUMBER_OF_LEDS; i++) {
		LEDS[i] = 0;
	}

	for (int i = 0; i < RESET_TIME; i++) {
		buffor[i] = 0;
	}
	for (int i = 0; i < NUMBER_OF_LEDS; i++) {
		for (int j = 0; j < 24; j++) {
			if (LEDS[i] & 1 << (23 - j)) {
				buffor[RESET_TIME + j + (i * 24)] = BIT_HIGH;
			} else {
				buffor[RESET_TIME + j + (i * 24)] = BIT_LOW;

			}
		}
	}
	//START DMA
	HAL_TIM_PWM_Start_DMA(htim, Channel,buffor,buffor_size);
}

void ws2812b_refresh(void) {

	for (int i = 0; i < NUMBER_OF_LEDS; i++) {
		for (int j = 0; j < 24; j++) {
			if (LEDS[i] & 1 << (23 - j)) {
				buffor[RESET_TIME + j + (i * 24)] = BIT_HIGH;
			} else {
				buffor[RESET_TIME + j + (i * 24)] = BIT_LOW;

			}
		}
	}

}

void ws2812b_setHSV(uint8_t ledId, int hue, int sat, int val) {
	/* convert hue, saturation and brightness ( HSB/HSV ) to RGB
	 The dim_curve is used only on brightness/value and on saturation (inverted).
	 This looks the most natural.
	 */

	val = dim_curve[val];
	sat = 255 - dim_curve[255 - sat];

	int r;
	int g;
	int b;
	int base;

	if (sat == 0) { // Acromatic color (gray). Hue doesn't mind.
		LEDS[ledId] = val + (val << 8) + (val << 16);
	} else {

		base = ((255 - sat) * val) >> 8;

		switch (hue / 60) {
		case 0:
			r = val;
			g = (((val - base) * hue) / 60) + base;
			b = base;
			break;

		case 1:
			r = (((val - base) * (60 - (hue % 60))) / 60) + base;
			g = val;
			b = base;
			break;

		case 2:
			r = base;
			g = val;
			b = (((val - base) * (hue % 60)) / 60) + base;
			break;

		case 3:
			r = base;
			g = (((val - base) * (60 - (hue % 60))) / 60) + base;
			b = val;
			break;

		case 4:
			r = (((val - base) * (hue % 60)) / 60) + base;
			g = base;
			b = val;
			break;

		case 5:
			r = val;
			g = base;
			b = (((val - base) * (60 - (hue % 60))) / 60) + base;
			break;
		}

		LEDS[ledId] = b + (r << 8) + (g << 16);
	}
}

void ws2812b_setRgb(uint8_t ledId, int red, int green, int blue){
	LEDS[ledId]=0;
	LEDS[ledId]=(green<<16)+(red<<8)+blue;
}
void ws2812b_setRgbGamma(uint8_t ledId, int red, int green, int blue){
	LEDS[ledId]=0;
	LEDS[ledId]=(dim_curve[green]<<16)+(dim_curve[red]<<8)+dim_curve[blue];
}

void ws2812b_setKelvin(uint8_t ledId, int kelvin, uint8_t Gamma){
	int kelvinId=kelvin/100;
	kelvinId-=10; // kelvinId=0 to 1000K czyli pierwsza wartość w tabeli
	if(kelvinId<0)kelvinId=0;
	if(kelvinId>150)kelvinId=150;
	int g,r,b;
	g=(kelvin_to_RGB[kelvinId]&0x00ff00)>>8;
	r=(kelvin_to_RGB[kelvinId]&0xff0000)>>16;
	b=kelvin_to_RGB[kelvinId]&0x0000ff;
	if(Gamma)ws2812b_setRgbGamma(ledId, r, g, b);
	else ws2812b_setRgb(ledId, r, g, b);


}
