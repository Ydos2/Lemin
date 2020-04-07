/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Compare two string
*/

int fae_strcmp(char const *s1, char const *s2)
{
    int c = 0;

    if (!s1 && !s2)
        return 0;
    if (!s1 || !s2)
        return ((!s1) ? -1 : 1);
    for (c = 0; s1[c] == s2[c]; c++)
        if (s1[c] == '\0')
            return 0;
    return s1[c] - s2[c];
}

int fae_strncmp(char const *s1, char const *s2, int n)
{
    int c = 0;

    if (!s1 && !s2)
        return 0;
    if (!s1 || !s2)
        return ((!s1) ? -1 : 1);
    for (c = 0; c < n && s1[c] != '\0' && s2[c] != '\0'; c++) {
        if (s1[c] != s2[c])
            return s1[c] - s2[c];
        if (s1[c] == '\0' && s2[c] == '\0')
            return 0;
    }
    return 0;
}
