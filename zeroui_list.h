#ifndef ZEROUI_LIST_H
#define ZEROUI_LIST_H

#include "zeroui_common.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct zeroui_list_element_t_ zeroui_list_element_t; 
struct zeroui_list_element_t_ {
    void *data;
    zeroui_list_element_t *next;
};

typedef struct zeroui_list_t_ zeroui_list_t; 
struct zeroui_list_t_ {
    zeroui_list_element_t *head;
};


void zeroui_list_init(zeroui_list_t *list);
void zeroui_list_append(zeroui_list_t *list, void *data);


#ifdef __cplusplus
}
#endif

#endif