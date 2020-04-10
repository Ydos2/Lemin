/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include <stdlib.h>
#include "linked_list.h"

linked_list_t *list_pop_end(linked_list_t **list)
{
    linked_list_t *poped = *list;

    if (!(*list))
        return 0;
    while (poped->next) {
        poped = poped->next;
    }
    if (!poped->previous) {
        *list = 0;
    } else {
        poped->previous->next = 0;
    }
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

linked_list_t *list_pop_begin(linked_list_t **list)
{
    linked_list_t *poped = *list;

    if (!*list)
        return 0;
    if (!(*list)->next) {
        *list = 0;
    } else {
        *list = (*list)->next;
        (*list)->previous = 0;
    }
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

static linked_list_t *list_pop_middle(linked_list_t *tmp)
{
    linked_list_t *poped = tmp;

    tmp = tmp->previous;
    tmp->next->next->previous = tmp;
    tmp->next = tmp->next->next;
    poped->previous = 0;
    poped->next = 0;
    return poped;
}

linked_list_t *list_pop_at(linked_list_t **list, int id)
{
    linked_list_t *poped = *list;

    if (!*list)
        return 0;
    if (id <= 0)
        poped = list_pop_begin(list);
    else {
        for (int i = 0; i < id && poped->next; i++) {
            poped = poped->next;
        }
        if (!poped->next) {
            poped = list_pop_end(list);
        } else {
            poped = list_pop_middle(poped);
        }
    }
    return poped;
}
