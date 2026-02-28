/*
** EPITECH PROJECT, 2025
** csfml_lib
** File description:
** helpers to manage animation frames inside a texture
*/

#include "../../../includes/textures.h"

int csfml_texture_set_animation_frames(csfml_texture_t *texture,
    unsigned int frame_count)
{
    if (!texture) return -1;
    texture->animation_frame_count = (frame_count == 0) ? 1 : frame_count;
    if (texture->animation_frame_index >= texture->animation_frame_count)
        texture->animation_frame_index = 0;
    return 0;
}

void csfml_texture_set_frame_index(csfml_texture_t *texture,
    unsigned int frame_index)
{
    if (!texture || texture->animation_frame_count == 0) return;
    texture->animation_frame_index = frame_index % texture->animation_frame_count;
}

unsigned int csfml_texture_advance_frame(csfml_texture_t *texture)
{
    if (!texture || texture->animation_frame_count <= 1) return 0;
    texture->animation_frame_index = (texture->animation_frame_index + 1) % texture->animation_frame_count;
    return texture->animation_frame_index;
}

sfIntRect csfml_texture_get_frame_rect(const csfml_texture_t *texture,
    unsigned int frame_index)
{
    sfIntRect rect = {0, 0, 0, 0};
    if (!texture || !texture->handle) return rect;
    unsigned int frames = (texture->animation_frame_count == 0) ? 1 : texture->animation_frame_count;
    unsigned int index = frame_index % frames;
    unsigned int frame_width = (frames == 0) ? texture->width : (texture->width / frames);
    rect.left = (int)(frame_width * index);
    rect.top = 0;
    rect.width = (int)frame_width;
    rect.height = (int)texture->height;
    return rect;
}

sfIntRect csfml_texture_get_current_frame_rect(const csfml_texture_t *texture)
{
    if (!texture) {
        sfIntRect r = {0,0,0,0};
        return r;
    }
    return csfml_texture_get_frame_rect(texture, texture->animation_frame_index);
}
