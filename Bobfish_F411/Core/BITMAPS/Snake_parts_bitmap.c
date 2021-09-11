/*
 * Snake_parts_bitmap.c
 *
 *  Created on: 13 kwi 2020
 *      Author: user
 */
#include <stdint.h>
#include <stdlib.h>
#include "bitmaps.h"
#include "binary.h"
//////////////////////////////////////////////////////////////////////
//								HEAD								//
//////////////////////////////////////////////////////////////////////
//RIGHT
static const uint8_t snake_head_bitmap_R[4]={
		B10000000,
		B01100000,
		B11100000,
		B00000000
};
static const tImage snake_head_image_R={ .data=snake_head_bitmap_R, .width=4, .height=4};
//UP
static const uint8_t snake_head_bitmap_U[4]={
		B00000000,
		B01100000,
		B01100000,
		B10100000
};
static const tImage snake_head_image_U={ .data=snake_head_bitmap_U, .width=4, .height=4};
//LEFT
static const uint8_t snake_head_bitmap_L[4]={
		B00010000,
		B01100000,
		B01110000,
		B00000000
};
static const tImage snake_head_image_L={ .data=snake_head_bitmap_L, .width=4, .height=4};
//DOWN
static const uint8_t snake_head_bitmap_D[4]={
		B10100000,
		B01100000,
		B01100000,
		B00000000
};
static const tImage snake_head_image_D={ .data=snake_head_bitmap_D, .width=4, .height=4};

const tImage* snake_head_image[4]={
		&snake_head_image_R,
		&snake_head_image_U,
		&snake_head_image_L,
		&snake_head_image_D
};
//////////////////////////////////////////////////////////////////////
//								BODY								//
//////////////////////////////////////////////////////////////////////
//RIGHT
static const uint8_t snake_body_bitmap_R[4]={
		B00000000,
		B11010000,
		B10110000,
		B00000000
};
static const tImage snake_body_image_R={ .data=snake_body_bitmap_R, .width=4, .height=4};
//UP
static const uint8_t snake_body_bitmap_U[4]={
		B01100000,
		B00100000,
		B01000000,
		B01100000
};
static const tImage snake_body_image_U={ .data=snake_body_bitmap_U, .width=4, .height=4};
//LEFT
static const uint8_t snake_body_bitmap_L[4]={
		B00000000,
		B10110000,
		B11010000,
		B00000000
};
static const tImage snake_body_image_L={ .data=snake_body_bitmap_L, .width=4, .height=4};
//DOWN
static const uint8_t snake_body_bitmap_D[4]={
		B01100000,
		B01000000,
		B00100000,
		B01100000
};
static const tImage snake_body_image_D={ .data=snake_body_bitmap_D, .width=4, .height=4};

const tImage* snake_body_image[4]={
		&snake_body_image_R,
		&snake_body_image_U,
		&snake_body_image_L,
		&snake_body_image_D
};
//////////////////////////////////////////////////////////////////////
//								TAIL								//
//////////////////////////////////////////////////////////////////////

//RIGHT
static const uint8_t snake_tail_bitmap_R[4]={
		B00000000,
		B00110000,
		B11110000,
		B00000000
};
static const tImage snake_tail_image_R={ .data=snake_tail_bitmap_R, .width=4, .height=4};
//UP
static const uint8_t snake_tail_bitmap_U[4]={
		B01100000,
		B01100000,
		B00100000,
		B00100000
};
static const tImage snake_tail_image_U={ .data=snake_tail_bitmap_U, .width=4, .height=4};
//LEFT
static const uint8_t snake_tail_bitmap_L[4]={
		B00000000,
		B11000000,
		B11110000,
		B00000000
};
static const tImage snake_tail_image_L={ .data=snake_tail_bitmap_L, .width=4, .height=4};
//DOWN
static const uint8_t snake_tail_bitmap_D[4]={
		B00100000,
		B00100000,
		B01100000,
		B01100000
};
static const tImage snake_tail_image_D={ .data=snake_tail_bitmap_D, .width=4, .height=4};

const tImage* snake_tail_image[4]={
		&snake_tail_image_R,
		&snake_tail_image_U,
		&snake_tail_image_L,
		&snake_tail_image_D
};
//////////////////////////////////////////////////////////////////////
//							FULL BODY								//
//////////////////////////////////////////////////////////////////////
//RIGHT
static const uint8_t snake_bodyFull_bitmap_R[4]={
		B01100000,
		B11010000,
		B10110000,
		B01100000
};
static const tImage snake_bodyFull_image_R={ .data=snake_bodyFull_bitmap_R, .width=4, .height=4};
//UP
static const uint8_t snake_bodyFull_bitmap_U[4]={
		B01100000,
		B10110000,
		B11010000,
		B01100000
};
static const tImage snake_bodyFull_image_U={ .data=snake_bodyFull_bitmap_U, .width=4, .height=4};
//LEFT
static const uint8_t snake_bodyFull_bitmap_L[4]={
		B01100000,
		B10110000,
		B11010000,
		B01100000
};
static const tImage snake_bodyFull_image_L={ .data=snake_bodyFull_bitmap_L, .width=4, .height=4};
//DOWN
static const uint8_t snake_bodyFull_bitmap_D[4]={
		B01100000,
		B11010000,
		B10110000,
		B01100000
};
static const tImage snake_bodyFull_image_D={ .data=snake_bodyFull_bitmap_D, .width=4, .height=4};

const tImage* snake_bodyFull_image[4]={
		&snake_bodyFull_image_R,
		&snake_bodyFull_image_U,
		&snake_bodyFull_image_L,
		&snake_bodyFull_image_D
};
//////////////////////////////////////////////////////////////////////
//							CORNER								//
//////////////////////////////////////////////////////////////////////
//LEFT UP
static const uint8_t snake_corner_bitmap_LU[4]={
		B00000000,
		B00110000,
		B01010000,
		B01100000
};
static const tImage snake_corner_image_LU={ .data=snake_corner_bitmap_LU, .width=4, .height=4};
//RIGHT UP
static const uint8_t snake_corner_bitmap_RU[4]={
		B00000000,
		B11000000,
		B10100000,
		B01100000
};
static const tImage snake_corner_image_RU={ .data=snake_corner_bitmap_RU, .width=4, .height=4};
//LEFT DOWN
static const uint8_t snake_corner_bitmap_LD[4]={
		B01100000,
		B01010000,
		B00110000,
		B00000000
};
static const tImage snake_corner_image_LD={ .data=snake_corner_bitmap_LD, .width=4, .height=4};
//RIGHT DOWN
static const uint8_t snake_corner_bitmap_RD[4]={
		B01100000,
		B10100000,
		B11000000,
		B00000000
};
static const tImage snake_corner_image_RD={ .data=snake_corner_bitmap_RD, .width=4, .height=4};

const tImage* snake_corner_image[4]={
		&snake_corner_image_LU,
		&snake_corner_image_RU,
		&snake_corner_image_LD,
		&snake_corner_image_RD
};
//////////////////////////////////////////////////////////////////////
//								POINT								//
//////////////////////////////////////////////////////////////////////

static const uint8_t snake_point_bitmap_normal[4]={
		B01000000,
		B10100000,
		B01000000,
		B00000000
};
static const tImage snake_point_image_normal={ .data=snake_point_bitmap_normal, .width=4, .height=4};

const tImage* snake_point_image[4]={&snake_point_image_normal,NULL,NULL,NULL};
