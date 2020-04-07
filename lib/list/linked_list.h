/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** include all bsq functions
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *previous;
} linked_list_t;

void list_add_end(linked_list_t **, void *);

void list_add_begin(linked_list_t **, void *);

void list_add_at(linked_list_t **, void *, int);

void list_add_node_end(linked_list_t **, linked_list_t *);

void list_add_node_begin(linked_list_t **, linked_list_t *);

void list_add_node_at(linked_list_t **, linked_list_t *, int);

void *list_remove_at(linked_list_t **, int);

void *list_remove_end(linked_list_t **);

void *list_remove_begin(linked_list_t **);

linked_list_t *list_pop_end(linked_list_t **);

linked_list_t *list_pop_begin(linked_list_t **);

linked_list_t *list_pop_at(linked_list_t **, int);

void list_free_all(linked_list_t **);

void list_transfer_b_to_b(linked_list_t **, linked_list_t **);

void list_transfer_b_to_e(linked_list_t **, linked_list_t **);

void list_transfer_e_to_b(linked_list_t **, linked_list_t **);

void list_transfer_e_to_e(linked_list_t **, linked_list_t **);

void list_itransfer_b_to_e(linked_list_t **);

void list_itransfer_e_to_b(linked_list_t **);

void list_itransfer_at(linked_list_t **, int, int);

void list_transfer_at(linked_list_t **, int, linked_list_t **, int);

void list_swap_b_to_b(linked_list_t **, linked_list_t **);

void list_swap_b_to_e(linked_list_t **, linked_list_t **);

void list_swap_e_to_b(linked_list_t **, linked_list_t **);

void list_swap_e_to_e(linked_list_t **, linked_list_t **);

void list_iswap_extreme(linked_list_t **);

void list_iswap_at(linked_list_t **, int, int);

void list_swap_at(linked_list_t **, int, linked_list_t **, int);

void *list_get_data(linked_list_t *, int);

linked_list_t *list_get(linked_list_t *, int);

int list_get_size(linked_list_t *);

void list_merge(linked_list_t **, linked_list_t **);

void list_merge_at(linked_list_t **, linked_list_t **, int);

#endif
