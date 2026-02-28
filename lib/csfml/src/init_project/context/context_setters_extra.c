/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** extra context setters split out
*/

#include "init_project.h"

void csfml_context_close(csfml_context_t *ctx)
{
    if (!ctx)
        return;
    csfml_cleanup_all(ctx);
    csfml_context_destroy(ctx);
}
