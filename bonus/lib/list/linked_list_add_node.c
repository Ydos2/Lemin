/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list add node
*/

#include <stdlib.h>
#include "linked_list.h"

void list_add_node_end(linked_list_t **list, linked_list_t *node)
{
    linked_list_t *tmp = *list;

    if (!node)
        return;
    node->next = 0;
    if (!(*list)) {
        node->previous = 0;
        *list = node;
    } else {
        while (tmp->next)
            tmp = tmp->next;
        node->previous = tmp;
        tmp->next = node;
    }
}

void list_add_node_begin(linked_list_t **list, linked_list_t *node)
{
    if (!node)
        return;
    node->previous = 0;
    if (!*list) {
        node->next = 0;
        *list = node;
        return;
    }
    node->next = *list;
    (*list)->previous = node;
    *list = node;
}

void list_add_node_at(linked_list_t **list, linked_list_t *node, int index)
{
    linked_list_t *tmp = *list;
    int i = 0;

    if (!node)
        return;
    if (index <= 0 || !tmp)
        list_add_node_begin(list, node);
    else {
        for (i = 0; i < index && tmp->next; i++) {
            tmp = tmp->next;
        }
        if (i < index)
            list_add_node_end(list, node);
        else {
            node->next = tmp;
            node->previous = tmp->previous;
            tmp->previous->next = node;
            tmp->previous = node;
        }
    }
}
