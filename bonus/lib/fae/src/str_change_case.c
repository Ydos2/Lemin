/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Change lowercase to upercase
*/

void fae_str_up(char *str)
{
    if (!str)
        return;
    for (int c = 0; str[c] != '\0'; c++)
        if (str[c] >= 'a' && str[c] <= 'z')
            str[c] -= 'a' - 'A';
}

void my_str_low(char *str)
{
    if (!str)
        return;
    for (int c = 0; str[c] != '\0'; c++)
        if (str[c] >= 'A' && str[c] <= 'Z')
            str[c] += 'a' - 'A';
}
