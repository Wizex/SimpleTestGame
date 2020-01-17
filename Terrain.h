#pragma once

#include <SFML/Graphics.h>

#define TERRAIN_PATH "Sprites/Terrain/terrain_atlas.png"

#define WATER_NUMBER 13
#define GRASS_NUMBER 4

#define TERRAIN_WIDTH 64
#define TERRAIN_HEIGHT 64

#define GRASS_NUMBER_PERLIN 0.48

typedef struct Terrain {

	sfTexture* water_textures[WATER_NUMBER];
	sfSprite* water_sprites[WATER_NUMBER];

	sfTexture* grass_textures[GRASS_NUMBER];
	sfSprite* grass_sprites[GRASS_NUMBER];

	float terrain[TERRAIN_WIDTH][TERRAIN_HEIGHT];

} Terrain;

Terrain terrain;

void init_terrain();
void create_terrain();
void show_terrain(sfRenderWindow*);
void destroy_terrain();