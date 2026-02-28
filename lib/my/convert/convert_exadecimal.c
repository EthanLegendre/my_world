/*
** EPITECH PROJECT, 2025
** convert_exadecimal
** File description:
** convert_exadecimal
*/

#include "../../../include/biglib.h"

int len_size(unsigned int n)
{
    int size = 0;

    while (n != 0){
        n = n / 16;
        size += 1;
    }
    return size;
}

char *convert_exadecimal(unsigned int n)
{
    char *hexadecimal;
    int size = len_size(n);

    if (n == 0)
        return "0";
    hexadecimal = malloc(sizeof(char) * (size + 1));
    hexadecimal[size] = '\0';
    for (int i = size - 1; i != -1; i--){
        if ((n % 16) > 9)
            hexadecimal[i] = 'a' + ((n % 16) - 10);
        else
            hexadecimal[i] = (n % 16) + '0';
        n = n / 16;
    }
    return hexadecimal;
}
