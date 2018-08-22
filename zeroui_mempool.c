#include "zeroui_mempool.h"
#include <stdlib.h>


void *zeroui_mempool_alloc(zeroui_mempool_t *mempool, size_t size){
    return malloc(size);
}

void zeroui_mempool_free(zeroui_mempool_t *mempool, void *ptr){
    free(ptr);
}
