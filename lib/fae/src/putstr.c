/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Display a string
*/

#include <unistd.h>

void fae_putstr(char const *str)
{
    int len = 0;

    if (!str)
        return;
    for (; str[len]; len++);
    write(1, str, len);
}

void fae_err_putstr(char const *str)
{
    int len = 0;

    if (!str)
        return;
    for (; str[len]; len++);
    write(2, str, len);
}
