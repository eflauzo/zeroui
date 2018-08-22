#ifndef ZEROUI_MEMPOOL_H
#define ZEROUI_MEMPOOL_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct zeroui_mempool_t_ zeroui_mempool_t;

struct zeroui_mempool_t_ {
};

void *zeroui_mempool_alloc(zeroui_mempool_t *mempool, size_t size);
void zeroui_mempool_free(zeroui_mempool_t *mempool, void *ptr);

#ifdef __cplusplus
}
#endif

#endif