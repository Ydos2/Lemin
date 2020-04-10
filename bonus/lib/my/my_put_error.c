/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_put_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
