
/*******************************************************************************
* font
* filename: C:/Users/user/Desktop/Fonts/Font_8x5.xml
* name: Font_8x5
* family: MS Gothic
* size: 8
* style: Bold
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
#define _Font_8x5_ 1

#if(_Font_8x5_ ==1)
extern const tFont Font_8x5;
#endif
*/

#include <stdint.h>
#include "fonts.h"

#if(_Font_8x5_ ==1)


static const uint8_t image_data_Font_8x5_0x0020[5] = { // character: ' '
    0x00,
    0x00,
    0x00,
    0x00,
    0x00   };
static const tImage Font_8x5_0x0020 = { image_data_Font_8x5_0x0020, 5, 8};

static const uint8_t image_data_Font_8x5_0x0021[5] = { // character: '!'
    0x00,
    0x00,
    0x5e,
    0x00,
    0x00   };
static const tImage Font_8x5_0x0021 = { image_data_Font_8x5_0x0021, 5, 8};

static const uint8_t image_data_Font_8x5_0x0022[5] = { // character: '"'
    0x00,
    0x06,
    0x00,
    0x06,
    0x00   };
static const tImage Font_8x5_0x0022 = { image_data_Font_8x5_0x0022, 5, 8};

static const uint8_t image_data_Font_8x5_0x0023[5] = { // character: '#'
    0x14,
    0x7f,
    0x14,
    0x7f,
    0x14   };
static const tImage Font_8x5_0x0023 = { image_data_Font_8x5_0x0023, 5, 8};

static const uint8_t image_data_Font_8x5_0x0024[5] = { // character: '$'
    0x24,
    0x2a,
    0x7f,
    0x2a,
    0x12   };
static const tImage Font_8x5_0x0024 = { image_data_Font_8x5_0x0024, 5, 8};

static const uint8_t image_data_Font_8x5_0x0025[5] = { // character: '%'
    0x23,
    0x13,
    0x08,
    0x64,
    0x62   };
static const tImage Font_8x5_0x0025 = { image_data_Font_8x5_0x0025, 5, 8};

static const uint8_t image_data_Font_8x5_0x0026[5] = { // character: '&'
    0x36,
    0x49,
    0x55,
    0x22,
    0x50   };
static const tImage Font_8x5_0x0026 = { image_data_Font_8x5_0x0026, 5, 8};

static const uint8_t image_data_Font_8x5_0x0027[5] = { // character: '''
    0x00,
    0x00,
    0x00,
    0x03,
    0x00   };
static const tImage Font_8x5_0x0027 = { image_data_Font_8x5_0x0027, 5, 8};

static const uint8_t image_data_Font_8x5_0x0028[5] = { // character: '('
    0x00,
    0x00,
    0x1c,
    0x22,
    0x41   };
static const tImage Font_8x5_0x0028 = { image_data_Font_8x5_0x0028, 5, 8};

static const uint8_t image_data_Font_8x5_0x0029[5] = { // character: ')'
    0x41,
    0x22,
    0x1c,
    0x00,
    0x00   };
static const tImage Font_8x5_0x0029 = { image_data_Font_8x5_0x0029, 5, 8};

static const uint8_t image_data_Font_8x5_0x002a[5] = { // character: '*'
    0x14,
    0x08,
    0x3e,
    0x08,
    0x14   };
static const tImage Font_8x5_0x002a = { image_data_Font_8x5_0x002a, 5, 8};

static const uint8_t image_data_Font_8x5_0x002b[5] = { // character: '+'
    0x08,
    0x08,
    0x3e,
    0x08,
    0x08   };
static const tImage Font_8x5_0x002b = { image_data_Font_8x5_0x002b, 5, 8};

static const uint8_t image_data_Font_8x5_0x002c[5] = { // character: ','
    0x00,
    0x00,
    0xa0,
    0x60,
    0x00   };
static const tImage Font_8x5_0x002c = { image_data_Font_8x5_0x002c, 5, 8};

static const uint8_t image_data_Font_8x5_0x002d[5] = { // character: '-'
    0x08,
    0x08,
    0x08,
    0x08,
    0x08   };
static const tImage Font_8x5_0x002d = { image_data_Font_8x5_0x002d, 5, 8};

static const uint8_t image_data_Font_8x5_0x002e[5] = { // character: '.'
    0x00,
    0x00,
    0x60,
    0x60,
    0x00   };
static const tImage Font_8x5_0x002e = { image_data_Font_8x5_0x002e, 5, 8};

static const uint8_t image_data_Font_8x5_0x002f[5] = { // character: '/'
    0x20,
    0x10,
    0x08,
    0x04,
    0x02   };
static const tImage Font_8x5_0x002f = { image_data_Font_8x5_0x002f, 5, 8};

static const uint8_t image_data_Font_8x5_0x0030[5] = { // character: '0'
    0x3e,
    0x51,
    0x49,
    0x45,
    0x3e   };
static const tImage Font_8x5_0x0030 = { image_data_Font_8x5_0x0030, 5, 8};

static const uint8_t image_data_Font_8x5_0x0031[5] = { // character: '1'
    0x00,
    0x42,
    0x7f,
    0x40,
    0x00   };
static const tImage Font_8x5_0x0031 = { image_data_Font_8x5_0x0031, 5, 8};

static const uint8_t image_data_Font_8x5_0x0032[5] = { // character: '2'
    0x42,
    0x61,
    0x51,
    0x49,
    0x46   };
static const tImage Font_8x5_0x0032 = { image_data_Font_8x5_0x0032, 5, 8};

static const uint8_t image_data_Font_8x5_0x0033[5] = { // character: '3'
    0x21,
    0x41,
    0x45,
    0x4b,
    0x31   };
static const tImage Font_8x5_0x0033 = { image_data_Font_8x5_0x0033, 5, 8};

static const uint8_t image_data_Font_8x5_0x0034[5] = { // character: '4'
    0x18,
    0x14,
    0x12,
    0x7f,
    0x10   };
static const tImage Font_8x5_0x0034 = { image_data_Font_8x5_0x0034, 5, 8};

static const uint8_t image_data_Font_8x5_0x0035[5] = { // character: '5'
    0x27,
    0x45,
    0x45,
    0x45,
    0x39   };
static const tImage Font_8x5_0x0035 = { image_data_Font_8x5_0x0035, 5, 8};

static const uint8_t image_data_Font_8x5_0x0036[5] = { // character: '6'
    0x3c,
    0x4a,
    0x49,
    0x49,
    0x30   };
static const tImage Font_8x5_0x0036 = { image_data_Font_8x5_0x0036, 5, 8};

static const uint8_t image_data_Font_8x5_0x0037[5] = { // character: '7'
    0x03,
    0x71,
    0x09,
    0x05,
    0x03   };
static const tImage Font_8x5_0x0037 = { image_data_Font_8x5_0x0037, 5, 8};

static const uint8_t image_data_Font_8x5_0x0038[5] = { // character: '8'
    0x36,
    0x49,
    0x49,
    0x49,
    0x36   };
static const tImage Font_8x5_0x0038 = { image_data_Font_8x5_0x0038, 5, 8};

static const uint8_t image_data_Font_8x5_0x0039[5] = { // character: '9'
    0x06,
    0x49,
    0x49,
    0x29,
    0x1e   };
static const tImage Font_8x5_0x0039 = { image_data_Font_8x5_0x0039, 5, 8};

static const uint8_t image_data_Font_8x5_0x003a[5] = { // character: ':'
    0x00,
    0x00,
    0x66,
    0x66,
    0x00   };
static const tImage Font_8x5_0x003a = { image_data_Font_8x5_0x003a, 5, 8};

static const uint8_t image_data_Font_8x5_0x003b[5] = { // character: ';'
    0x00,
    0x00,
    0x56,
    0x36,
    0x00   };
static const tImage Font_8x5_0x003b = { image_data_Font_8x5_0x003b, 5, 8};

static const uint8_t image_data_Font_8x5_0x003c[5] = { // character: '<'
    0x08,
    0x14,
    0x22,
    0x41,
    0x00   };
static const tImage Font_8x5_0x003c = { image_data_Font_8x5_0x003c, 5, 8};

static const uint8_t image_data_Font_8x5_0x003d[5] = { // character: '='
    0x14,
    0x14,
    0x14,
    0x14,
    0x14   };
static const tImage Font_8x5_0x003d = { image_data_Font_8x5_0x003d, 5, 8};

static const uint8_t image_data_Font_8x5_0x003e[5] = { // character: '>'
    0x00,
    0x41,
    0x22,
    0x14,
    0x08   };
static const tImage Font_8x5_0x003e = { image_data_Font_8x5_0x003e, 5, 8};

static const uint8_t image_data_Font_8x5_0x003f[5] = { // character: '?'
    0x02,
    0x01,
    0x51,
    0x09,
    0x06   };
static const tImage Font_8x5_0x003f = { image_data_Font_8x5_0x003f, 5, 8};

static const uint8_t image_data_Font_8x5_0x0040[5] = { // character: '\x0040'
    0x32,
    0x49,
    0x79,
    0x41,
    0x3e   };
static const tImage Font_8x5_0x0040 = { image_data_Font_8x5_0x0040, 5, 8};

static const uint8_t image_data_Font_8x5_0x0041[5] = { // character: 'A'
    0x7e,
    0x21,
    0x21,
    0x21,
    0x7e   };
static const tImage Font_8x5_0x0041 = { image_data_Font_8x5_0x0041, 5, 8};

static const uint8_t image_data_Font_8x5_0x0042[5] = { // character: 'B'
    0x7f,
    0x49,
    0x49,
    0x49,
    0x36   };
static const tImage Font_8x5_0x0042 = { image_data_Font_8x5_0x0042, 5, 8};

static const uint8_t image_data_Font_8x5_0x0043[5] = { // character: 'C'
    0x3e,
    0x41,
    0x41,
    0x41,
    0x22   };
static const tImage Font_8x5_0x0043 = { image_data_Font_8x5_0x0043, 5, 8};

static const uint8_t image_data_Font_8x5_0x0044[5] = { // character: 'D'
    0x7f,
    0x41,
    0x41,
    0x41,
    0x3e   };
static const tImage Font_8x5_0x0044 = { image_data_Font_8x5_0x0044, 5, 8};

static const uint8_t image_data_Font_8x5_0x0045[5] = { // character: 'E'
    0x7f,
    0x49,
    0x49,
    0x49,
    0x41   };
static const tImage Font_8x5_0x0045 = { image_data_Font_8x5_0x0045, 5, 8};

static const uint8_t image_data_Font_8x5_0x0046[5] = { // character: 'F'
    0x7f,
    0x09,
    0x09,
    0x09,
    0x01   };
static const tImage Font_8x5_0x0046 = { image_data_Font_8x5_0x0046, 5, 8};

static const uint8_t image_data_Font_8x5_0x0047[5] = { // character: 'G'
    0x3e,
    0x41,
    0x49,
    0x49,
    0x7a   };
static const tImage Font_8x5_0x0047 = { image_data_Font_8x5_0x0047, 5, 8};

static const uint8_t image_data_Font_8x5_0x0048[5] = { // character: 'H'
    0x7f,
    0x08,
    0x08,
    0x08,
    0x7f   };
static const tImage Font_8x5_0x0048 = { image_data_Font_8x5_0x0048, 5, 8};

static const uint8_t image_data_Font_8x5_0x0049[5] = { // character: 'I'
    0x00,
    0x41,
    0x7f,
    0x41,
    0x00   };
static const tImage Font_8x5_0x0049 = { image_data_Font_8x5_0x0049, 5, 8};

static const uint8_t image_data_Font_8x5_0x004a[5] = { // character: 'J'
    0x20,
    0x40,
    0x41,
    0x3f,
    0x01   };
static const tImage Font_8x5_0x004a = { image_data_Font_8x5_0x004a, 5, 8};

static const uint8_t image_data_Font_8x5_0x004b[5] = { // character: 'K'
    0x7f,
    0x08,
    0x14,
    0x22,
    0x41   };
static const tImage Font_8x5_0x004b = { image_data_Font_8x5_0x004b, 5, 8};

static const uint8_t image_data_Font_8x5_0x004c[5] = { // character: 'L'
    0x7f,
    0x40,
    0x40,
    0x40,
    0x40   };
static const tImage Font_8x5_0x004c = { image_data_Font_8x5_0x004c, 5, 8};

static const uint8_t image_data_Font_8x5_0x004d[5] = { // character: 'M'
    0x7f,
    0x02,
    0x0c,
    0x02,
    0x7f   };
static const tImage Font_8x5_0x004d = { image_data_Font_8x5_0x004d, 5, 8};

static const uint8_t image_data_Font_8x5_0x004e[5] = { // character: 'N'
    0x7f,
    0x04,
    0x08,
    0x10,
    0x7f   };
static const tImage Font_8x5_0x004e = { image_data_Font_8x5_0x004e, 5, 8};

static const uint8_t image_data_Font_8x5_0x004f[5] = { // character: 'O'
    0x3e,
    0x41,
    0x41,
    0x41,
    0x3e   };
static const tImage Font_8x5_0x004f = { image_data_Font_8x5_0x004f, 5, 8};

static const uint8_t image_data_Font_8x5_0x0050[5] = { // character: 'P'
    0x7f,
    0x09,
    0x09,
    0x09,
    0x06   };
static const tImage Font_8x5_0x0050 = { image_data_Font_8x5_0x0050, 5, 8};

static const uint8_t image_data_Font_8x5_0x0051[5] = { // character: 'Q'
    0x3e,
    0x41,
    0x51,
    0x21,
    0x5e   };
static const tImage Font_8x5_0x0051 = { image_data_Font_8x5_0x0051, 5, 8};

static const uint8_t image_data_Font_8x5_0x0052[5] = { // character: 'R'
    0x7f,
    0x09,
    0x19,
    0x29,
    0x46   };
static const tImage Font_8x5_0x0052 = { image_data_Font_8x5_0x0052, 5, 8};

static const uint8_t image_data_Font_8x5_0x0053[5] = { // character: 'S'
    0x26,
    0x49,
    0x49,
    0x49,
    0x32   };
static const tImage Font_8x5_0x0053 = { image_data_Font_8x5_0x0053, 5, 8};

static const uint8_t image_data_Font_8x5_0x0054[5] = { // character: 'T'
    0x01,
    0x01,
    0x7f,
    0x01,
    0x01   };
static const tImage Font_8x5_0x0054 = { image_data_Font_8x5_0x0054, 5, 8};

static const uint8_t image_data_Font_8x5_0x0055[5] = { // character: 'U'
    0x3f,
    0x40,
    0x40,
    0x40,
    0x3f   };
static const tImage Font_8x5_0x0055 = { image_data_Font_8x5_0x0055, 5, 8};

static const uint8_t image_data_Font_8x5_0x0056[5] = { // character: 'V'
    0x1f,
    0x20,
    0x40,
    0x20,
    0x1f   };
static const tImage Font_8x5_0x0056 = { image_data_Font_8x5_0x0056, 5, 8};

static const uint8_t image_data_Font_8x5_0x0057[5] = { // character: 'W'
    0x3f,
    0x40,
    0x38,
    0x40,
    0x3f   };
static const tImage Font_8x5_0x0057 = { image_data_Font_8x5_0x0057, 5, 8};

static const uint8_t image_data_Font_8x5_0x0058[5] = { // character: 'X'
    0x63,
    0x14,
    0x08,
    0x14,
    0x63   };
static const tImage Font_8x5_0x0058 = { image_data_Font_8x5_0x0058, 5, 8};

static const uint8_t image_data_Font_8x5_0x0059[5] = { // character: 'Y'
    0x07,
    0x08,
    0x70,
    0x08,
    0x07   };
static const tImage Font_8x5_0x0059 = { image_data_Font_8x5_0x0059, 5, 8};

static const uint8_t image_data_Font_8x5_0x005a[5] = { // character: 'Z'
    0x61,
    0x51,
    0x49,
    0x45,
    0x43   };
static const tImage Font_8x5_0x005a = { image_data_Font_8x5_0x005a, 5, 8};

static const uint8_t image_data_Font_8x5_0x005b[5] = { // character: '['
    0x00,
    0x7f,
    0x41,
    0x41,
    0x00   };
static const tImage Font_8x5_0x005b = { image_data_Font_8x5_0x005b, 5, 8};

static const uint8_t image_data_Font_8x5_0x005c[5] = { // character: '\'
    0x02,
    0x04,
    0x08,
    0x10,
    0x20   };
static const tImage Font_8x5_0x005c = { image_data_Font_8x5_0x005c, 5, 8};

static const uint8_t image_data_Font_8x5_0x005d[5] = { // character: ']'
    0x00,
    0x41,
    0x41,
    0x7f,
    0x00   };
static const tImage Font_8x5_0x005d = { image_data_Font_8x5_0x005d, 5, 8};

static const uint8_t image_data_Font_8x5_0x005e[5] = { // character: '^'
    0x04,
    0x02,
    0x01,
    0x02,
    0x04   };
static const tImage Font_8x5_0x005e = { image_data_Font_8x5_0x005e, 5, 8};

static const uint8_t image_data_Font_8x5_0x005f[5] = { // character: '_'
    0x80,
    0x80,
    0x80,
    0x80,
    0x80   };
static const tImage Font_8x5_0x005f = { image_data_Font_8x5_0x005f, 5, 8};

static const uint8_t image_data_Font_8x5_0x0060[5] = { // character: '`'
    0x00,
    0x00,
    0x01,
    0x02,
    0x04   };
static const tImage Font_8x5_0x0060 = { image_data_Font_8x5_0x0060, 5, 8};

static const uint8_t image_data_Font_8x5_0x0061[5] = { // character: 'a'
    0x20,
    0x54,
    0x54,
    0x54,
    0x78   };
static const tImage Font_8x5_0x0061 = { image_data_Font_8x5_0x0061, 5, 8};

static const uint8_t image_data_Font_8x5_0x0062[5] = { // character: 'b'
    0x7f,
    0x48,
    0x44,
    0x44,
    0x38   };
static const tImage Font_8x5_0x0062 = { image_data_Font_8x5_0x0062, 5, 8};

static const uint8_t image_data_Font_8x5_0x0063[5] = { // character: 'c'
    0x38,
    0x44,
    0x44,
    0x44,
    0x20   };
static const tImage Font_8x5_0x0063 = { image_data_Font_8x5_0x0063, 5, 8};

static const uint8_t image_data_Font_8x5_0x0064[5] = { // character: 'd'
    0x38,
    0x44,
    0x44,
    0x48,
    0x7f   };
static const tImage Font_8x5_0x0064 = { image_data_Font_8x5_0x0064, 5, 8};

static const uint8_t image_data_Font_8x5_0x0065[5] = { // character: 'e'
    0x38,
    0x54,
    0x54,
    0x54,
    0x18   };
static const tImage Font_8x5_0x0065 = { image_data_Font_8x5_0x0065, 5, 8};

static const uint8_t image_data_Font_8x5_0x0066[5] = { // character: 'f'
    0x08,
    0x7e,
    0x09,
    0x01,
    0x02   };
static const tImage Font_8x5_0x0066 = { image_data_Font_8x5_0x0066, 5, 8};

static const uint8_t image_data_Font_8x5_0x0067[5] = { // character: 'g'
    0x10,
    0xa8,
    0xa8,
    0xa8,
    0x78   };
static const tImage Font_8x5_0x0067 = { image_data_Font_8x5_0x0067, 5, 8};

static const uint8_t image_data_Font_8x5_0x0068[5] = { // character: 'h'
    0x7f,
    0x08,
    0x04,
    0x04,
    0x78   };
static const tImage Font_8x5_0x0068 = { image_data_Font_8x5_0x0068, 5, 8};

static const uint8_t image_data_Font_8x5_0x0069[5] = { // character: 'i'
    0x00,
    0x48,
    0x7d,
    0x40,
    0x00   };
static const tImage Font_8x5_0x0069 = { image_data_Font_8x5_0x0069, 5, 8};

static const uint8_t image_data_Font_8x5_0x006a[5] = { // character: 'j'
    0x20,
    0x40,
    0x44,
    0x3d,
    0x00   };
static const tImage Font_8x5_0x006a = { image_data_Font_8x5_0x006a, 5, 8};

static const uint8_t image_data_Font_8x5_0x006b[5] = { // character: 'k'
    0x7f,
    0x10,
    0x28,
    0x44,
    0x00   };
static const tImage Font_8x5_0x006b = { image_data_Font_8x5_0x006b, 5, 8};

static const uint8_t image_data_Font_8x5_0x006c[5] = { // character: 'l'
    0x00,
    0x41,
    0x7f,
    0x40,
    0x00   };
static const tImage Font_8x5_0x006c = { image_data_Font_8x5_0x006c, 5, 8};

static const uint8_t image_data_Font_8x5_0x006d[5] = { // character: 'm'
    0x7c,
    0x04,
    0x78,
    0x04,
    0x78   };
static const tImage Font_8x5_0x006d = { image_data_Font_8x5_0x006d, 5, 8};

static const uint8_t image_data_Font_8x5_0x006e[5] = { // character: 'n'
    0x7c,
    0x08,
    0x04,
    0x04,
    0x78   };
static const tImage Font_8x5_0x006e = { image_data_Font_8x5_0x006e, 5, 8};

static const uint8_t image_data_Font_8x5_0x006f[5] = { // character: 'o'
    0x38,
    0x44,
    0x44,
    0x44,
    0x38   };
static const tImage Font_8x5_0x006f = { image_data_Font_8x5_0x006f, 5, 8};

static const uint8_t image_data_Font_8x5_0x0070[5] = { // character: 'p'
    0xf8,
    0x28,
    0x28,
    0x28,
    0x10   };
static const tImage Font_8x5_0x0070 = { image_data_Font_8x5_0x0070, 5, 8};

static const uint8_t image_data_Font_8x5_0x0071[5] = { // character: 'q'
    0x10,
    0x28,
    0x28,
    0x28,
    0xf8   };
static const tImage Font_8x5_0x0071 = { image_data_Font_8x5_0x0071, 5, 8};

static const uint8_t image_data_Font_8x5_0x0072[5] = { // character: 'r'
    0x7c,
    0x08,
    0x04,
    0x04,
    0x08   };
static const tImage Font_8x5_0x0072 = { image_data_Font_8x5_0x0072, 5, 8};

static const uint8_t image_data_Font_8x5_0x0073[5] = { // character: 's'
    0x48,
    0x54,
    0x54,
    0x54,
    0x20   };
static const tImage Font_8x5_0x0073 = { image_data_Font_8x5_0x0073, 5, 8};

static const uint8_t image_data_Font_8x5_0x0074[5] = { // character: 't'
    0x04,
    0x3f,
    0x44,
    0x40,
    0x20   };
static const tImage Font_8x5_0x0074 = { image_data_Font_8x5_0x0074, 5, 8};

static const uint8_t image_data_Font_8x5_0x0075[5] = { // character: 'u'
    0x3c,
    0x40,
    0x40,
    0x20,
    0x7c   };
static const tImage Font_8x5_0x0075 = { image_data_Font_8x5_0x0075, 5, 8};

static const uint8_t image_data_Font_8x5_0x0076[5] = { // character: 'v'
    0x1c,
    0x20,
    0x40,
    0x20,
    0x1c   };
static const tImage Font_8x5_0x0076 = { image_data_Font_8x5_0x0076, 5, 8};

static const uint8_t image_data_Font_8x5_0x0077[5] = { // character: 'w'
    0x3c,
    0x40,
    0x20,
    0x40,
    0x3c   };
static const tImage Font_8x5_0x0077 = { image_data_Font_8x5_0x0077, 5, 8};

static const uint8_t image_data_Font_8x5_0x0078[5] = { // character: 'x'
    0x44,
    0x28,
    0x10,
    0x28,
    0x44   };
static const tImage Font_8x5_0x0078 = { image_data_Font_8x5_0x0078, 5, 8};

static const uint8_t image_data_Font_8x5_0x0079[5] = { // character: 'y'
    0x0c,
    0x50,
    0x50,
    0x50,
    0x3c   };
static const tImage Font_8x5_0x0079 = { image_data_Font_8x5_0x0079, 5, 8};

static const uint8_t image_data_Font_8x5_0x007a[5] = { // character: 'z'
    0x44,
    0x64,
    0x54,
    0x4c,
    0x44   };
static const tImage Font_8x5_0x007a = { image_data_Font_8x5_0x007a, 5, 8};

static const uint8_t image_data_Font_8x5_0x007b[5] = { // character: '{'
    0x00,
    0x08,
    0x36,
    0x41,
    0x00   };
static const tImage Font_8x5_0x007b = { image_data_Font_8x5_0x007b, 5, 8};

static const uint8_t image_data_Font_8x5_0x007c[5] = { // character: '|'
    0x00,
    0x00,
    0x7f,
    0x00,
    0x00   };
static const tImage Font_8x5_0x007c = { image_data_Font_8x5_0x007c, 5, 8};

static const uint8_t image_data_Font_8x5_0x007d[5] = { // character: '}'
    0x00,
    0x41,
    0x36,
    0x08,
    0x00   };
static const tImage Font_8x5_0x007d = { image_data_Font_8x5_0x007d, 5, 8};

static const uint8_t image_data_Font_8x5_0x007e[5] = { // character: '~'
    0x04,
    0x02,
    0x02,
    0x04,
    0x02   };
static const tImage Font_8x5_0x007e = { image_data_Font_8x5_0x007e, 5, 8};


static const tImage* Font_8x5_array[95] = {
&Font_8x5_0x0020,// character: ' '
&Font_8x5_0x0021,// character: '!'
&Font_8x5_0x0022,// character: '"'
&Font_8x5_0x0023,// character: '#'
&Font_8x5_0x0024,// character: '$'
&Font_8x5_0x0025,// character: '%'
&Font_8x5_0x0026,// character: '&'
&Font_8x5_0x0027,// character: '''
&Font_8x5_0x0028,// character: '('
&Font_8x5_0x0029,// character: ')'
&Font_8x5_0x002a,// character: '*'
&Font_8x5_0x002b,// character: '+'
&Font_8x5_0x002c,// character: ','
&Font_8x5_0x002d,// character: '-'
&Font_8x5_0x002e,// character: '.'
&Font_8x5_0x002f,// character: '/'
&Font_8x5_0x0030,// character: '0'
&Font_8x5_0x0031,// character: '1'
&Font_8x5_0x0032,// character: '2'
&Font_8x5_0x0033,// character: '3'
&Font_8x5_0x0034,// character: '4'
&Font_8x5_0x0035,// character: '5'
&Font_8x5_0x0036,// character: '6'
&Font_8x5_0x0037,// character: '7'
&Font_8x5_0x0038,// character: '8'
&Font_8x5_0x0039,// character: '9'
&Font_8x5_0x003a,// character: ':'
&Font_8x5_0x003b,// character: ';'
&Font_8x5_0x003c,// character: '<'
&Font_8x5_0x003d,// character: '='
&Font_8x5_0x003e,// character: '>'
&Font_8x5_0x003f,// character: '?'
&Font_8x5_0x0040,// character: '\x0040'
&Font_8x5_0x0041,// character: 'A'
&Font_8x5_0x0042,// character: 'B'
&Font_8x5_0x0043,// character: 'C'
&Font_8x5_0x0044,// character: 'D'
&Font_8x5_0x0045,// character: 'E'
&Font_8x5_0x0046,// character: 'F'
&Font_8x5_0x0047,// character: 'G'
&Font_8x5_0x0048,// character: 'H'
&Font_8x5_0x0049,// character: 'I'
&Font_8x5_0x004a,// character: 'J'
&Font_8x5_0x004b,// character: 'K'
&Font_8x5_0x004c,// character: 'L'
&Font_8x5_0x004d,// character: 'M'
&Font_8x5_0x004e,// character: 'N'
&Font_8x5_0x004f,// character: 'O'
&Font_8x5_0x0050,// character: 'P'
&Font_8x5_0x0051,// character: 'Q'
&Font_8x5_0x0052,// character: 'R'
&Font_8x5_0x0053,// character: 'S'
&Font_8x5_0x0054,// character: 'T'
&Font_8x5_0x0055,// character: 'U'
&Font_8x5_0x0056,// character: 'V'
&Font_8x5_0x0057,// character: 'W'
&Font_8x5_0x0058,// character: 'X'
&Font_8x5_0x0059,// character: 'Y'
&Font_8x5_0x005a,// character: 'Z'
&Font_8x5_0x005b,// character: '['
&Font_8x5_0x005c,// character: '\'
&Font_8x5_0x005d,// character: ']'
&Font_8x5_0x005e,// character: '^'
&Font_8x5_0x005f,// character: '_'
&Font_8x5_0x0060,// character: '`'
&Font_8x5_0x0061,// character: 'a'
&Font_8x5_0x0062,// character: 'b'
&Font_8x5_0x0063,// character: 'c'
&Font_8x5_0x0064,// character: 'd'
&Font_8x5_0x0065,// character: 'e'
&Font_8x5_0x0066,// character: 'f'
&Font_8x5_0x0067,// character: 'g'
&Font_8x5_0x0068,// character: 'h'
&Font_8x5_0x0069,// character: 'i'
&Font_8x5_0x006a,// character: 'j'
&Font_8x5_0x006b,// character: 'k'
&Font_8x5_0x006c,// character: 'l'
&Font_8x5_0x006d,// character: 'm'
&Font_8x5_0x006e,// character: 'n'
&Font_8x5_0x006f,// character: 'o'
&Font_8x5_0x0070,// character: 'p'
&Font_8x5_0x0071,// character: 'q'
&Font_8x5_0x0072,// character: 'r'
&Font_8x5_0x0073,// character: 's'
&Font_8x5_0x0074,// character: 't'
&Font_8x5_0x0075,// character: 'u'
&Font_8x5_0x0076,// character: 'v'
&Font_8x5_0x0077,// character: 'w'
&Font_8x5_0x0078,// character: 'x'
&Font_8x5_0x0079,// character: 'y'
&Font_8x5_0x007a,// character: 'z'
&Font_8x5_0x007b,// character: '{'
&Font_8x5_0x007c,// character: '|'
&Font_8x5_0x007d,// character: '}'
&Font_8x5_0x007e// character: '~'
};


const tFont Font_8x5 = {0, 95, Font_8x5_array };

#endif
