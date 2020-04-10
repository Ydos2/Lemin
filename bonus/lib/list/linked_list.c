/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include <stdlib.h>
#include "linked_list.h"

void list_add_end(linked_list_t **list, void *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *old_last = 0;

    new->data = data;
    new->next = 0;
    if (!(*list)) {
        new->previous = 0;
        *list = new;
    } else {
        old_last = *list;
        while (old_last->next)
            old_last = old_last->next;
        old_last->next = new;
        new->previous = old_last;
    }
}

void list_add_begin(linked_list_t **list, void *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = data;
    new->previous = 0;
    if (!*list) {
        new->next = 0;
        *list = new;
        return;
    }
    new->next = *list;
    (*list)->previous = new;
    *list = new;
}

void list_add_at(linked_list_t **list, void *data, int index)
{
    linked_list_t *tmp = *list;
    linked_list_t *new = malloc(sizeof(linked_list_t));
    int i = 0;

    if (index <= 0 || !tmp)
        list_add_begin(list, data);
    else {
        new->data = data;
        for (i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (i < index)
            list_add_end(list, data);
        else {
            new->next = tmp;
            new->previous = tmp->previous;
            tmp->previous->next = new;
            tmp->previous = new;
        }
    }
}

void *list_get_data(linked_list_t *list, int index)
{
    linked_list_t *tmp = list;
    void *data = 0;

    if (tmp) {
        for (int i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        data = tmp->data;
    }
    return data;
}

linked_list_t *list_get(linked_list_t *list, int index)
{
    linked_list_t *tmp = list;

    if (index < 0)
        return 0;
    for (int i = 0; i < index && tmp->next && tmp; i++) {
        tmp = tmp->next;
    }
    return tmp;
}
