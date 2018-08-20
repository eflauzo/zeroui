#include "zeroui_list.h"
#include <stddef.h>
#include <stdlib.h>

void zeroui_list_init(zeroui_list_t *list){
    list->head = malloc(sizeof(zeroui_list_element_t));
    list->head->next = NULL;
}
void zeroui_list_append(zeroui_list_t *list, void *data) {
    zeroui_list_element_t *last_element = list->head;
    while (last_element->next != NULL){
        last_element = last_element->next;
    } 
    zeroui_list_element_t *new_element = malloc(sizeof(zeroui_list_element_t));
    new_element->next = NULL;
    new_element->data = data;
    last_element->next = new_element;
}
