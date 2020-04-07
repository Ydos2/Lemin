/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** swap content of two integers
*/

void fae_swap(void **a, void **b)
{
    void *stock = *a;

    *a = *b;
    *b = stock;
}

void fae_iswap(int *a, int *b)
{
    int stock = *a;

    *a = *b;
    *b = stock;
}

void fae_cswap(char *a, char *b)
{
    char stock = *a;

    *a = *b;
    *b = stock;
}

void fae_fswap(float *a, float *b)
{
    float stock = *a;

    *a = *b;
    *b = stock;
}
