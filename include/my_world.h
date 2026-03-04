/*
** EPITECH PROJECT, 2025
** my_hunter_header
** File description:
** my_hunter_header
*/

#ifndef MY_WORLD
    #define MY_WORLD
    #include "init_project.h"
    #include "SFML/System.h"
    #include "SFML/Audio.h"
    #include "SFML/Graphics.h"
    #include "stdlib.h"
    #include "math.h"
    #include "menu.h"

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

typedef struct camera_s{
    float x;
    float y;
    float angle_x;
    float angle_y;
    float zoom;
}camera_t;

typedef struct game_info{
    int strenght;
    int weight;
    int rayon;
    int edit_mode;
    sfTexture *water_texture;
    sfTexture *snow_texture;
    sfTexture *herbe_texture;
    sfTexture *sand_texture;
}game_info_t;

typedef struct world_runtime_s {
    world_ *init;
    camera_t *camera;
    game_info_t *game_info;
    int map_3d[MAP_Y][MAP_X];
    sfConvexShape ***rendus_map;
    sfConvexShape ***rendus_map2;
    sfVector2f **map_2d;
    int rendus_dirty;
} world_runtime_t;

init_t init(void);
void game_loop(init_t *init, camera_t *camera, game_info_t *game_info);
void game_end(init_t *init);
void manage_camera_pos(camera_t *camera);
int **noise_perlin(int width, int height);
sfColor change_color_by_z(int z);
sfVector2f **create_2d_map_empty(int map_3d[MAP_Y][MAP_X], camera_t *camera);
sfVertexArray *create_line_by_two_points(sfVector2f *point1 , sfVector2f *point2, int z);
int draw_edit_map(sfRenderWindow *window, sfVector2f **map_2d, int map_3d[MAP_Y][MAP_X]);
void manage_map(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, camera_t *camera);
void change_z_by_select_point(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, int i, int j, sfVector2f current_point);
sfVector2f project_iso_point(int x, int y, int z, camera_t *camera);
void update_edit_map(int map_3d[MAP_Y][MAP_X], sfVector2i mouse_pos, camera_t *camera);
sfConvexShape ***mem_alloc_2d_array_sfVConvex(int nbr_line, int nbr_column);
int draw_rendus_map(sfRenderWindow *window, sfConvexShape ***convex_tab);
void fit_convex_by_map(sfConvexShape ***tab, int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info);
sfConvexShape ***create_convex_array_empty(void);
void manage_edit_mode(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d, camera_t *camera, game_info_t *game_info);
void manage_rendus_mode(sfConvexShape ***convex_tab1, int map_3d[MAP_Y][MAP_X], camera_t *camera, game_info_t *game_info);
void update_iso_point(int map_3d[MAP_Y][MAP_X], sfVector2f **map_2d, camera_t *camera);
void fit_convex_by_map2(sfConvexShape ***tab, int map_3d[MAP_Y][MAP_X], camera_t *camera);

#endif /* !MY_WORLD */
