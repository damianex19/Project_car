/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#include <string.h>
#include <stdlib.h>

#include "map.h"

#define MAP_INCREASE 2
#define MAP_ITERATOR (sizeof(uint8_t) + map->key_size + map->value_size)

/*  --------------------- ---------------- --------------------
 * | USED_FLAG (uint8_t) | KEY (key_size) | VALUE (value_size) |
 *  --------------------- ---------------- --------------------
 */

#define MAP_USE_OFFSET 0
#define MAP_KEY_OFFSET (MAP_USE_OFFSET + sizeof(uint8_t))
#define MAP_VALUE_OFFSET (MAP_KEY_OFFSET + map->key_size)

static void *map_find_first_free( map_t *map );

int map_init( map_t *map, size_t key_size, size_t value_size, compare_f compare )
{
    if( map == NULL )
        return -1;

    memset( map, 0, sizeof(map_t) );
    
    map->map = calloc( ( sizeof(uint8_t) + key_size + value_size ), MAP_INCREASE );
    if( map->map == NULL )
        return -2;

    map->map_cap = MAP_INCREASE;
    
    map->key_size = key_size;
    map->value_size = value_size;
    map->compare = compare;

    return 0;
}


void map_deinit( map_t *map )
{
    if( map == NULL )
        return;

    free( map->map );
    
    memset( map, 0, sizeof(map_t) );
}

int map_insert( map_t *map, void *key, void *value )
{
    if( map == NULL )
        return -1;

    if( map_find( map, key ) != NULL )
        return -2;
    
    void *tmp = map_find_first_free( map );
    if( tmp == NULL )
    {
        uint8_t *new_map = realloc( map->map, ( sizeof(uint8_t) + map->key_size + map->value_size ) * (MAP_INCREASE + map->map_cap) );
        if( new_map == NULL )
        {
            return -3;
        }

        memset( new_map + (( sizeof(uint8_t) + map->key_size + map->value_size ) * map->map_cap), 0, ( sizeof(uint8_t) + map->key_size + map->value_size ) * MAP_INCREASE );

        map->map = new_map;
        map->map_cap += MAP_INCREASE;
    
        tmp = map_find_first_free( map );
    }

    *((uint8_t *)tmp) = 1;
    memcpy( (uint8_t *)tmp + MAP_KEY_OFFSET, key, map->key_size );
    memcpy( (uint8_t *)tmp + MAP_VALUE_OFFSET, value, map->value_size );

    return 0;
}

int map_remove( map_t *map, void *key )
{
    if( map == NULL || key == NULL )
        return -1;

    void *tmp = map_find( map, key );
    if( tmp == NULL )
        return -2;

    tmp -= MAP_VALUE_OFFSET;
    *((uint8_t *)tmp) = 0;

    return 0;
}

void *map_find( map_t *map, void *key )
{
    if( map == NULL || key == NULL )
        return NULL;

    for( size_t idx = 0; idx < map->map_cap; ++idx )
    {
        uint8_t *tmp = (uint8_t *)(map->map + idx * (MAP_ITERATOR));
        if( *tmp == 1 )
        {
            tmp += MAP_KEY_OFFSET;
            if( map->compare(tmp, key) == 0)
                return (uint8_t *)(map->map + idx * (MAP_ITERATOR)) + MAP_VALUE_OFFSET;
        }
    }

    return NULL;
}

static void *map_find_first_free( map_t *map )
{
    if( map == NULL )
        return NULL;
    
    for( size_t idx = 0; idx < map->map_cap; ++idx )
    {
        uint8_t *tmp = (uint8_t *)(map->map + idx * (MAP_ITERATOR));
        if( *tmp == 0 )
            return tmp;
    }

    return NULL;
}

