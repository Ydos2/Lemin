/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Return the square root
*/

int fae_square_root(int nb)
{
    int answer = 0;

    if (nb < 0)
        return 0;
    for (int sub = 1; sub <= nb; sub += 2) {
        nb -= sub;
        answer++;
    }
    if (nb > 0)
        return 0;
    return answer;
}
