/*
** EPITECH PROJECT, 2025
** my_hunter_header
** File description:
** my_hunter_header
*/

#ifndef MY_WORLD
    #define MY_WORLD
    #include "../include/biglib.h"
    #include "../lib/csfml/includes/init_project.h"
    #include "../lib/csfml/includes/textures_simple.h"
    #include "SFML/System.h"
    #include "SFML/Window.h"
    #include "SFML/Audio.h"
    #include "SFML/Graphics.h"
    #include "menu.h"
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #define WINDOW_SIZE_X 1920
    #define WINDOW_SIZE_Y 1080
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    #define MAP_X 200
    #define MAP_Y 200
    #define SPACE 100
    #define CAM_SPEED 20
    #define ROTATE_SPEED 1
    #define WEIGHT 2
    #define ZOOM_SPEED 0.005
    #define HAUTEUR_MAX 200
    #define HAUTEUR_MIN 0
    #define MAX_HEIGHT_PERLIN 255
    #define PI_F 3.14159265358979323846f

typedef struct ip {
    float angle_x;
    float angle_y;
    float cos_x;
    float sin_x;
    float cos_y;
    float sin_y;
    float cx;
    float cy;
    float center_x;
    float center_y;
    float zoom;
    float x;
    float y;
    float rel_x;
    float rel_y;
    float z;
    float screen_x;
    float screen_y;
} ip_t;

typedef struct init {
    csfml_context_t *ctx;
    sfRenderWindow *window;
}init_t;

typedef struct text_info {
    sfText *text;
    sfFont *font;
    char *content;
    sfVector2f position;
    unsigned int size;
    sfColor color;
    sfClock *clock;
    int seconde;
}text_info_t;

typedef struct sound_info {
    sfSound *sound;
    sfSoundBuffer *buffer;
}sound_info_t;

typedef struct sprite_info {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfIntRect rect;
    sfColor color;
}sprite_info_t;

typedef struct camera_s {
    float x;
    float y;
    float angle_x;
    float angle_y;
    float zoom;
}camera_t;

typedef struct fcbm {
    float angle_x;
    float angle_y;
    float cos_x;
    float sin_x;
    float cos_y;
    float sin_y;
    float cx;
    float cy;
    float center_x;
    float center_y;
    float zoom;
    int z;
    int x;
    int y;
} fcbm_t;

typedef struct game_info {
    int strenght;
    int weight;
    int rayon;
    int edit_mode;
    sfTexture *water_texture;
    sfTexture *snow_texture;
    sfTexture *herbe_texture;
    sfTexture *sand_texture;
    sfVector2i mouse_pos;
    int up;
    unsigned int base_seed;
}game_info_t;

typedef struct pha {
    float amplitude;
    float frequency;
    float total;
    float max_value;
    float base_scale;
    float persistence;
    float lacunarity;
    int octaves;
    float sample_x;
    float sample_y;
}pha_t;

typedef struct my_world_s {
    csfml_context_t *ctx;
    csfml_menu_t *menu;
    sfTexture *tex_menu;
    sfFont *font_menu;
    unsigned int map_seed;
    int map_seed_dirty;
    int menu_open;
    int main_page_id;
    int edit_page_id;
    int load_page_id;
    int pause_page_id;
    int save_page_id;
    int save_menu_from_page_id;
    camera_t *active_camera;
    sfVector2f **active_map_2d;
    int *active_rendus_dirty;
    int (*active_map_3d)[MAP_X];
} my_world_t;

typedef struct world_runtime_s {
    my_world_t *init;
    camera_t *camera;
    game_info_t *game_info;
    int map_3d[MAP_Y][MAP_X];
    sfConvexShape ***rendus_map;
    sfConvexShape ***rendus_map2;
    sfVector2f **map_2d;
    int rendus_dirty;
} world_runtime_t;

my_world_t *init(void);
void game_end(my_world_t *world_data);
void game_loop(my_world_t *world_data, camera_t *camera,
    game_info_t *game_info);
int fill_map_with_perlin(int map_3d[MAP_Y][MAP_X], unsigned int seed);
void manage_camera_pos(camera_t *camera);
int **noise_perlin(int width, int height, unsigned int seed);
sfColor change_color_by_z(int z);
sfVector2f **create_2d_map_empty(int map_3d[MAP_Y][MAP_X],
    camera_t *camera);
sfVertexArray *create_line_by_two_points(sfVector2f *point1,
    sfVector2f *point2, int z);
int draw_edit_map(sfRenderWindow *window, sfVector2f **map_2d,
    int map_3d[MAP_Y][MAP_X]);
sfVector2f project_iso_point(int x, int y, int z,
    camera_t *camera);
void update_edit_map(int map_3d[MAP_Y][MAP_X],
    game_info_t *game_info, camera_t *camera);
sfConvexShape ***mem_alloc_2d_array_sfVConvex(int nbr_line, int nbr_column);
int draw_rendus_map(sfRenderWindow *window, sfConvexShape ***convex_tab);
void fit_convex_by_map(sfConvexShape ***tab, int map_3d[MAP_Y][MAP_X],
    camera_t *camera, game_info_t *game_info);
sfConvexShape ***create_convex_array_empty(void);
void manage_edit_mode(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d,
    camera_t *camera, game_info_t *game_info);
void manage_rendus_mode(sfConvexShape ***convex_tab1,
    int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info);
void update_iso_point(int map_3d[MAP_Y][MAP_X],
    sfVector2f **map_2d, camera_t *camera);
void change_z_by_select_point(int map_3d[MAP_Y][MAP_X],
    game_info_t *game_info, int *int_tab, sfVector2f *current_point);
#endif /* !MY_WORLD */
