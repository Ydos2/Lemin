/*
** EPITECH PROJECT, 2019
** liblist
** File description:
** linked_list get length
*/

#include <stdlib.h>
#include "linked_list.h"

int list_get_size(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int size = 0;

    if (!list)
        return 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}
