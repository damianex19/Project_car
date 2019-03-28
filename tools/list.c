/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */


#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
typedef struct list_s
{
    void *item;
    struct list_s *next_item;
} list_t;
*/

static list_t * new_item( void );
static list_t * find_tail(list_t *head);
static list_t * find_prev(list_t *head, list_t *current);

list_t * list_create(void)
{
    list_t *head = new_item();
    if( head == NULL )
        return NULL;
    
    head->item = malloc(sizeof(size_t));
    *(size_t *)head->item = 0;
    
    head->next_item = NULL;

    return head;
}

int list_insert(list_t *head, void* data)
{
    list_t *tail, *tmp;

    if( data == NULL )
        return -1;
    
    tail = find_tail(head);

    tmp = new_item();

    if(tmp)
    {
        tmp->item = data;
        tmp->next_item = NULL;
        
        tail->next_item = tmp;

        *((size_t *)head->item) = *((size_t *)head->item) + 1;
        return 0;
    }
    
    return -1;
}

int list_delete(list_t *head, list_t *item)
{
    list_t *prev = head;
    list_t *next = NULL;

    if( item == head )
        return -1;
    
    prev = find_prev( head, item );
    next = item->next_item;
     
    free(item); 
   
    prev->next_item = next;
    
    *((size_t *)head->item) = *((size_t *)head->item) - 1;
    
    return 0;
}

int list_delete_by_item(list_t *head, void *item )
{
    list_foreach( head )
    {
        if( el->item == item )
        {
            list_delete(head, el );
            return 0;
        }
    }
    return -1;
}

int list_is_empty(list_t *head)
{
    if( head->next_item == NULL )
        return 1;
    else
        return 0;
}

void list_destroy(list_t *head)
{
    list_t *tail = find_tail(head);
    list_t *prev = NULL;
    while(tail != head)
    {
        prev = find_prev( head, tail );
        free(tail);
        prev->next_item = NULL;
        tail = find_tail(head);
    }

    free(head->item);
    free(head);
}

static list_t * new_item(void)
{
    list_t *tmp = malloc(sizeof(list_t));
    tmp->item = NULL;
    tmp->next_item = NULL;

    return tmp;
}

static list_t * find_tail(list_t *head)
{
    list_t *tmp = head;

    while(tmp->next_item != NULL)
        tmp = tmp->next_item;

    return tmp;
}

static list_t * find_prev(list_t *head, list_t *current)
{
    list_foreach( head )
    {
        if(el->next_item == current)
            return el;
    }

    return head;
}

