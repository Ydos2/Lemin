/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list rotation
*/

#include "linked_list.h"

void list_itransfer_b_to_e(linked_list_t **list)
{
    linked_list_t *node = list_pop_begin(list);

    list_add_node_end(list, node);
}

void list_itransfer_e_to_b(linked_list_t **list)
{
    linked_list_t *node = list_pop_end(list);

    list_add_node_begin(list, node);
}

void list_itransfer_at(linked_list_t **list, int src, int target)
{
    linked_list_t *node = 0;

    if (src == target)
        return;
    node = list_pop_at(list, src);
    list_add_node_at(list, node, target);
}
