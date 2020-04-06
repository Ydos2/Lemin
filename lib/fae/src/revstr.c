/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Reverse a string
*/

#include "fae.h"

void fae_revstr(char *str)
{
    int length = fae_strlen(str);

    if (length < 2)
        return;
    for (int index = 0; index < length / 2; index++)
        fae_cswap(&str[index], &str[length - index - 1]);
}
