/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** textures delete wrappers
*/

#include "textures_simple.h"

void csfml_textures_unload(csfml_context_t *ctx, const char *key)
{
    csfml_tex_unload(ctx, key);
}

void csfml_textures_cleanup(csfml_context_t *ctx)
{
    csfml_tex_cleanup(ctx);
}
