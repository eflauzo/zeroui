
#ifndef ZEROUI_SELECT_BF_H
#define ZEROUI_SELECT_BF_H

#include "zeroui_common.h"
//#include "zeroui_controls.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zeroui_select_rec_t_ zeroui_select_rec_t; 
struct zeroui_select_rec_t_ {
    zeroui_int_t x;
    zeroui_int_t y;
    zeroui_int_t w;
    zeroui_int_t h;
    void *ctrl;
};


typedef struct zeroui_select_bf_t_ zeroui_select_bf_t; 
struct zeroui_select_bf_t_ {
    zeroui_select_rec_t bf[ZEROUI_MAX_SELECT];
    zeroui_int_t itemcount;
};

void zeroui_select_bf_reset(zeroui_select_bf_t *select_bf);
void zeroui_select_bf_register(zeroui_select_bf_t *select_bf, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h, void *ctrl);
void * zeroui_select_bf_pick(zeroui_select_bf_t *select_bf, zeroui_int_t x, zeroui_int_t y);


#ifdef __cplusplus
}
#endif

#endif