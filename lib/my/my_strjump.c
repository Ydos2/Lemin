/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my_strjump
*/

int my_strjump(char *str, char c)
{
    int i = 0;

    for (; str[i] && str[i] != c; i++);
    return (i);
}