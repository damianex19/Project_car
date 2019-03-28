/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nowacki.jakub@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Jakub Nowacki
 * ----------------------------------------------------------------------------
 */

#ifndef __LIST_H__
#define __LIST_H__

typedef struct list_s
{
    void *item;
    struct list_s *next_item;
} list_t;

#define list_foreach(head) \
    for( list_t *el = head != NULL ? head->next_item : NULL, *nel = el != NULL ? el->next_item : NULL; el; el = nel, nel = nel != NULL ? nel->next_item : NULL )

list_t * list_create(void);
int list_insert(list_t *head, void* data);
int list_delete(list_t *head, list_t *item);
int list_delete_by_item(list_t *head, void *item );
int list_is_empty(list_t *head);
void list_destroy(list_t *head);

#endif
