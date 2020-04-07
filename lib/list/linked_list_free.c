/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include <stdlib.h>
#include "linked_list.h"

void list_free_all(linked_list_t **list)
{
    if (*list) {
        if ((*list)->next)
            *list = (*list)->next;
        while ((*list)->next) {
            free((*list)->previous);
            *list = (*list)->next;
        }
        if ((*list)->previous)
            free((*list)->previous);
        free(*list);
    }
    *list = 0;
}

void *list_remove_end(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    void *data = 0;

    if (!tmp)
        return 0;
    while (tmp->next) {
        tmp = tmp->next;
    }
    if (!tmp->previous) {
        *list = 0;
    } else {
        tmp->previous->next = 0;
        data = tmp->data;
    }
    free(tmp);
    return data;
}

void *list_remove_begin(linked_list_t **list)
{
    linked_list_t *tmp = *list;
    void *data = 0;

    *list = (*list)->next;
    if (*list)
        (*list)->previous = 0;
    data = tmp->data;
    free(tmp);
    return data;
}

static void *list_remove_middle(linked_list_t *tmp)
{
    linked_list_t *to_remove = tmp;
    void *data = 0;

    tmp = tmp->previous;
    tmp->next->next->previous = tmp;
    tmp->next = tmp->next->next;
    data = to_remove->data;
    free(to_remove);
    return data;
}

void *list_remove_at(linked_list_t **list, int id)
{
    linked_list_t *tmp = *list;
    void *data = 0;

    if (!(*list))
        return 0;
    if (id <= 0)
        data = list_remove_begin(list);
    else {
        for (int i = 0; i < id && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (!tmp->next) {
            data = list_remove_end(list);
        } else {
            data = list_remove_middle(tmp);
        }
    }
    return data;
}
