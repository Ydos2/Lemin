/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include <stdlib.h>

char *my_strstr(char *str, char const *find)
{
    int res = 0;
    (void)res;

    for (int i = 0; str[i] != '\0'; i++)
        for (int x = 0, res = i;; x++, i++) {
            if (find[x] == '\0')
                return (&str[res]);
            if (str[i] != find[x] && x > 0) {
                i--;
                break;
            } else if (str[i] != find[x])
                break;
        }
    return (NULL);
}