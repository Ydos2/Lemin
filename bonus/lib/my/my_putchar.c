/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}