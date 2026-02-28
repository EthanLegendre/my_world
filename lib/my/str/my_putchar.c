/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** my_putchar
*/

#include "../../../include/biglib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
