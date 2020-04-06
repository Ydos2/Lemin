/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Return power of a number with recursive
*/

int fae_power(int nb, int p)
{
    int answer;
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    answer = nb * fae_power(nb, p - 1);
    return answer;
}
