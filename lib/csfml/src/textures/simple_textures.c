/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** simple texture cache implementation
*/

#include "textures_simple.h"
#include "../../includes/init_project.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

static
tex_node_t **csfml_textures_head(csfml_context_t *ctx)
{
    if (!ctx)
        return NULL;
    return &ctx->textures_head;
}

static
tex_node_t *tex_node_create(csfml_context_t *ctx, const char *key,
    sfTexture *t)
{
    tex_node_t *n = malloc(sizeof(*n));

    if (!n)
        return NULL;
    n->key = my_strdup(key);
    if (!n->key) {
        free(n);
        return NULL;
    }
    n->tex = t;
    n->next = *csfml_textures_head(ctx);
    *csfml_textures_head(ctx) = n;
    return n;
}

sfTexture *csfml_tex_get(csfml_context_t *ctx, const char *key)
{
    tex_node_t *n;

    if (!ctx || !key) {
        return NULL;
    }
    n = *csfml_textures_head(ctx);
    while (n) {
        if (my_strcmp(n->key, key) == 0) {
            return n->tex;
        }
        n = n->next;
    }
    return NULL;
}

sfTexture *csfml_tex_load(csfml_context_t *ctx, const char *key,
    const char *path)
{
    sfTexture *existing;
    sfTexture *texture;

    if (!ctx || !key || !path) {
        return NULL;
    }
    existing = csfml_tex_get(ctx, key);
    if (existing) {
        return existing;
    }
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture)
        return NULL;
    if (!tex_node_create(ctx, key, texture)) {
        sfTexture_destroy(texture);
        return NULL;
    }
    return texture;
}

void csfml_tex_unload(csfml_context_t *ctx, const char *key)
{
    tex_node_t **pp;
    tex_node_t *node;

    if (!ctx || !key) {
        return;
    }
    pp = csfml_textures_head(ctx);
    while (*pp) {
        node = *pp;
        if (my_strcmp(node->key, key) == 0) {
            *pp = node->next;
            sfTexture_destroy(node->tex);
            free(node->key);
            free(node);
            return;
        }
        pp = &node->next;
    }
}

void csfml_tex_cleanup(csfml_context_t *ctx)
{
    tex_node_t *n;
    tex_node_t *next;

    if (!ctx)
        return;
    n = *csfml_textures_head(ctx);
    while (n) {
        next = n->next;
        if (n->tex) {
            sfTexture_destroy(n->tex);
        }
        free(n->key);
        free(n);
        n = next;
    }
    *csfml_textures_head(ctx) = NULL;
}
