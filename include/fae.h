/*
** EPITECH PROJECT, 2019
** fae.h
** File description:
** include libfae
*/

#ifndef FAE_H_
#define FAE_H_

/*  DISPLAY  */

void fae_putchar(char);

void fae_err_putchar(char);

void fae_sputchar(char, int);

int fae_putstr(char const *);

void fae_err_putstr(char const *);

void fae_putnb(int, int);

void fae_putfloat(float, int);

void fae_putbase(int, char const *);

void fae_put(char *, ...);

void fae_err_put(char *, ...);

/*  CONVERSION  */

int fae_stoi(char const *, char **);

char *fae_itos(int);

/*  STRING  */

int fae_strlen(char const *);

void fae_revstr(char *);

int fae_strcmp(char const *, char const *);

int fae_strncmp(char const *, char const *, int);

int fae_str_is_up(char const *, char);

int fae_str_is_low(char const *, char);

int fae_str_is_num(char const *, char);

int fae_str_is_alpha(char const *, char);

int fae_str_is_alphanum(char const *, char);

void fae_str_up(char *);

void fae_str_low(char *);

/*  CHAR  */

int fae_char_is_up(char);

int fae_char_is_low(char);

int fae_char_is_num(char);

int fae_char_is_alpha(char);

int fae_char_is_alphanum(char);

/*  MATHS  */

int fae_power(int, int);

int fae_square_root(int);

int fae_nblen(int);

/*  ARRAY  */

int fae_arraylen(void **);

/* LOGIC  */

void fae_swap(void **, void **);

void fae_iswap(int *, int *);

void fae_cswap(char *, char *);

void fae_fswap(float *, float *);

/*  SORT  */

void fae_sort_int(int *, int *);

void fae_sort_char(char *, char *);

void fae_sort_str(char **, char **);

void fae_sort_int_array(int *, int);

void fae_sort_char_array(char *);

void fae_sort_str_array(char **);

#endif /*FAE_H*/
