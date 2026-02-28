/*
** EPITECH PROJECT, 2025
** get_file_size
** File description:
** get_file_size
*/

#include "../../../include/biglib.h"

int get_file_size(char *file_path)
{
    struct stat sfile;

    stat(file_path, &sfile);
    return sfile.st_size;
}
