/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** sort an array of int in ascending order
*/

#include "fae.h"

void fae_sort_char(char *first, char *second)
{
    char stock;

    if (*first > *second) {
        stock = *first;
        *first = *second;
        *second = stock;
    }
}

void fae_sort_char_array(char *array)
{
    int len = fae_strlen(array);

    for (int progress = 0; progress < len - 1; progress++)
        for (int index = 0; index < len - 1; index++)
            fae_sort_char(&array[index], &array[index + 1]);
}
