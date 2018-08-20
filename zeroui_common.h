#ifndef ZEROUI_COMMON_H
#define ZEROUI_COMMON_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ZEROUI_MAX_SELECT 255

typedef uint16_t zeroui_int_t;

typedef struct _zeroui_rgba_t zeroui_rgba_t; 
struct _zeroui_rgba_t{
    uint8_t r,g,b,a;
};

void zero_rgba_init(zeroui_rgba_t* self);
void zero_rgba_set(zeroui_rgba_t* self, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

typedef uint8_t zeroui_size_policy_t;
#define ZEROUI_SIZE_POLICY_FIXED 0;
#define ZEROUI_SIZE_POLICY_FILL 1;


//typedef uint8_t font;
//#define FONT_8x8;

#ifdef __cplusplus
}
#endif

//typedef uint8_t zeroui_color_t;

#endif