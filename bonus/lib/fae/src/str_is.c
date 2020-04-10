/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Return 1 if is uppercase
*/

int fae_str_is_up(char const *str, char parser)
{
    for (int c = 0; str[c] != '\0'; c++)
        if (!(str[c] >= 'A' && str[c] <= 'Z') && str[c] != parser)
            return 0;
    return 1;
}

int fae_str_is_low(char const *str, char parser)
{
    for (int c = 0; str[c] != '\0'; c++)
        if (!(str[c] >= 'a' && str[c] <= 'z') && str[c] != parser)
            return 0;
    return 1;
}

int fae_str_is_num(char const *str, char parser)
{
    for (int c = 0; str[c] != '\0'; c++)
        if (!(str[c] >= '0' && str[c] <= '9') && str[c] != parser)
            return 0;
    return 1;
}

int fae_str_is_alpha(char const *str, char parser)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] != parser
            && !(str[c] >= 'a' && str[c] <= 'z')
            && !(str[c] >= 'A' && str[c] <= 'Z'))
            return 0;
    }
    return 1;
}

int fae_str_is_alphanum(char const *str, char parser)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (!(str[c] >= '0' && str[c] <= '9')
            && str[c] != parser
            && !(str[c] >= 'a' && str[c] <= 'z')
            && !(str[c] >= 'A' && str[c] <= 'Z'))
            return 0;
    }
    return 1;
}
