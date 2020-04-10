/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str == 0)
        return (1);
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        return (0);
    }
    return (1);
}