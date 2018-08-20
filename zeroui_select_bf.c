#include "zeroui_select_bf.h"
#include <stddef.h>


void zeroui_select_bf_reset(zeroui_select_bf_t *select_bf){
    select_bf->itemcount = 0;
}

void zeroui_select_bf_register(zeroui_select_bf_t *select_bf, zeroui_int_t x, zeroui_int_t y, zeroui_int_t w, zeroui_int_t h, void *ctrl){
    select_bf->itemcount += 1;
    select_bf->bf[select_bf->itemcount-1].x = x;
    select_bf->bf[select_bf->itemcount-1].y = y;
    select_bf->bf[select_bf->itemcount-1].w = w;
    select_bf->bf[select_bf->itemcount-1].h = h;
    select_bf->bf[select_bf->itemcount-1].ctrl = ctrl;
}

void * zeroui_select_bf_pick(zeroui_select_bf_t *select_bf, zeroui_int_t x, zeroui_int_t y){
    for (int i=0; i<select_bf->itemcount; i++){
        int index = select_bf->itemcount - i - 1;
        if (
                (x > select_bf->bf[index].x) &&
                (y > select_bf->bf[index].y) &&
                (x < (select_bf->bf[index].x + select_bf->bf[index].w)) &&
                (y < (select_bf->bf[index].x + select_bf->bf[index].h))
        ){
            return select_bf->bf[index].ctrl;
        }
    }
    return NULL;
}
