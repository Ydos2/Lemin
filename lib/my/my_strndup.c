/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include <stdlib.h>

char *my_strndup(char const *src, int nb)
{
    char *str = malloc(sizeof(char) * nb + 1);
    int i = 0;

    while (src[i] != '\0' && i != nb) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}