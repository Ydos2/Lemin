/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Display a character
*/

#include <unistd.h>

void fae_putchar(char c)
{
    write(1, &c, 1);
}

void fae_err_putchar(char c)
{
    write(2, &c, 1);
}

void fae_sputchar(char c, int stream)
{
    write(stream, &c, 1);
}
