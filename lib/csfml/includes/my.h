/*
** EPITECH PROJECT, 2025
** my_putchar.h
** File description:
** Header for my_putchar.c
*/

#ifndef _LIBMY_H_
    #define _LIBMY_H_

    #include <unistd.h>
    #include <stdlib.h>

int my_showmem(char const *, int);
int my_showstr(char const *str, int size);
char *concat_params(int argc, char **argv);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
int my_show_word_array(char *const *tab);
void my_sort_int_array(int *array, int size);
int my_sort_word_array(char **tab);
char **my_str_to_word_array(char const *str, char delim);
int my_advanced_sort_word_array(char **tab, int (*cmp)
    (const char *, const char *));
void my_putchar(char c);
int my_putstr(char const *str);
int my_puterror(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strrev(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
char *my_char_to_str(char c);
int my_getnbr(char const *str);
char *my_nbr_to_str(long nb);
char *my_double_to_str(double nb);
char *my_float_to_str(double nb, int precision);
char *convert_base(const char *nbr, const char *base_from, const char *base_to);
char *my_unsigned_nbr_to_str(unsigned int nb);
char *my_long_nbr_to_str(long int nb);
char *my_long_long_nbr_to_str(long long int nb);
char *my_short_nbr_to_str(short int nb);
char *my_unsigned_char_to_str(unsigned char nb);
char *my_unsigned_short_nbr_to_str(unsigned short int nb);
long str_to_long(const char *nbr, const char *base_from);
char *long_to_str_base(long nbr, const char *base_to);
char *my_strchr(char *buf, const char c);
int my_str_tab_len(char **tab);

#endif
