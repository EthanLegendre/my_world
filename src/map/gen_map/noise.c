/*
** EPITECH PROJECT, 2025
** game_loop
** File description:
** game_loop
*/

#include "my_world.h"

// polynomiale
static
float fade(float t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

static
float midpoint(float a, float b, float t)
{
    return a + t * (b - a);
}

static
float scalaire(int hash, float x, float y)
{
    int h = hash & 7;
    float u = h < 4 ? x : y;
    float v = h < 4 ? y : x;

    return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}

static
void init_permutation(int perm[512], unsigned int seed)
{
    int values[256];

    for (int i = 0; i < 256; i++)
        values[i] = i; //remplir tab
    for (int i = 255; i > 0; i--) {
        seed = seed * 1664525u + 1013904223u; // mélanger tab
        int j = (int)(seed % (unsigned int)(i + 1));
        int tmp = values[i];

        values[i] = values[j];
        values[j] = tmp;
    }
    for (int i = 0; i < 256; i++) { // block out of range
        perm[i] = values[i];
        perm[i + 256] = values[i];
    }
}

static
float perlin_2d(float x, float y, int perm[512])
{
    int xi = (int)floorf(x) & 255; // get block coordo
    int yi = (int)floorf(y) & 255;
    float xf = x - floorf(x); // get local coordo
    float yf = y - floorf(y);
    float u = fade(xf); // smooth
    float v = fade(yf);
    int aa = perm[perm[xi] + yi]; // get corner
    int ab = perm[perm[xi] + yi + 1];
    int ba = perm[perm[xi + 1] + yi];
    int bb = perm[perm[xi + 1] + yi + 1];
    float x1 = midpoint(scalaire(aa, xf, yf), scalaire(ba, xf - 1.f, yf), u); // get scalaire && inter
    float x2 = midpoint(scalaire(ab, xf, yf - 1.f), scalaire(bb, xf - 1.f, yf - 1.f), u);

    return midpoint(x1, x2, v); // get height
}

static
int perlin_height_at(int x, int y, int perm[512])
{
    float amplitude = 1.f;
    float frequency = 1.f;
    float total = 0.f;
    float max_value = 0.f;
    const float base_scale = 0.01f;
    const float persistence = 0.5f;
    const float lacunarity = 2.f;
    const int octaves = 5;

    for (int octave = 0; octave < octaves; octave++) {
        float sample_x = (float)x * base_scale * frequency;
        float sample_y = (float)y * base_scale * frequency;

        total += perlin_2d(sample_x, sample_y, perm) * amplitude;
        max_value += amplitude;
        amplitude *= persistence;
        frequency *= lacunarity;
    }
    total /= max_value;
    total = (total + 1.f) * 10.f;
    return (int)(total * MAX_HEIGHT_PERLIN);
}

int **noise_perlin(int width, int height, unsigned int seed)
{
    int **noise = malloc(sizeof(int *) * height);
    int perm[512];

    if (!noise)
        return NULL;
    init_permutation(perm, seed);
    for (int i = 0; i < height; i++) {
        noise[i] = malloc(sizeof(int) * width);
        if (!noise[i]) {
            for (int k = 0; k < i; k++)
                free(noise[k]);
            free(noise);
            return NULL;
        }
        for (int j = 0; j < width; j++) {
            noise[i][j] = perlin_height_at(j, i, perm) * 2;
        }
    }
    return noise;
}

int fill_map_with_perlin(int map_3d[MAP_Y][MAP_X], unsigned int seed)
{
    int **noise = noise_perlin(MAP_X, MAP_Y, seed);

    if (!noise)
        return -1;
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++)
            map_3d[i][j] = (noise[i][j] * HAUTEUR_MAX) / 255;
        free(noise[i]);
    }
    free(noise);
    return 0;
}