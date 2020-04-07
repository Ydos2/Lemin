/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** sort an array of int in ascending order
*/

void fae_sort_int(int *first, int *second)
{
    int stock;

    if (*first > *second) {
        stock = *first;
        *first = *second;
        *second = stock;
    }
}

void fae_sort_int_array(int *array, int size)
{
    for (int progress = 0; progress < size - 1; progress++)
        for (int index = 0; index < size - 1; index++)
            fae_sort_int(&array[index], &array[index + 1]);
}
