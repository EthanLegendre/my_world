/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** consolidated init_project API
*/

#ifndef CSFML_INIT_PROJECT_H
    #define CSFML_INIT_PROJECT_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef struct tex_node tex_node_t;
typedef struct sound_node sound_node_t;
typedef struct csfml_context csfml_context_t;

typedef void (* csfml_mouse_click_cb_t)(int x, int y, int button,
    void *user_data);

typedef void (* csfml_mouse_move_cb_t)(int x, int y, void *user_data);

typedef void (* csfml_key_press_cb_t)(sfKeyCode key, void *user_data);

typedef void (* csfml_frame_cb_t)(csfml_context_t *ctx, float dt,
    void *user_data);

typedef void (* csfml_draw_cb_t)(csfml_context_t *ctx, void *user_data);

struct csfml_context {
    sfRenderWindow *window;
    sfClock *clock;
    unsigned int framerate_limit;
    csfml_mouse_click_cb_t on_mouse_click;
    csfml_mouse_move_cb_t on_mouse_move;
    csfml_key_press_cb_t on_key_press;
    csfml_frame_cb_t on_frame;
    float frame_accum;
    void *user_data;
    tex_node_t *textures_head;
    sound_node_t *sounds_head;
    sfSprite *background_sprite;
};

csfml_context_t *csfml_context_create(const char *title, unsigned int width,
    unsigned int height, unsigned int framerate_limit);
void csfml_context_destroy(csfml_context_t *ctx);
void csfml_context_set_mouse_click_cb(csfml_context_t *ctx,
    csfml_mouse_click_cb_t cb);
void csfml_context_set_mouse_move_cb(csfml_context_t *ctx,
    csfml_mouse_move_cb_t cb);
void csfml_context_set_key_press_cb(csfml_context_t *ctx,
    csfml_key_press_cb_t cb);
void csfml_context_set_user_data(csfml_context_t *ctx, void *user_data);
void csfml_context_set_frame_cb(csfml_context_t *ctx, csfml_frame_cb_t cb);
void csfml_context_close(csfml_context_t *ctx);
int csfml_context_run(csfml_context_t *ctx, csfml_frame_cb_t frame_cb,
    csfml_draw_cb_t draw_cb, void *user_data);
int csfml_context_poll_events(csfml_context_t *ctx);
int csfml_context_is_open(csfml_context_t *ctx);
void csfml_cleanup_all(csfml_context_t *ctx);

/* Background helpers */
int csfml_context_set_background_from_file(csfml_context_t *ctx,
    const char *key, const char *path);
int csfml_context_set_background_texture(csfml_context_t *ctx,
    sfTexture *texture);
void csfml_context_clear_background(csfml_context_t *ctx);

#endif
