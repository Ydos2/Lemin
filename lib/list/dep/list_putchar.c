/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** Display a character
*/

#include <unistd.h>

void list_putchar(char c)
{
    write(1, &c, 1);
}
