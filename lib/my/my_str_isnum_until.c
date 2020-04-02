/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_str_isnum_until(char const *str, char c)
{
    int i = 0;

    if (str[i] == 0)
        return (0);
    while (str[i] != '\0' && str[i] != c)
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    return (1);
}