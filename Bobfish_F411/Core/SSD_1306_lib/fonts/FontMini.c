
/*******************************************************************************
* font
* filename: unsaved
* name: FontMini
* family: Britannic Bold
* size: 6
* style: Italic
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?\x0040ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
* antialiasing: no
* type: monospaced
* encoding: UTF-16
* unicode bom: no
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Edge 255
* bits per pixel: 1
*
* preprocess:
*  main scan direction: left_to_right
*  line scan direction: backward
*  inverse: yes
*******************************************************************************/

/*
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
*/

/*
#define _FontMini_ 1

#if(_FontMini_ ==1)
extern const tFont FontMini;
#endif
*/

#include <stdint.h>
#include "fonts.h"
#if(_FontMini_ ==1)

static const uint8_t image_data_FontMini_0x0020[3] = { // character: ' '
    0x00,
    0x00,
    0x00};
static const tImage FontMini_0x0020 = {image_data_FontMini_0x0020, 3, 6};

static const uint8_t image_data_FontMini_0x0021[3] = { // character: '!'
    0x00,
    0x5c,
    0x00};
static const tImage FontMini_0x0021 = {image_data_FontMini_0x0021, 3, 6};

static const uint8_t image_data_FontMini_0x0022[3] = { // character: '"'
    0x18,
    0x00,
    0x18};
static const tImage FontMini_0x0022 = {image_data_FontMini_0x0022, 3, 6};

static const uint8_t image_data_FontMini_0x0023[3] = { // character: '#'
    0xf8,
    0x50,
    0xf8};
static const tImage FontMini_0x0023 = {image_data_FontMini_0x0023, 3, 6};

static const uint8_t image_data_FontMini_0x0024[3] = { // character: '$'
    0x48,
    0xfc,
    0x24};
static const tImage FontMini_0x0024 = {image_data_FontMini_0x0024, 3, 6};

static const uint8_t image_data_FontMini_0x0025[3] = { // character: '%'
    0x24,
    0x10,
    0x48};
static const tImage FontMini_0x0025 = {image_data_FontMini_0x0025, 3, 6};

static const uint8_t image_data_FontMini_0x0026[3] = { // character: '&'
    0xf8,
    0xa8,
    0x38};
static const tImage FontMini_0x0026 = {image_data_FontMini_0x0026, 3, 6};

static const uint8_t image_data_FontMini_0x0027[3] = { // character: '''
    0x00,
    0x18,
    0x00};
static const tImage FontMini_0x0027 = {image_data_FontMini_0x0027, 3, 6};

static const uint8_t image_data_FontMini_0x0028[3] = { // character: '('
    0x78,
    0x84,
    0x00};
static const tImage FontMini_0x0028 = {image_data_FontMini_0x0028, 3, 6};

static const uint8_t image_data_FontMini_0x0029[3] = { // character: ')'
    0x00,
    0x84,
    0x78};
static const tImage FontMini_0x0029 = {image_data_FontMini_0x0029, 3, 6};

static const uint8_t image_data_FontMini_0x002a[3] = { // character: '*'
    0x28,
    0x10,
    0x28};
static const tImage FontMini_0x002a = {image_data_FontMini_0x002a, 3, 6};

static const uint8_t image_data_FontMini_0x002b[3] = { // character: '+'
    0x10,
    0x38,
    0x10};
static const tImage FontMini_0x002b = {image_data_FontMini_0x002b, 3, 6};

static const uint8_t image_data_FontMini_0x002c[3] = { // character: ','
    0x80,
    0x40,
    0x00};
static const tImage FontMini_0x002c = {image_data_FontMini_0x002c, 3, 6};

static const uint8_t image_data_FontMini_0x002d[3] = { // character: '-'
    0x10,
    0x10,
    0x10};
static const tImage FontMini_0x002d = {image_data_FontMini_0x002d, 3, 6};

static const uint8_t image_data_FontMini_0x002e[3] = { // character: '.'
    0x00,
    0x40,
    0x00};
static const tImage FontMini_0x002e = {image_data_FontMini_0x002e, 3, 6};

static const uint8_t image_data_FontMini_0x002f[3] = { // character: '/'
    0xc0,
    0x30,
    0x0c};
static const tImage FontMini_0x002f = {image_data_FontMini_0x002f, 3, 6};

static const uint8_t image_data_FontMini_0x0030[3] = { // character: '0'
    0x7c,
    0x44,
    0x7c};
static const tImage FontMini_0x0030 = {image_data_FontMini_0x0030, 3, 6};

static const uint8_t image_data_FontMini_0x0031[3] = { // character: '1'
    0x48,
    0x7c,
    0x40};
static const tImage FontMini_0x0031 = {image_data_FontMini_0x0031, 3, 6};

static const uint8_t image_data_FontMini_0x0032[3] = { // character: '2'
    0x74,
    0x54,
    0x5c};
static const tImage FontMini_0x0032 = {image_data_FontMini_0x0032, 3, 6};

static const uint8_t image_data_FontMini_0x0033[3] = { // character: '3'
    0x44,
    0x54,
    0x7c};
static const tImage FontMini_0x0033 = {image_data_FontMini_0x0033, 3, 6};

static const uint8_t image_data_FontMini_0x0034[3] = { // character: '4'
    0x1c,
    0x10,
    0x7c};
static const tImage FontMini_0x0034 = {image_data_FontMini_0x0034, 3, 6};

static const uint8_t image_data_FontMini_0x0035[3] = { // character: '5'
    0x5c,
    0x54,
    0x74};
static const tImage FontMini_0x0035 = {image_data_FontMini_0x0035, 3, 6};

static const uint8_t image_data_FontMini_0x0036[3] = { // character: '6'
    0x7c,
    0x54,
    0x74};
static const tImage FontMini_0x0036 = {image_data_FontMini_0x0036, 3, 6};

static const uint8_t image_data_FontMini_0x0037[3] = { // character: '7'
    0x04,
    0x74,
    0x0c};
static const tImage FontMini_0x0037 = {image_data_FontMini_0x0037, 3, 6};

static const uint8_t image_data_FontMini_0x0038[3] = { // character: '8'
    0x7c,
    0x54,
    0x7c};
static const tImage FontMini_0x0038 = {image_data_FontMini_0x0038, 3, 6};

static const uint8_t image_data_FontMini_0x0039[3] = { // character: '9'
    0x5c,
    0x54,
    0x7c};
static const tImage FontMini_0x0039 = {image_data_FontMini_0x0039, 3, 6};

static const uint8_t image_data_FontMini_0x003a[3] = { // character: ':'
    0x00,
    0x28,
    0x00};
static const tImage FontMini_0x003a = {image_data_FontMini_0x003a, 3, 6};

static const uint8_t image_data_FontMini_0x003b[3] = { // character: ';'
    0x40,
    0x28,
    0x00};
static const tImage FontMini_0x003b = {image_data_FontMini_0x003b, 3, 6};

static const uint8_t image_data_FontMini_0x003c[3] = { // character: '<'
    0x10,
    0x28,
    0x44};
static const tImage FontMini_0x003c = {image_data_FontMini_0x003c, 3, 6};

static const uint8_t image_data_FontMini_0x003d[3] = { // character: '='
    0x28,
    0x28,
    0x28};
static const tImage FontMini_0x003d = {image_data_FontMini_0x003d, 3, 6};

static const uint8_t image_data_FontMini_0x003e[3] = { // character: '>'
    0x44,
    0x28,
    0x10};
static const tImage FontMini_0x003e = {image_data_FontMini_0x003e, 3, 6};

static const uint8_t image_data_FontMini_0x003f[3] = { // character: '?'
    0x04,
    0x54,
    0x0c};
static const tImage FontMini_0x003f = {image_data_FontMini_0x003f, 3, 6};

static const uint8_t image_data_FontMini_0x0040[3] = { // character: '\x0040'
    0x00,
    0x00,
    0x00};
static const tImage FontMini_0x0040 = {image_data_FontMini_0x0040, 3, 6};

static const uint8_t image_data_FontMini_0x0041[3] = { // character: 'A'
    0x7c,
    0x14,
    0x7c};
static const tImage FontMini_0x0041 = {image_data_FontMini_0x0041, 3, 6};

static const uint8_t image_data_FontMini_0x0042[3] = { // character: 'B'
    0x7c,
    0x54,
    0x28};
static const tImage FontMini_0x0042 = {image_data_FontMini_0x0042, 3, 6};

static const uint8_t image_data_FontMini_0x0043[3] = { // character: 'C'
    0x7c,
    0x44,
    0x44};
static const tImage FontMini_0x0043 = {image_data_FontMini_0x0043, 3, 6};

static const uint8_t image_data_FontMini_0x0044[3] = { // character: 'D'
    0x7c,
    0x44,
    0x38};
static const tImage FontMini_0x0044 = {image_data_FontMini_0x0044, 3, 6};

static const uint8_t image_data_FontMini_0x0045[3] = { // character: 'E'
    0x7c,
    0x54,
    0x44};
static const tImage FontMini_0x0045 = {image_data_FontMini_0x0045, 3, 6};

static const uint8_t image_data_FontMini_0x0046[3] = { // character: 'F'
    0x7c,
    0x14,
    0x04};
static const tImage FontMini_0x0046 = {image_data_FontMini_0x0046, 3, 6};

static const uint8_t image_data_FontMini_0x0047[3] = { // character: 'G'
    0x7c,
    0x44,
    0x74};
static const tImage FontMini_0x0047 = {image_data_FontMini_0x0047, 3, 6};

static const uint8_t image_data_FontMini_0x0048[3] = { // character: 'H'
    0x7c,
    0x10,
    0x7c};
static const tImage FontMini_0x0048 = {image_data_FontMini_0x0048, 3, 6};

static const uint8_t image_data_FontMini_0x0049[3] = { // character: 'I'
    0x00,
    0x7c,
    0x00};
static const tImage FontMini_0x0049 = {image_data_FontMini_0x0049, 3, 6};

static const uint8_t image_data_FontMini_0x004a[3] = { // character: 'J'
    0x40,
    0x3c,
    0x00};
static const tImage FontMini_0x004a = {image_data_FontMini_0x004a, 3, 6};

static const uint8_t image_data_FontMini_0x004b[3] = { // character: 'K'
    0x7c,
    0x10,
    0x6c};
static const tImage FontMini_0x004b = {image_data_FontMini_0x004b, 3, 6};

static const uint8_t image_data_FontMini_0x004c[3] = { // character: 'L'
    0x7c,
    0x40,
    0x40};
static const tImage FontMini_0x004c = {image_data_FontMini_0x004c, 3, 6};

static const uint8_t image_data_FontMini_0x004d[3] = { // character: 'M'
    0x7c,
    0x08,
    0x7c};
static const tImage FontMini_0x004d = {image_data_FontMini_0x004d, 3, 6};

static const uint8_t image_data_FontMini_0x004e[3] = { // character: 'N'
    0x7c,
    0x04,
    0x7c};
static const tImage FontMini_0x004e = {image_data_FontMini_0x004e, 3, 6};

static const uint8_t image_data_FontMini_0x004f[3] = { // character: 'O'
    0x38,
    0x44,
    0x38};
static const tImage FontMini_0x004f = {image_data_FontMini_0x004f, 3, 6};

static const uint8_t image_data_FontMini_0x0050[3] = { // character: 'P'
    0x7c,
    0x14,
    0x1c};
static const tImage FontMini_0x0050 = {image_data_FontMini_0x0050, 3, 6};

static const uint8_t image_data_FontMini_0x0051[3] = { // character: 'Q'
    0x38,
    0x64,
    0x78};
static const tImage FontMini_0x0051 = {image_data_FontMini_0x0051, 3, 6};

static const uint8_t image_data_FontMini_0x0052[3] = { // character: 'R'
    0x7c,
    0x14,
    0x6c};
static const tImage FontMini_0x0052 = {image_data_FontMini_0x0052, 3, 6};

static const uint8_t image_data_FontMini_0x0053[3] = { // character: 'S'
    0x5c,
    0x54,
    0x74};
static const tImage FontMini_0x0053 = {image_data_FontMini_0x0053, 3, 6};

static const uint8_t image_data_FontMini_0x0054[3] = { // character: 'T'
    0x04,
    0x7c,
    0x04};
static const tImage FontMini_0x0054 = {image_data_FontMini_0x0054, 3, 6};

static const uint8_t image_data_FontMini_0x0055[3] = { // character: 'U'
    0x7c,
    0x40,
    0x7c};
static const tImage FontMini_0x0055 = {image_data_FontMini_0x0055, 3, 6};

static const uint8_t image_data_FontMini_0x0056[3] = { // character: 'V'
    0x3c,
    0x40,
    0x3c};
static const tImage FontMini_0x0056 = {image_data_FontMini_0x0056, 3, 6};

static const uint8_t image_data_FontMini_0x0057[3] = { // character: 'W'
    0x7c,
    0x20,
    0x7c};
static const tImage FontMini_0x0057 = {image_data_FontMini_0x0057, 3, 6};

static const uint8_t image_data_FontMini_0x0058[3] = { // character: 'X'
    0x6c,
    0x10,
    0x6c};
static const tImage FontMini_0x0058 = {image_data_FontMini_0x0058, 3, 6};

static const uint8_t image_data_FontMini_0x0059[3] = { // character: 'Y'
    0x0c,
    0x70,
    0x0c};
static const tImage FontMini_0x0059 = {image_data_FontMini_0x0059, 3, 6};

static const uint8_t image_data_FontMini_0x005a[3] = { // character: 'Z'
    0x64,
    0x54,
    0x4c};
static const tImage FontMini_0x005a = {image_data_FontMini_0x005a, 3, 6};

static const uint8_t image_data_FontMini_0x005b[3] = { // character: '['
    0xfc,
    0x84,
    0x00};
static const tImage FontMini_0x005b = {image_data_FontMini_0x005b, 3, 6};

static const uint8_t image_data_FontMini_0x005c[3] = { // character: '\'
    0x0c,
    0x30,
    0xc0};
static const tImage FontMini_0x005c = {image_data_FontMini_0x005c, 3, 6};

static const uint8_t image_data_FontMini_0x005d[3] = { // character: ']'
    0x00,
    0x84,
    0xfc};
static const tImage FontMini_0x005d = {image_data_FontMini_0x005d, 3, 6};

static const uint8_t image_data_FontMini_0x005e[3] = { // character: '^'
    0x08,
    0x04,
    0x08};
static const tImage FontMini_0x005e = {image_data_FontMini_0x005e, 3, 6};

static const uint8_t image_data_FontMini_0x005f[3] = { // character: '_'
    0x80,
    0x80,
    0x80};
static const tImage FontMini_0x005f = {image_data_FontMini_0x005f, 3, 6};

static const uint8_t image_data_FontMini_0x0060[3] = { // character: '`'
    0x00,
    0x04,
    0x08};
static const tImage FontMini_0x0060 = {image_data_FontMini_0x0060, 3, 6};

static const uint8_t image_data_FontMini_0x0061[3] = { // character: 'a'
    0x7c,
    0x14,
    0x7c};
static const tImage FontMini_0x0061 = {image_data_FontMini_0x0061, 3, 6};

static const uint8_t image_data_FontMini_0x0062[3] = { // character: 'b'
    0x7c,
    0x54,
    0x28};
static const tImage FontMini_0x0062 = {image_data_FontMini_0x0062, 3, 6};

static const uint8_t image_data_FontMini_0x0063[3] = { // character: 'c'
    0x7c,
    0x44,
    0x44};
static const tImage FontMini_0x0063 = {image_data_FontMini_0x0063, 3, 6};

static const uint8_t image_data_FontMini_0x0064[3] = { // character: 'd'
    0x7c,
    0x44,
    0x38};
static const tImage FontMini_0x0064 = {image_data_FontMini_0x0064, 3, 6};

static const uint8_t image_data_FontMini_0x0065[3] = { // character: 'e'
    0x7c,
    0x54,
    0x44};
static const tImage FontMini_0x0065 = {image_data_FontMini_0x0065, 3, 6};

static const uint8_t image_data_FontMini_0x0066[3] = { // character: 'f'
    0x7c,
    0x14,
    0x04};
static const tImage FontMini_0x0066 = {image_data_FontMini_0x0066, 3, 6};

static const uint8_t image_data_FontMini_0x0067[3] = { // character: 'g'
    0x7c,
    0x44,
    0x74};
static const tImage FontMini_0x0067 = {image_data_FontMini_0x0067, 3, 6};

static const uint8_t image_data_FontMini_0x0068[3] = { // character: 'h'
    0x7c,
    0x10,
    0x7c};
static const tImage FontMini_0x0068 = {image_data_FontMini_0x0068, 3, 6};

static const uint8_t image_data_FontMini_0x0069[3] = { // character: 'i'
    0x00,
    0x7c,
    0x00};
static const tImage FontMini_0x0069 = {image_data_FontMini_0x0069, 3, 6};

static const uint8_t image_data_FontMini_0x006a[3] = { // character: 'j'
    0x40,
    0x3c,
    0x00};
static const tImage FontMini_0x006a = {image_data_FontMini_0x006a, 3, 6};

static const uint8_t image_data_FontMini_0x006b[3] = { // character: 'k'
    0x7c,
    0x10,
    0x6c};
static const tImage FontMini_0x006b = {image_data_FontMini_0x006b, 3, 6};

static const uint8_t image_data_FontMini_0x006c[3] = { // character: 'l'
    0x7c,
    0x40,
    0x40};
static const tImage FontMini_0x006c = {image_data_FontMini_0x006c, 3, 6};

static const uint8_t image_data_FontMini_0x006d[3] = { // character: 'm'
    0x7c,
    0x08,
    0x7c};
static const tImage FontMini_0x006d = {image_data_FontMini_0x006d, 3, 6};

static const uint8_t image_data_FontMini_0x006e[3] = { // character: 'n'
    0x7c,
    0x04,
    0x7c};
static const tImage FontMini_0x006e = {image_data_FontMini_0x006e, 3, 6};

static const uint8_t image_data_FontMini_0x006f[3] = { // character: 'o'
    0x38,
    0x44,
    0x38};
static const tImage FontMini_0x006f = {image_data_FontMini_0x006f, 3, 6};

static const uint8_t image_data_FontMini_0x0070[3] = { // character: 'p'
    0x7c,
    0x14,
    0x1c};
static const tImage FontMini_0x0070 = {image_data_FontMini_0x0070, 3, 6};

static const uint8_t image_data_FontMini_0x0071[3] = { // character: 'q'
    0x38,
    0x64,
    0x78};
static const tImage FontMini_0x0071 = {image_data_FontMini_0x0071, 3, 6};

static const uint8_t image_data_FontMini_0x0072[3] = { // character: 'r'
    0x7c,
    0x14,
    0x6c};
static const tImage FontMini_0x0072 = {image_data_FontMini_0x0072, 3, 6};

static const uint8_t image_data_FontMini_0x0073[3] = { // character: 's'
    0x5c,
    0x54,
    0x74};
static const tImage FontMini_0x0073 = {image_data_FontMini_0x0073, 3, 6};

static const uint8_t image_data_FontMini_0x0074[3] = { // character: 't'
    0x04,
    0x7c,
    0x04};
static const tImage FontMini_0x0074 = {image_data_FontMini_0x0074, 3, 6};

static const uint8_t image_data_FontMini_0x0075[3] = { // character: 'u'
    0x7c,
    0x40,
    0x7c};
static const tImage FontMini_0x0075 = {image_data_FontMini_0x0075, 3, 6};

static const uint8_t image_data_FontMini_0x0076[3] = { // character: 'v'
    0x3c,
    0x40,
    0x3c};
static const tImage FontMini_0x0076 = {image_data_FontMini_0x0076, 3, 6};

static const uint8_t image_data_FontMini_0x0077[3] = { // character: 'w'
    0x7c,
    0x20,
    0x7c};
static const tImage FontMini_0x0077 = {image_data_FontMini_0x0077, 3, 6};

static const uint8_t image_data_FontMini_0x0078[3] = { // character: 'x'
    0x6c,
    0x10,
    0x6c};
static const tImage FontMini_0x0078 = {image_data_FontMini_0x0078, 3, 6};

static const uint8_t image_data_FontMini_0x0079[3] = { // character: 'y'
    0x0c,
    0x70,
    0x0c};
static const tImage FontMini_0x0079 = {image_data_FontMini_0x0079, 3, 6};

static const uint8_t image_data_FontMini_0x007a[3] = { // character: 'z'
    0x64,
    0x54,
    0x4c};
static const tImage FontMini_0x007a = {image_data_FontMini_0x007a, 3, 6};

static const uint8_t image_data_FontMini_0x007b[3] = { // character: '{'
    0x30,
    0xcc,
    0x84};
static const tImage FontMini_0x007b = {image_data_FontMini_0x007b, 3, 6};

static const uint8_t image_data_FontMini_0x007c[3] = { // character: '|'
    0x00,
    0xfc,
    0x00};
static const tImage FontMini_0x007c = {image_data_FontMini_0x007c, 3, 6};

static const uint8_t image_data_FontMini_0x007d[3] = { // character: '}'
    0x84,
    0xcc,
    0x30};
static const tImage FontMini_0x007d = {image_data_FontMini_0x007d, 3, 6};

static const uint8_t image_data_FontMini_0x007e[3] = { // character: '~'
    0x10,
    0x30,
    0x20};
static const tImage FontMini_0x007e = {image_data_FontMini_0x007e, 3, 6};

static const tImage *FontMini_array[95] = {
    &FontMini_0x0020, // character: ' '
    &FontMini_0x0021, // character: '!'
    &FontMini_0x0022, // character: '"'
    &FontMini_0x0023, // character: '#'
    &FontMini_0x0024, // character: '$'
    &FontMini_0x0025, // character: '%'
    &FontMini_0x0026, // character: '&'
    &FontMini_0x0027, // character: '''
    &FontMini_0x0028, // character: '('
    &FontMini_0x0029, // character: ')'
    &FontMini_0x002a, // character: '*'
    &FontMini_0x002b, // character: '+'
    &FontMini_0x002c, // character: ','
    &FontMini_0x002d, // character: '-'
    &FontMini_0x002e, // character: '.'
    &FontMini_0x002f, // character: '/'
    &FontMini_0x0030, // character: '0'
    &FontMini_0x0031, // character: '1'
    &FontMini_0x0032, // character: '2'
    &FontMini_0x0033, // character: '3'
    &FontMini_0x0034, // character: '4'
    &FontMini_0x0035, // character: '5'
    &FontMini_0x0036, // character: '6'
    &FontMini_0x0037, // character: '7'
    &FontMini_0x0038, // character: '8'
    &FontMini_0x0039, // character: '9'
    &FontMini_0x003a, // character: ':'
    &FontMini_0x003b, // character: ';'
    &FontMini_0x003c, // character: '<'
    &FontMini_0x003d, // character: '='
    &FontMini_0x003e, // character: '>'
    &FontMini_0x003f, // character: '?'
    &FontMini_0x0040, // character: '\x0040'
    &FontMini_0x0041, // character: 'A'
    &FontMini_0x0042, // character: 'B'
    &FontMini_0x0043, // character: 'C'
    &FontMini_0x0044, // character: 'D'
    &FontMini_0x0045, // character: 'E'
    &FontMini_0x0046, // character: 'F'
    &FontMini_0x0047, // character: 'G'
    &FontMini_0x0048, // character: 'H'
    &FontMini_0x0049, // character: 'I'
    &FontMini_0x004a, // character: 'J'
    &FontMini_0x004b, // character: 'K'
    &FontMini_0x004c, // character: 'L'
    &FontMini_0x004d, // character: 'M'
    &FontMini_0x004e, // character: 'N'
    &FontMini_0x004f, // character: 'O'
    &FontMini_0x0050, // character: 'P'
    &FontMini_0x0051, // character: 'Q'
    &FontMini_0x0052, // character: 'R'
    &FontMini_0x0053, // character: 'S'
    &FontMini_0x0054, // character: 'T'
    &FontMini_0x0055, // character: 'U'
    &FontMini_0x0056, // character: 'V'
    &FontMini_0x0057, // character: 'W'
    &FontMini_0x0058, // character: 'X'
    &FontMini_0x0059, // character: 'Y'
    &FontMini_0x005a, // character: 'Z'
    &FontMini_0x005b, // character: '['
    &FontMini_0x005c, // character: '\'
    &FontMini_0x005d, // character: ']'
    &FontMini_0x005e, // character: '^'
    &FontMini_0x005f, // character: '_'
    &FontMini_0x0060, // character: '`'
    &FontMini_0x0061, // character: 'a'
    &FontMini_0x0062, // character: 'b'
    &FontMini_0x0063, // character: 'c'
    &FontMini_0x0064, // character: 'd'
    &FontMini_0x0065, // character: 'e'
    &FontMini_0x0066, // character: 'f'
    &FontMini_0x0067, // character: 'g'
    &FontMini_0x0068, // character: 'h'
    &FontMini_0x0069, // character: 'i'
    &FontMini_0x006a, // character: 'j'
    &FontMini_0x006b, // character: 'k'
    &FontMini_0x006c, // character: 'l'
    &FontMini_0x006d, // character: 'm'
    &FontMini_0x006e, // character: 'n'
    &FontMini_0x006f, // character: 'o'
    &FontMini_0x0070, // character: 'p'
    &FontMini_0x0071, // character: 'q'
    &FontMini_0x0072, // character: 'r'
    &FontMini_0x0073, // character: 's'
    &FontMini_0x0074, // character: 't'
    &FontMini_0x0075, // character: 'u'
    &FontMini_0x0076, // character: 'v'
    &FontMini_0x0077, // character: 'w'
    &FontMini_0x0078, // character: 'x'
    &FontMini_0x0079, // character: 'y'
    &FontMini_0x007a, // character: 'z'
    &FontMini_0x007b, // character: '{'
    &FontMini_0x007c, // character: '|'
    &FontMini_0x007d, // character: '}'
    &FontMini_0x007e  // character: '~'
};

const tFont FontMini = {1, 95, FontMini_array};

#endif
