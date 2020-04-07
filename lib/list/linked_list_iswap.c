/*
** EPITECH PROJECT, 2019
** push swap
** File description:
** linked_list swap
*/

#include "linked_list.h"

void list_iswap_extreme(linked_list_t **list)
{
    linked_list_t *node1 = 0;
    linked_list_t *node2 = 0;

    if (!(*list) || !(*list)->next)
        return;
    node1 = list_pop_begin(list);
    node2 = list_pop_end(list);
    list_add_node_end(list, node1);
    list_add_node_begin(list, node2);
}

void list_iswap_at(linked_list_t **list, int first, int second)
{
    linked_list_t *node1 = 0;
    linked_list_t *node2 = 0;
    int order = (first > second ? 1 : 0);

    if (!(*list) || !(*list)->next || first == second)
        return;
    node1 = list_pop_at(list, first);
    if (first < second) {
        node2 = list_pop_at(list, second - 1);
        list_add_node_at(list, node1, second - 1);
    } else {
        node2 = list_pop_at(list, second);
        list_add_node_at(list, node1, second);
    }
    list_add_node_at(list, node2, first);
}
