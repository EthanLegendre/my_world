/*
** EPITECH PROJECT, 2026
** manage_camera
** File description:
** manage_camera
*/

#include "my_world.h"

void manage_camera_pos(camera_t *camera)
{
    if (sfKeyboard_isKeyPressed(sfKeyD))
        camera->x += CAM_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        camera->x -= CAM_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        camera->y -= CAM_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        camera->y += CAM_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        camera->angle_y += ROTATE_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        camera->angle_y -= ROTATE_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        camera->angle_x -= ROTATE_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        camera->angle_x += ROTATE_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        camera->zoom += ZOOM_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        camera->zoom -= ZOOM_SPEED;
}
