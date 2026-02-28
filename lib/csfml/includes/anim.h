/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** animation helper API
*/

#ifndef CSFML_ANIM_H
    #define CSFML_ANIM_H

    #include <SFML/Graphics.h>
    #include "init_project.h"

typedef struct csfml_anim_s {
    sfSprite *sprite;
    sfIntRect rect;
    int frame_index;
    int cols;
    float anim_accum;
    float speed;
} csfml_anim_t;

csfml_anim_t *csfml_anim_create(sfTexture *tex, const sfIntRect *rect,
    float speed);
void csfml_anim_destroy(csfml_anim_t *anim);
void csfml_anim_frame(float dt, void *user_data);
void csfml_anim_draw(csfml_context_t *cctx, void *user_data);

#endif
