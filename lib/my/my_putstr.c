/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}