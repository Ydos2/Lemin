/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list
*/

#include "linked_list.h"

void list_transfer_b_to_b(linked_list_t **src, linked_list_t **target)
{
    linked_list_t *node = list_pop_begin(src);

    list_add_node_begin(target, node);
}

void list_transfer_b_to_e(linked_list_t **src, linked_list_t **target)
{
    linked_list_t *node = list_pop_begin(src);

    list_add_node_end(target, node);
}

void list_transfer_e_to_b(linked_list_t **src, linked_list_t **target)
{
    linked_list_t *node = list_pop_end(src);

    list_add_node_begin(target, node);
}

void list_transfer_e_to_e(linked_list_t **src, linked_list_t **target)
{
    linked_list_t *node = list_pop_end(src);

    list_add_node_end(target, node);
}

void list_transfer_at(linked_list_t **src, int si, linked_list_t **tar, int ti)
{
    linked_list_t *node = list_pop_at(src, si);

    list_add_node_at(tar, node, ti);
}
