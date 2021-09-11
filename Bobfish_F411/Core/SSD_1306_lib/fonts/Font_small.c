
/*******************************************************************************
* font
* filename: C:/Users/user/Desktop/Fonts/Font_small.xml
* name: Font_small
* family: Small Fonts
* size: 8
* style: Normal
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?\x0040ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
* antialiasing: no
* type: proportional
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
#define _Font_small_ 1

#if(_Font_small_ ==1)
extern const tFont Font_small;
#endif
*/

#include <stdint.h>
#include "fonts.h"

#if(_Font_small_ ==1)



static const uint8_t image_data_Font_small_0x0020[2] = { // character: ' '
    0x00,
    0x00   };
static const tImage Font_small_0x0020 = { image_data_Font_small_0x0020, 2, 8};

static const uint8_t image_data_Font_small_0x0021[2] = { // character: '!'
    0x00,
    0x2f   };
static const tImage Font_small_0x0021 = { image_data_Font_small_0x0021, 2, 8};

static const uint8_t image_data_Font_small_0x0022[4] = { // character: '"'
    0x00,
    0x03,
    0x00,
    0x03   };
static const tImage Font_small_0x0022 = { image_data_Font_small_0x0022, 4, 8};

static const uint8_t image_data_Font_small_0x0023[6] = { // character: '#'
    0x00,
    0x12,
    0x3f,
    0x12,
    0x3f,
    0x12   };
static const tImage Font_small_0x0023 = { image_data_Font_small_0x0023, 6, 8};

static const uint8_t image_data_Font_small_0x0024[4] = { // character: '$'
    0x00,
    0x26,
    0x7f,
    0x32   };
static const tImage Font_small_0x0024 = { image_data_Font_small_0x0024, 4, 8};

static const uint8_t image_data_Font_small_0x0025[5] = { // character: '%'
    0x00,
    0x13,
    0x0b,
    0x34,
    0x32   };
static const tImage Font_small_0x0025 = { image_data_Font_small_0x0025, 5, 8};

static const uint8_t image_data_Font_small_0x0026[5] = { // character: '&'
    0x00,
    0x1a,
    0x25,
    0x1a,
    0x28   };
static const tImage Font_small_0x0026 = { image_data_Font_small_0x0026, 5, 8};

static const uint8_t image_data_Font_small_0x0027[2] = { // character: '''
    0x00,
    0x03   };
static const tImage Font_small_0x0027 = { image_data_Font_small_0x0027, 2, 8};

static const uint8_t image_data_Font_small_0x0028[3] = { // character: '('
    0x00,
    0x7e,
    0x81   };
static const tImage Font_small_0x0028 = { image_data_Font_small_0x0028, 3, 8};

static const uint8_t image_data_Font_small_0x0029[3] = { // character: ')'
    0x00,
    0x81,
    0x7e   };
static const tImage Font_small_0x0029 = { image_data_Font_small_0x0029, 3, 8};

static const uint8_t image_data_Font_small_0x002a[3] = { // character: '*'
    0x00,
    0x03,
    0x03   };
static const tImage Font_small_0x002a = { image_data_Font_small_0x002a, 3, 8};

static const uint8_t image_data_Font_small_0x002b[4] = { // character: '+'
    0x00,
    0x08,
    0x1c,
    0x08   };
static const tImage Font_small_0x002b = { image_data_Font_small_0x002b, 4, 8};

static const uint8_t image_data_Font_small_0x002c[2] = { // character: ','
    0x00,
    0x60   };
static const tImage Font_small_0x002c = { image_data_Font_small_0x002c, 2, 8};

static const uint8_t image_data_Font_small_0x002d[3] = { // character: '-'
    0x00,
    0x08,
    0x08   };
static const tImage Font_small_0x002d = { image_data_Font_small_0x002d, 3, 8};

static const uint8_t image_data_Font_small_0x002e[2] = { // character: '.'
    0x00,
    0x20   };
static const tImage Font_small_0x002e = { image_data_Font_small_0x002e, 2, 8};

static const uint8_t image_data_Font_small_0x002f[3] = { // character: '/'
    0x00,
    0x38,
    0x07   };
static const tImage Font_small_0x002f = { image_data_Font_small_0x002f, 3, 8};

static const uint8_t image_data_Font_small_0x0030[5] = { // character: '0'
    0x00,
    0x1e,
    0x21,
    0x21,
    0x1e   };
static const tImage Font_small_0x0030 = { image_data_Font_small_0x0030, 5, 8};

static const uint8_t image_data_Font_small_0x0031[3] = { // character: '1'
    0x00,
    0x02,
    0x3f   };
static const tImage Font_small_0x0031 = { image_data_Font_small_0x0031, 3, 8};

static const uint8_t image_data_Font_small_0x0032[5] = { // character: '2'
    0x00,
    0x32,
    0x29,
    0x29,
    0x26   };
static const tImage Font_small_0x0032 = { image_data_Font_small_0x0032, 5, 8};

static const uint8_t image_data_Font_small_0x0033[5] = { // character: '3'
    0x00,
    0x12,
    0x21,
    0x25,
    0x1a   };
static const tImage Font_small_0x0033 = { image_data_Font_small_0x0033, 5, 8};

static const uint8_t image_data_Font_small_0x0034[5] = { // character: '4'
    0x00,
    0x18,
    0x16,
    0x3f,
    0x10   };
static const tImage Font_small_0x0034 = { image_data_Font_small_0x0034, 5, 8};

static const uint8_t image_data_Font_small_0x0035[4] = { // character: '5'
    0x00,
    0x27,
    0x25,
    0x19   };
static const tImage Font_small_0x0035 = { image_data_Font_small_0x0035, 4, 8};

static const uint8_t image_data_Font_small_0x0036[5] = { // character: '6'
    0x00,
    0x1e,
    0x25,
    0x25,
    0x18   };
static const tImage Font_small_0x0036 = { image_data_Font_small_0x0036, 5, 8};

static const uint8_t image_data_Font_small_0x0037[4] = { // character: '7'
    0x00,
    0x01,
    0x3d,
    0x03   };
static const tImage Font_small_0x0037 = { image_data_Font_small_0x0037, 4, 8};

static const uint8_t image_data_Font_small_0x0038[5] = { // character: '8'
    0x00,
    0x1a,
    0x25,
    0x25,
    0x1a   };
static const tImage Font_small_0x0038 = { image_data_Font_small_0x0038, 5, 8};

static const uint8_t image_data_Font_small_0x0039[5] = { // character: '9'
    0x00,
    0x12,
    0x25,
    0x25,
    0x1e   };
static const tImage Font_small_0x0039 = { image_data_Font_small_0x0039, 5, 8};

static const uint8_t image_data_Font_small_0x003a[2] = { // character: ':'
    0x00,
    0x24   };
static const tImage Font_small_0x003a = { image_data_Font_small_0x003a, 2, 8};

static const uint8_t image_data_Font_small_0x003b[2] = { // character: ';'
    0x00,
    0x64   };
static const tImage Font_small_0x003b = { image_data_Font_small_0x003b, 2, 8};

static const uint8_t image_data_Font_small_0x003c[4] = { // character: '<'
    0x00,
    0x08,
    0x14,
    0x22   };
static const tImage Font_small_0x003c = { image_data_Font_small_0x003c, 4, 8};

static const uint8_t image_data_Font_small_0x003d[4] = { // character: '='
    0x00,
    0x14,
    0x14,
    0x14   };
static const tImage Font_small_0x003d = { image_data_Font_small_0x003d, 4, 8};

static const uint8_t image_data_Font_small_0x003e[4] = { // character: '>'
    0x00,
    0x22,
    0x14,
    0x08   };
static const tImage Font_small_0x003e = { image_data_Font_small_0x003e, 4, 8};

static const uint8_t image_data_Font_small_0x003f[5] = { // character: '?'
    0x00,
    0x02,
    0x29,
    0x05,
    0x02   };
static const tImage Font_small_0x003f = { image_data_Font_small_0x003f, 5, 8};

static const uint8_t image_data_Font_small_0x0040[8] = { // character: '\x0040'
    0x00,
    0x1c,
    0x22,
    0x49,
    0x55,
    0x59,
    0x12,
    0x0c   };
static const tImage Font_small_0x0040 = { image_data_Font_small_0x0040, 8, 8};

static const uint8_t image_data_Font_small_0x0041[6] = { // character: 'A'
    0x00,
    0x30,
    0x0c,
    0x0b,
    0x0c,
    0x30   };
static const tImage Font_small_0x0041 = { image_data_Font_small_0x0041, 6, 8};

static const uint8_t image_data_Font_small_0x0042[6] = { // character: 'B'
    0x00,
    0x3f,
    0x25,
    0x25,
    0x25,
    0x1a   };
static const tImage Font_small_0x0042 = { image_data_Font_small_0x0042, 6, 8};

static const uint8_t image_data_Font_small_0x0043[6] = { // character: 'C'
    0x00,
    0x1e,
    0x21,
    0x21,
    0x21,
    0x12   };
static const tImage Font_small_0x0043 = { image_data_Font_small_0x0043, 6, 8};

static const uint8_t image_data_Font_small_0x0044[6] = { // character: 'D'
    0x00,
    0x3f,
    0x21,
    0x21,
    0x21,
    0x1e   };
static const tImage Font_small_0x0044 = { image_data_Font_small_0x0044, 6, 8};

static const uint8_t image_data_Font_small_0x0045[5] = { // character: 'E'
    0x00,
    0x3f,
    0x25,
    0x25,
    0x21   };
static const tImage Font_small_0x0045 = { image_data_Font_small_0x0045, 5, 8};

static const uint8_t image_data_Font_small_0x0046[5] = { // character: 'F'
    0x00,
    0x3f,
    0x05,
    0x05,
    0x01   };
static const tImage Font_small_0x0046 = { image_data_Font_small_0x0046, 5, 8};

static const uint8_t image_data_Font_small_0x0047[6] = { // character: 'G'
    0x00,
    0x1e,
    0x21,
    0x21,
    0x29,
    0x3a   };
static const tImage Font_small_0x0047 = { image_data_Font_small_0x0047, 6, 8};

static const uint8_t image_data_Font_small_0x0048[5] = { // character: 'H'
    0x00,
    0x3f,
    0x04,
    0x04,
    0x3f   };
static const tImage Font_small_0x0048 = { image_data_Font_small_0x0048, 5, 8};

static const uint8_t image_data_Font_small_0x0049[2] = { // character: 'I'
    0x00,
    0x3f   };
static const tImage Font_small_0x0049 = { image_data_Font_small_0x0049, 2, 8};

static const uint8_t image_data_Font_small_0x004a[4] = { // character: 'J'
    0x00,
    0x30,
    0x20,
    0x1f   };
static const tImage Font_small_0x004a = { image_data_Font_small_0x004a, 4, 8};

static const uint8_t image_data_Font_small_0x004b[5] = { // character: 'K'
    0x00,
    0x3f,
    0x0c,
    0x12,
    0x21   };
static const tImage Font_small_0x004b = { image_data_Font_small_0x004b, 5, 8};

static const uint8_t image_data_Font_small_0x004c[4] = { // character: 'L'
    0x00,
    0x3f,
    0x20,
    0x20   };
static const tImage Font_small_0x004c = { image_data_Font_small_0x004c, 4, 8};

static const uint8_t image_data_Font_small_0x004d[8] = { // character: 'M'
    0x00,
    0x3f,
    0x03,
    0x0c,
    0x30,
    0x0c,
    0x03,
    0x3f   };
static const tImage Font_small_0x004d = { image_data_Font_small_0x004d, 8, 8};

static const uint8_t image_data_Font_small_0x004e[6] = { // character: 'N'
    0x00,
    0x3f,
    0x03,
    0x0c,
    0x30,
    0x3f   };
static const tImage Font_small_0x004e = { image_data_Font_small_0x004e, 6, 8};

static const uint8_t image_data_Font_small_0x004f[6] = { // character: 'O'
    0x00,
    0x1e,
    0x21,
    0x21,
    0x21,
    0x1e   };
static const tImage Font_small_0x004f = { image_data_Font_small_0x004f, 6, 8};

static const uint8_t image_data_Font_small_0x0050[5] = { // character: 'P'
    0x00,
    0x3f,
    0x09,
    0x09,
    0x06   };
static const tImage Font_small_0x0050 = { image_data_Font_small_0x0050, 5, 8};

static const uint8_t image_data_Font_small_0x0051[6] = { // character: 'Q'
    0x00,
    0x1e,
    0x21,
    0x29,
    0x11,
    0x2e   };
static const tImage Font_small_0x0051 = { image_data_Font_small_0x0051, 6, 8};

static const uint8_t image_data_Font_small_0x0052[6] = { // character: 'R'
    0x00,
    0x3f,
    0x09,
    0x09,
    0x09,
    0x36   };
static const tImage Font_small_0x0052 = { image_data_Font_small_0x0052, 6, 8};

static const uint8_t image_data_Font_small_0x0053[5] = { // character: 'S'
    0x00,
    0x12,
    0x25,
    0x29,
    0x12   };
static const tImage Font_small_0x0053 = { image_data_Font_small_0x0053, 5, 8};

static const uint8_t image_data_Font_small_0x0054[5] = { // character: 'T'
    0x01,
    0x01,
    0x3f,
    0x01,
    0x01   };
static const tImage Font_small_0x0054 = { image_data_Font_small_0x0054, 5, 8};

static const uint8_t image_data_Font_small_0x0055[6] = { // character: 'U'
    0x00,
    0x1f,
    0x20,
    0x20,
    0x20,
    0x1f   };
static const tImage Font_small_0x0055 = { image_data_Font_small_0x0055, 6, 8};

static const uint8_t image_data_Font_small_0x0056[6] = { // character: 'V'
    0x00,
    0x03,
    0x0c,
    0x30,
    0x0c,
    0x03   };
static const tImage Font_small_0x0056 = { image_data_Font_small_0x0056, 6, 8};

static const uint8_t image_data_Font_small_0x0057[8] = { // character: 'W'
    0x00,
    0x03,
    0x0c,
    0x30,
    0x0c,
    0x30,
    0x0c,
    0x03   };
static const tImage Font_small_0x0057 = { image_data_Font_small_0x0057, 8, 8};

static const uint8_t image_data_Font_small_0x0058[6] = { // character: 'X'
    0x00,
    0x21,
    0x12,
    0x0c,
    0x12,
    0x21   };
static const tImage Font_small_0x0058 = { image_data_Font_small_0x0058, 6, 8};

static const uint8_t image_data_Font_small_0x0059[6] = { // character: 'Y'
    0x00,
    0x01,
    0x02,
    0x3c,
    0x02,
    0x01   };
static const tImage Font_small_0x0059 = { image_data_Font_small_0x0059, 6, 8};

static const uint8_t image_data_Font_small_0x005a[5] = { // character: 'Z'
    0x00,
    0x31,
    0x29,
    0x25,
    0x23   };
static const tImage Font_small_0x005a = { image_data_Font_small_0x005a, 5, 8};

static const uint8_t image_data_Font_small_0x005b[3] = { // character: '['
    0x00,
    0x7f,
    0x41   };
static const tImage Font_small_0x005b = { image_data_Font_small_0x005b, 3, 8};

static const uint8_t image_data_Font_small_0x005c[3] = { // character: '\'
    0x00,
    0x07,
    0x38   };
static const tImage Font_small_0x005c = { image_data_Font_small_0x005c, 3, 8};

static const uint8_t image_data_Font_small_0x005d[3] = { // character: ']'
    0x00,
    0x41,
    0x7f   };
static const tImage Font_small_0x005d = { image_data_Font_small_0x005d, 3, 8};

static const uint8_t image_data_Font_small_0x005e[4] = { // character: '^'
    0x00,
    0x02,
    0x01,
    0x02   };
static const tImage Font_small_0x005e = { image_data_Font_small_0x005e, 4, 8};

static const uint8_t image_data_Font_small_0x005f[5] = { // character: '_'
    0x40,
    0x40,
    0x40,
    0x40,
    0x40   };
static const tImage Font_small_0x005f = { image_data_Font_small_0x005f, 5, 8};

static const uint8_t image_data_Font_small_0x0060[3] = { // character: '`'
    0x00,
    0x01,
    0x02   };
static const tImage Font_small_0x0060 = { image_data_Font_small_0x0060, 3, 8};

static const uint8_t image_data_Font_small_0x0061[4] = { // character: 'a'
    0x00,
    0x14,
    0x24,
    0x38   };
static const tImage Font_small_0x0061 = { image_data_Font_small_0x0061, 4, 8};

static const uint8_t image_data_Font_small_0x0062[5] = { // character: 'b'
    0x00,
    0x3f,
    0x24,
    0x24,
    0x18   };
static const tImage Font_small_0x0062 = { image_data_Font_small_0x0062, 5, 8};

static const uint8_t image_data_Font_small_0x0063[4] = { // character: 'c'
    0x00,
    0x18,
    0x24,
    0x24   };
static const tImage Font_small_0x0063 = { image_data_Font_small_0x0063, 4, 8};

static const uint8_t image_data_Font_small_0x0064[5] = { // character: 'd'
    0x00,
    0x18,
    0x24,
    0x24,
    0x3f   };
static const tImage Font_small_0x0064 = { image_data_Font_small_0x0064, 5, 8};

static const uint8_t image_data_Font_small_0x0065[4] = { // character: 'e'
    0x00,
    0x18,
    0x24,
    0x28   };
static const tImage Font_small_0x0065 = { image_data_Font_small_0x0065, 4, 8};

static const uint8_t image_data_Font_small_0x0066[3] = { // character: 'f'
    0x00,
    0x3e,
    0x05   };
static const tImage Font_small_0x0066 = { image_data_Font_small_0x0066, 3, 8};

static const uint8_t image_data_Font_small_0x0067[5] = { // character: 'g'
    0x00,
    0x18,
    0xa4,
    0xa4,
    0x7c   };
static const tImage Font_small_0x0067 = { image_data_Font_small_0x0067, 5, 8};

static const uint8_t image_data_Font_small_0x0068[4] = { // character: 'h'
    0x00,
    0x3f,
    0x04,
    0x38   };
static const tImage Font_small_0x0068 = { image_data_Font_small_0x0068, 4, 8};

static const uint8_t image_data_Font_small_0x0069[2] = { // character: 'i'
    0x00,
    0x3d   };
static const tImage Font_small_0x0069 = { image_data_Font_small_0x0069, 2, 8};

static const uint8_t image_data_Font_small_0x006a[2] = { // character: 'j'
    0x00,
    0xfd   };
static const tImage Font_small_0x006a = { image_data_Font_small_0x006a, 2, 8};

static const uint8_t image_data_Font_small_0x006b[4] = { // character: 'k'
    0x00,
    0x3f,
    0x08,
    0x34   };
static const tImage Font_small_0x006b = { image_data_Font_small_0x006b, 4, 8};

static const uint8_t image_data_Font_small_0x006c[2] = { // character: 'l'
    0x00,
    0x3f   };
static const tImage Font_small_0x006c = { image_data_Font_small_0x006c, 2, 8};

static const uint8_t image_data_Font_small_0x006d[6] = { // character: 'm'
    0x00,
    0x3c,
    0x04,
    0x3c,
    0x04,
    0x38   };
static const tImage Font_small_0x006d = { image_data_Font_small_0x006d, 6, 8};

static const uint8_t image_data_Font_small_0x006e[4] = { // character: 'n'
    0x00,
    0x3c,
    0x04,
    0x38   };
static const tImage Font_small_0x006e = { image_data_Font_small_0x006e, 4, 8};

static const uint8_t image_data_Font_small_0x006f[5] = { // character: 'o'
    0x00,
    0x18,
    0x24,
    0x24,
    0x18   };
static const tImage Font_small_0x006f = { image_data_Font_small_0x006f, 5, 8};

static const uint8_t image_data_Font_small_0x0070[5] = { // character: 'p'
    0x00,
    0xfc,
    0x24,
    0x24,
    0x18   };
static const tImage Font_small_0x0070 = { image_data_Font_small_0x0070, 5, 8};

static const uint8_t image_data_Font_small_0x0071[5] = { // character: 'q'
    0x00,
    0x18,
    0x24,
    0x24,
    0xfc   };
static const tImage Font_small_0x0071 = { image_data_Font_small_0x0071, 5, 8};

static const uint8_t image_data_Font_small_0x0072[3] = { // character: 'r'
    0x00,
    0x3c,
    0x04   };
static const tImage Font_small_0x0072 = { image_data_Font_small_0x0072, 3, 8};

static const uint8_t image_data_Font_small_0x0073[4] = { // character: 's'
    0x00,
    0x28,
    0x24,
    0x14   };
static const tImage Font_small_0x0073 = { image_data_Font_small_0x0073, 4, 8};

static const uint8_t image_data_Font_small_0x0074[3] = { // character: 't'
    0x00,
    0x1e,
    0x24   };
static const tImage Font_small_0x0074 = { image_data_Font_small_0x0074, 3, 8};

static const uint8_t image_data_Font_small_0x0075[4] = { // character: 'u'
    0x00,
    0x1c,
    0x20,
    0x3c   };
static const tImage Font_small_0x0075 = { image_data_Font_small_0x0075, 4, 8};

static const uint8_t image_data_Font_small_0x0076[4] = { // character: 'v'
    0x00,
    0x0c,
    0x30,
    0x0c   };
static const tImage Font_small_0x0076 = { image_data_Font_small_0x0076, 4, 8};

static const uint8_t image_data_Font_small_0x0077[6] = { // character: 'w'
    0x00,
    0x0c,
    0x30,
    0x0c,
    0x30,
    0x0c   };
static const tImage Font_small_0x0077 = { image_data_Font_small_0x0077, 6, 8};

static const uint8_t image_data_Font_small_0x0078[4] = { // character: 'x'
    0x00,
    0x24,
    0x18,
    0x24   };
static const tImage Font_small_0x0078 = { image_data_Font_small_0x0078, 4, 8};

static const uint8_t image_data_Font_small_0x0079[4] = { // character: 'y'
    0x00,
    0x9c,
    0x60,
    0x1c   };
static const tImage Font_small_0x0079 = { image_data_Font_small_0x0079, 4, 8};

static const uint8_t image_data_Font_small_0x007a[4] = { // character: 'z'
    0x00,
    0x34,
    0x24,
    0x2c   };
static const tImage Font_small_0x007a = { image_data_Font_small_0x007a, 4, 8};

static const uint8_t image_data_Font_small_0x007b[3] = { // character: '{'
    0x00,
    0x08,
    0x77   };
static const tImage Font_small_0x007b = { image_data_Font_small_0x007b, 3, 8};

static const uint8_t image_data_Font_small_0x007c[2] = { // character: '|'
    0x00,
    0x7f   };
static const tImage Font_small_0x007c = { image_data_Font_small_0x007c, 2, 8};

static const uint8_t image_data_Font_small_0x007d[3] = { // character: '}'
    0x00,
    0x77,
    0x08   };
static const tImage Font_small_0x007d = { image_data_Font_small_0x007d, 3, 8};

static const uint8_t image_data_Font_small_0x007e[4] = { // character: '~'
    0x02,
    0x01,
    0x02,
    0x01   };
static const tImage Font_small_0x007e = { image_data_Font_small_0x007e, 4, 8};


static const tImage* Font_small_array[95] = {
&Font_small_0x0020,// character: ' '
&Font_small_0x0021,// character: '!'
&Font_small_0x0022,// character: '"'
&Font_small_0x0023,// character: '#'
&Font_small_0x0024,// character: '$'
&Font_small_0x0025,// character: '%'
&Font_small_0x0026,// character: '&'
&Font_small_0x0027,// character: '''
&Font_small_0x0028,// character: '('
&Font_small_0x0029,// character: ')'
&Font_small_0x002a,// character: '*'
&Font_small_0x002b,// character: '+'
&Font_small_0x002c,// character: ','
&Font_small_0x002d,// character: '-'
&Font_small_0x002e,// character: '.'
&Font_small_0x002f,// character: '/'
&Font_small_0x0030,// character: '0'
&Font_small_0x0031,// character: '1'
&Font_small_0x0032,// character: '2'
&Font_small_0x0033,// character: '3'
&Font_small_0x0034,// character: '4'
&Font_small_0x0035,// character: '5'
&Font_small_0x0036,// character: '6'
&Font_small_0x0037,// character: '7'
&Font_small_0x0038,// character: '8'
&Font_small_0x0039,// character: '9'
&Font_small_0x003a,// character: ':'
&Font_small_0x003b,// character: ';'
&Font_small_0x003c,// character: '<'
&Font_small_0x003d,// character: '='
&Font_small_0x003e,// character: '>'
&Font_small_0x003f,// character: '?'
&Font_small_0x0040,// character: '\x0040'
&Font_small_0x0041,// character: 'A'
&Font_small_0x0042,// character: 'B'
&Font_small_0x0043,// character: 'C'
&Font_small_0x0044,// character: 'D'
&Font_small_0x0045,// character: 'E'
&Font_small_0x0046,// character: 'F'
&Font_small_0x0047,// character: 'G'
&Font_small_0x0048,// character: 'H'
&Font_small_0x0049,// character: 'I'
&Font_small_0x004a,// character: 'J'
&Font_small_0x004b,// character: 'K'
&Font_small_0x004c,// character: 'L'
&Font_small_0x004d,// character: 'M'
&Font_small_0x004e,// character: 'N'
&Font_small_0x004f,// character: 'O'
&Font_small_0x0050,// character: 'P'
&Font_small_0x0051,// character: 'Q'
&Font_small_0x0052,// character: 'R'
&Font_small_0x0053,// character: 'S'
&Font_small_0x0054,// character: 'T'
&Font_small_0x0055,// character: 'U'
&Font_small_0x0056,// character: 'V'
&Font_small_0x0057,// character: 'W'
&Font_small_0x0058,// character: 'X'
&Font_small_0x0059,// character: 'Y'
&Font_small_0x005a,// character: 'Z'
&Font_small_0x005b,// character: '['
&Font_small_0x005c,// character: '\'
&Font_small_0x005d,// character: ']'
&Font_small_0x005e,// character: '^'
&Font_small_0x005f,// character: '_'
&Font_small_0x0060,// character: '`'
&Font_small_0x0061,// character: 'a'
&Font_small_0x0062,// character: 'b'
&Font_small_0x0063,// character: 'c'
&Font_small_0x0064,// character: 'd'
&Font_small_0x0065,// character: 'e'
&Font_small_0x0066,// character: 'f'
&Font_small_0x0067,// character: 'g'
&Font_small_0x0068,// character: 'h'
&Font_small_0x0069,// character: 'i'
&Font_small_0x006a,// character: 'j'
&Font_small_0x006b,// character: 'k'
&Font_small_0x006c,// character: 'l'
&Font_small_0x006d,// character: 'm'
&Font_small_0x006e,// character: 'n'
&Font_small_0x006f,// character: 'o'
&Font_small_0x0070,// character: 'p'
&Font_small_0x0071,// character: 'q'
&Font_small_0x0072,// character: 'r'
&Font_small_0x0073,// character: 's'
&Font_small_0x0074,// character: 't'
&Font_small_0x0075,// character: 'u'
&Font_small_0x0076,// character: 'v'
&Font_small_0x0077,// character: 'w'
&Font_small_0x0078,// character: 'x'
&Font_small_0x0079,// character: 'y'
&Font_small_0x007a,// character: 'z'
&Font_small_0x007b,// character: '{'
&Font_small_0x007c,// character: '|'
&Font_small_0x007d,// character: '}'
&Font_small_0x007e// character: '~'
};


const tFont Font_small = {0, 95, Font_small_array };

#endif
