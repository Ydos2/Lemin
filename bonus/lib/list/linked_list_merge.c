/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list merge two lists
*/

#include "linked_list.h"

void list_merge(linked_list_t **target, linked_list_t **to_merge)
{
    linked_list_t *tmp = *target;

    if (!(*to_merge))
        return;
    if (!(*target)) {
        *target = *to_merge;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = *to_merge;
    (*to_merge)->previous = tmp;
}

static void list_merge_between(
    linked_list_t **target,
    linked_list_t **to_merge,
    linked_list_t *first_node,
    linked_list_t *second_node)
{
    linked_list_t *tmp = *to_merge;

    while (tmp->next)
        tmp = tmp->next;
    if (first_node)
        first_node->next = *to_merge;
    else
        *target = *to_merge;
    (*to_merge)->previous = first_node;
    tmp->next = second_node;
    second_node->previous = tmp;
}

void list_merge_at(linked_list_t **target, linked_list_t **to_merge, int index)
{
    linked_list_t *first_node = 0;
    linked_list_t *second_node = *target;
    int i = 0;

    if (!(*target)) {
        *target = *to_merge;
    } else if (*to_merge) {
        for (i = 0; i < index && second_node->next; i++)
            second_node = second_node->next;
        first_node = second_node->previous;
        if (i < index)
            list_merge(target, to_merge);
        else
            list_merge_between(target, to_merge, first_node, second_node);
    }
}
