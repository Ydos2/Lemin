/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str == 0)
        return (1);
    while (str[i] != '\0') {
        if (str[i] >= 32 || str[i] <= 126)
            i++;
        else
            return (0);
    }
    return (1);
}