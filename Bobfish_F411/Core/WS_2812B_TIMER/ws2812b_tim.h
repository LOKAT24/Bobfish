/*
 * ws2812b.h
 *
 *  Created on: 13.03.2019
 *      Author: adamc
 */

#ifndef WS2812B_H_
#define WS2812B_H_


#include "public_include.h"

#define NUMBER_OF_LEDS 60
#define BIT_HIGH 83
#define BIT_LOW 42
#define RESET_TIME 50

uint32_t LEDS[NUMBER_OF_LEDS];

void ws2812b_setHSV(uint8_t ledId, int hue, int sat, int val, int Gamma);
void ws2812b_setRgb(uint8_t ledId, int red, int green, int blue, int Gamma);
void ws2812b_init(TIM_HandleTypeDef *htim, uint32_t Channel);
void ws2812b_setKelvin(uint8_t ledId, int kelvin, int Gamma);
void ws2812b_refresh(void);

void RgbToHsv(allColor_t *color);
void HsvToRgb(allColor_t *color);
void KelvinToRgb(allColor_t *color);

#endif /* WS2812B_H_ */
