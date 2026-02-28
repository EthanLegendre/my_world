/*
** EPITECH PROJECT, 2025
** convert_octal
** File description:
** convert_octal
*/

#include "../../../include/biglib.h"

int convert_octal(int nb)
{
    int octal_result = 0;
    int i = 1;

    while (nb != 0){
        octal_result += (nb % 8) * i;
        nb /= 8;
        i *= 10;
    }
    return octal_result;
}
