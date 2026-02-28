/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** simple texture cache API
*/

#ifndef CSFML_TEXTURES_SIMPLE_H
    #define CSFML_TEXTURES_SIMPLE_H

    #include <SFML/Graphics.h>

typedef struct csfml_context csfml_context_t;

typedef struct tex_node {
    char *key;
    sfTexture *tex;
    struct tex_node *next;
} tex_node_t;

sfTexture *csfml_tex_load(csfml_context_t *ctx, const char *key,
    const char *path);
sfTexture *csfml_tex_get(csfml_context_t *ctx, const char *key);
void csfml_tex_unload(csfml_context_t *ctx, const char *key);
void csfml_tex_cleanup(csfml_context_t *ctx);

#endif
