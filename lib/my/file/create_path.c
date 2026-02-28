/*
** EPITECH PROJECT, 2025
** create_path
** File description:
** create_path
*/

#include "../../../include/biglib.h"

char *create_path(char *name, char *d_name)
{
    char *path = malloc(sizeof(char) * 1000);
    int i;
    int j;
    int len = my_str_len(name);

    for (i = 0; i < my_str_len(name); i++)
        path[i] = name[i];
    if (i > 0 && name[len - 1] != '/'){
        path[i] = '/';
        i++;
    }
    for (j = 0; j < my_str_len(d_name); j++){
        path[i + j] = d_name[j];
    }
    path[i + j] = '\0';
    return path;
}
