/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

static int is_num_too_fat(const char *str)
{
    long num = 0;
    int i = 0;
    int negat = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            negat = 1;
        else
            num = (num * 10) + (str[i] - 48);
        if (i > 11 && str[0] == '-' || i > 10 && str[0] != '-')
            return (0);
        i++;
    }
    if (negat == 1)
        num = num * -1;
    if (num > 2147483647 || num < -2147483648)
        return (0);
    return (1);
}

static int find_the_num(const char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] < '0' || str[i] > '9') {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            break;
        }
        i++;
    }
    if (str[i] == '\0')
        return (-1);
    return (i);
}

static int get_num_in_string(const char *str, int nb_pos, char *num_str)
{
    int digits = 0;

    if (str[nb_pos] == '-') {
        num_str[0] = '-';
        digits++;
        nb_pos++;
    }
    while (str[nb_pos] >= '0' && str[nb_pos] <= '9' && digits != 13) {
        num_str[digits] = str[nb_pos];
        nb_pos++;
        digits++;
    }
    num_str[digits] = '\0';
    return (1);
}

static int my_atoi(char str[], int is_positive)
{
    int num = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '-')
            num = (num * 10) + (str[i] - 48);
        i++;
    }
    if (is_positive == 0)
        num = num * -1;
    return (num);
}

int my_getnbr(const char *str)
{
    int num = 0;
    char num_str[15];
    int i = find_the_num(str);
    int positive = 1;
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] == '-')
            positive = (positive == 1) ? 0 : 1;
        x++;
    }
    if (i == -1)
        return (0);
    if (!get_num_in_string(str, i, num_str))
        return (0);
    if (!is_num_too_fat(num_str))
        return (0);
    return (my_atoi(num_str, positive));
}