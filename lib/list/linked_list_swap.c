/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list swap
*/

#include "linked_list.h"

void list_swap_b_to_b(linked_list_t **first, linked_list_t **second)
{
    linked_list_t *node1 = list_pop_begin(first);
    linked_list_t *node2 = list_pop_begin(second);

    list_add_node_begin(second, node1);
    list_add_node_begin(first, node2);
}

void list_swap_b_to_e(linked_list_t **first, linked_list_t **second)
{
    linked_list_t *node1 = list_pop_begin(first);
    linked_list_t *node2 = list_pop_end(second);

    list_add_node_end(second, node1);
    list_add_node_begin(first, node2);
}

void list_swap_e_to_b(linked_list_t **first, linked_list_t **second)
{
    linked_list_t *node1 = list_pop_end(first);
    linked_list_t *node2 = list_pop_begin(second);

    list_add_node_begin(second, node1);
    list_add_node_end(first, node2);
}

void list_swap_e_to_e(linked_list_t **first, linked_list_t **second)
{
    linked_list_t *node1 = list_pop_end(first);
    linked_list_t *node2 = list_pop_end(second);

    list_add_node_end(second, node1);
    list_add_node_end(first, node2);
}

void list_swap_at(linked_list_t **first, int fi, linked_list_t **second, int si)
{
    linked_list_t *node1 = list_pop_at(first, fi);
    linked_list_t *node2 = list_pop_at(second, si);

    list_add_node_at(second, node1, si);
    list_add_node_at(first, node2, fi);
}
