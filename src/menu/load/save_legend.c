/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** save map in .legend format
*/

#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#include "menu/home.h"

static
int create_save_directory(void)
{
    if (mkdir("saves", 0777) == 0)
        return 0;
    if (errno == EEXIST)
        return 0;
    return -1;
}

static int write_one_line(FILE *file, int map_3d[MAP_Y][MAP_X], int y)
{
    for (int x = 0; x < MAP_X; x++) {
        if (fprintf(file, "%d ", map_3d[y][x]) < 0)
            return 0;
    }
    fprintf(file, "\n");
    return 1;
}

static
int write_map_content(FILE *file, int map_3d[MAP_Y][MAP_X])
{
    if (fprintf(file, "size %d %d\n", MAP_X, MAP_Y) < 0)
        return -1;
    for (int y = 0; y < MAP_Y; y++) {
        if (!write_one_line(file, map_3d, y))
            return -1;
    }
    return 0;
}

int save_map_to_legend(my_world_t *world_data, int slot)
{
    const char *path = NULL;
    FILE *file = NULL;

    if (!world_data || !world_data->active_map_3d || (slot != 1 && slot != 2))
        return -1;
    if (create_save_directory() != 0)
        return -1;
    path = (slot == 1) ? "saves/save1.legend" : "saves/save2.legend";
    file = fopen(path, "w");
    if (!file)
        return -1;
    if (write_map_content(file, world_data->active_map_3d) != 0) {
        fclose(file);
        return -1;
    }
    fclose(file);
    return 0;
}

static int read_one_line(FILE *file, int map_3d[MAP_Y][MAP_X], int y)
{
    for (int x = 0; x < MAP_X; x++) {
        if (fscanf(file, "%d", &map_3d[y][x]) != 1)
            return 0;
    }
    return 1;
}

static
int read_map_content(FILE *file, int map_3d[MAP_Y][MAP_X])
{
    int width = 0;
    int height = 0;

    if (fscanf(file, "size %d %d", &width, &height) != 2)
        return -1;
    if (width != MAP_X || height != MAP_Y)
        return -1;
    for (int y = 0; y < MAP_Y; y++) {
        if (!read_one_line(file, map_3d, y))
            return -1;
    }
    return 0;
}

int load_map_from_legend(my_world_t *world_data, int slot)
{
    const char *path = NULL;
    FILE *file = NULL;

    if (!world_data || !world_data->active_map_3d ||
        !world_data->active_map_2d || !world_data->active_camera ||
        !world_data->active_rendus_dirty || (slot != 1 && slot != 2))
        return -1;
    path = (slot == 1) ? "saves/save1.legend" : "saves/save2.legend";
    file = fopen(path, "r");
    if (!file)
        return -1;
    if (read_map_content(file, world_data->active_map_3d) != 0) {
        fclose(file);
        return -1;
    }
    fclose(file);
    update_iso_point(world_data->active_map_3d,
        world_data->active_map_2d, world_data->active_camera);
    *(world_data->active_rendus_dirty) = 1;
    return 0;
}
