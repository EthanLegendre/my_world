/*
** EPITECH PROJECT, 2025
** get_content_file
** File description:
** get_content_file
*/

#include "../../../include/biglib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_content_file(char *file)
{
    FILE *f = fopen(file, "r");
    char *buffer = malloc(sizeof(char) * 1000000);
    char *final = malloc(sizeof(char) * 100000);

    final[0] = '\0';
    while (fgets(buffer, 100000, f)){
        if (strlen(final) + strlen(buffer) + 1 >= 1000000)
            break;
        strcat(final, buffer);
    }
    free(buffer);
    fclose(f);
    return final;
}
