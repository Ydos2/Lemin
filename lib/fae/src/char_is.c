/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** check the letter
*/

int fae_char_is_up(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int fae_char_is_low(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int fae_char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int fae_char_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int fae_char_is_alphanum(char c)
{
    if (fae_char_is_alpha(c) || fae_char_is_num(c))
        return 1;
    return 0;
}
