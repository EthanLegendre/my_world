/*
** EPITECH PROJECT, 2025
** my_str_o_word_array_by_chars
** File description:
** my_str_to_word_array_by_chars
*/

#include "../../../include/biglib.h"

int check_is_char(char c, char *chars)
{
    int i = 0;

    while (chars[i]) {
        if (c == chars[i])
            return 1;
        i++;
    }
    return 0;
}

static void increment_indice(char *str, char *chars, int *i)
{
    while (str[*i] && !check_is_char(str[*i], chars))
        (*i)++;
}

int count_tab_word_by_chars(char *str, char *chars)
{
    int i = 0;
    int nbr_tab = 0;

    while (str[i]) {
        while (str[i] && check_is_char(str[i], chars))
            i++;
        if (str[i]) {
            nbr_tab++;
            increment_indice(str, chars, &i);
        }
    }
    return nbr_tab;
}

void end_word(char **word_array, int *k, int *j)
{
    if (*k > 0) {
        word_array[*j][*k] = '\0';
        (*j)++;
        *k = 0;
    }
}

void fix_k(int *k, int *j, char **word_tab)
{
    if (*k > 0) {
        word_tab[*j][*k] = '\0';
        (*j)++;
        *k = 0;
    }
}

static void while_boucle(int *i, char *str, char *chars)
{
    while (str[*i] && check_is_char(str[*i], chars))
        (*i)++;
}

char **my_str_to_word_array_by_chars(char *str, char *chars)
{
    int len = my_str_len(str);
    int nbr_tab = count_tab_word_by_chars(str, chars);
    char **word_tab = mem_alloc_2d_array_str(nbr_tab + 1, 100);
    int j = 0;
    int k = 0;

    for (int i = 0; i < len; i++) {
        if (check_is_char(str[i], chars)) {
            fix_k(&k, &j, word_tab);
            while_boucle(&i, str, chars);
            i--;
            continue;
        }
        word_tab[j][k] = str[i];
        k++;
    }
    fix_k(&k, &j, word_tab);
    word_tab[j] = NULL;
    return word_tab;
}
