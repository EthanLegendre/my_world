/*
** EPITECH PROJECT, 2025
** lib_csfml
** File description:
** init_project_h
*/

#ifndef CSFML_INIT_PROJECT_PRIVATE_H
    #define CSFML_INIT_PROJECT_PRIVATE_H

    #include "init_project.h"

int csfml_setup_window_and_clock(csfml_context_t *ctx,
    const char *title, unsigned int width, unsigned int height);
void csfml_process_frame_accum(csfml_context_t *ctx,
    csfml_frame_cb_t frame_cb, float frame_time);
int csfml_context_loop(csfml_context_t *ctx,
    csfml_frame_cb_t frame_cb, csfml_draw_cb_t draw_cb);
void csfml_dispatch_event(csfml_context_t *ctx, const sfEvent *event);

#endif
