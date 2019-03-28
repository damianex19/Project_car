/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __MAP_H__
#define __MAP_H__

#include <inttypes.h>

typedef int (*compare_f) (const void *key1, const void *key2 );

typedef struct map_s
{
    uint8_t *map;
    size_t map_cap;
    size_t key_size;
    size_t value_size;
    compare_f compare;
} map_t;

int map_init( map_t *map, size_t key_size, size_t value_size, compare_f compare );
void map_deinit( map_t *map );

int map_insert( map_t *map, void *key, void *value );
int map_remove( map_t *map, void *key );
void *map_find( map_t *map, void *key );

#endif
