/*
** EPITECH PROJECT, 2026
** get_content_proc
** File description:
** get_content_proc
*/

#include "../../../include/biglib.h"
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void manage_buffer(char *out, size_t *used, char *buf)
{
    size_t add = strlen(buf);

    if (*used + add + 1 >= VALUE)
        return;
    memcpy(out + *used, buf, add);
    *used += add;
    out[*used] = '\0';
}

char *get_content_proc(char *file)
{
    FILE *f = fopen(file, "r");
    char *buf;
    char *out;
    size_t used = 0;

    if (!f)
        return NULL;
    buf = malloc(VALUE);
    out = malloc(VALUE);
    if (!buf || !out){
        free(buf);
        free(out);
        return NULL;
    }
    out[0] = '\0';
    while (fgets(buf, VALUE, f))
        manage_buffer(out, &used, buf);
    free(buf);
    fclose(f);
    return out;
}
