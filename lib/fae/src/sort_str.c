/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** sort an array of int in ascending order
*/

#include "fae.h"

void fae_sort_str(char **first, char **second)
{
    char *stock;

    if (fae_strcmp(*first, *second) < 0) {
        stock = *first;
        *first = *second;
        *second = stock;
    }
}

void fae_sort_str_array(char **array)
{
    int len = fae_arraylen((void **)(array));

    for (int progress = 0; progress < len - 1; progress++)
        for (int index = 0; index < len - 1; index++)
            fae_sort_str(&array[index], &array[index + 1]);
}
