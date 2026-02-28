/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../../include/biglib.h"

int count_tab_word(char *str)
{
    int i = 0;
    int len = my_str_len(str);
    int nbr_tab = 0;

    for (; i < len; i++)
        if (str[i] == '/' || str[i] == ',' || str[i] == ' ')
            nbr_tab++;
    return nbr_tab;
}

char **my_str_to_word_array(char *str)
{
    int len = my_str_len(str);
    int nbr_tab = count_tab_word(str);
    char **word_tab;
    int j = 0;
    int k = 0;

    word_tab = mem_alloc_2d_array_str(nbr_tab + 1, 100);
    for (int i = 0; i < len; i++){
        if (str[i] == '/' || str[i] == ',' || str[i] == ' '){
            i++;
            word_tab[j][k] = '\0';
            j++;
            k = 0;
        }
        word_tab[j][k] = str[i];
        k++;
    }
    word_tab[j][k] = '\0';
    word_tab[j + 1] = NULL;
    return word_tab;
}
