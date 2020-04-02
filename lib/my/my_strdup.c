/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;

    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}