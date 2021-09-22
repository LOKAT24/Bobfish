/*
 * fonts.h
 *
 *  The MIT License.
 *  Created on: 25.05.2017
 *      Author: Mateusz Salamon
 *      www.msalamon.pl
 *      mateusz@msalamon.pl
 */

#ifndef FONTS_FONTS_H_
#define FONTS_FONTS_H_

//
//	Set fonts you want to use
//
#define _FONT_Times_New_Roman_ 1
#define _FontMini_ 0
#define _Font_8x5_ 0
#define _Font_Tahoma_ 0
#define _Font_LED_ 1
#define _Font_small_ 1
#define _Font_kuchen_ 0
#define _Font_Harry_Potter_h48_ 1
#define _Font_Big_1_ 1
#define _Font_3D_ 0
#define _Font_Gothic_7x13_ 0



typedef struct {
     const uint8_t *data;
     uint8_t width;
     uint8_t height;
     } tImage;
typedef struct {
	 uint8_t char_space;
     int length;
     const tImage **image;
     } tFont;

#if(_FONT_Times_New_Roman_ ==1)
extern const tFont Font_Times_New_Roman;
#endif

#if(_FontMini_ ==1)
extern const tFont FontMini;
#endif

#if(_Font_8x5_ ==1)
extern const tFont Font_8x5;
#endif

#if(_Font_Tahoma_ ==1)
extern const tFont Font_Tahoma;
#endif

#if(_Font_LED_ ==1)
extern const tFont Font_LED;
#endif

#if(_Font_small_ ==1)
extern const tFont Font_small;
#endif

#if(_Font_kuchen_ ==1)
extern const tFont Font_kuchen;
#endif

#if(_Font_Harry_Potter_h48_ ==1)
extern const tFont Font_Harry_Potter_h48;
#endif

#if(_Font_Big_1_ ==1)
extern const tFont Font_Big_1;
#endif

#if(_Font_3D_ ==1)
extern const tFont Font_3D;
#endif

#if(_Font_Gothic_7x13_ ==1)
extern const tFont Font_Gothic_7x13;
#endif

#endif /* FONTS_FONTS_H_ */
