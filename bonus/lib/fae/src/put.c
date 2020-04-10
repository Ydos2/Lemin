/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Display a string
*/

#include <unistd.h>
#include <stdarg.h>
#include "fae.h"

static void infae_put_var(char type, va_list arg)
{
    switch (type) {
        case 'd':
            fae_putnb(va_arg(arg, int), 1);
            break;
        case 'c':
            fae_putchar((char)(va_arg(arg, int)));
            break;
        case 's':
            fae_putstr(va_arg(arg, char *));
            break;
        default:
            fae_putchar(type);
            break;
    }
}

void fae_put(char *str, ...)
{
    va_list arg;
    int len = fae_strlen(str);

    va_start(arg, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            infae_put_var(str[i], arg);
        } else {
            fae_putchar(str[i]);
        }
    }
    va_end(arg);
}

static void infae_err_put_var(char type, va_list arg)
{
    switch (type) {
        case 'd':
            fae_putnb(va_arg(arg, int), 2);
            break;
        case 'c':
            fae_err_putchar((char)(va_arg(arg, int)));
            break;
        case 's':
            fae_err_putstr(va_arg(arg, char *));
            break;
        default:
            fae_err_putchar(type);
            break;
    }
}

void fae_err_put(char *str, ...)
{
    va_list arg;
    int len = fae_strlen(str);

    va_start(arg, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            infae_err_put_var(str[i], arg);
        } else {
            fae_err_putchar(str[i]);
        }
    }
    va_end(arg);
}
