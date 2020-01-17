#include "Terrain.h"
#include "Perlin.h"

#include <math.h>
#include <stdio.h>

void init_terrain() {

	srand(time(NULL));

	init_seed();

	for (int i = 0; i < WATER_NUMBER - 4; i++) {

		terrain.water_textures[i] = sfTexture_createFromFile(TERRAIN_PATH, NULL);

		terrain.water_sprites[i] = sfSprite_create();

		sfSprite_setTexture(terrain.water_sprites[i], terrain.water_textures[i], sfTrue);

		sfSprite_setScale(terrain.water_sprites[i], (sfVector2f) { 0.5, 0.5 });

	}

	for (int i = 0; i < GRASS_NUMBER - 1; i++) {

		terrain.grass_textures[i] = sfTexture_createFromFile(TERRAIN_PATH, NULL);

		terrain.grass_sprites[i] = sfSprite_create();

		sfSprite_setTexture(terrain.grass_sprites[i], terrain.grass_textures[i], sfTrue);

		sfSprite_setScale(terrain.grass_sprites[i], (sfVector2f) { 0.5, 0.5 });

	}

	terrain.grass_textures[3] = sfTexture_createFromFile(TERRAIN_PATH, NULL);

	terrain.grass_sprites[3] = sfSprite_create();

	sfSprite_setTexture(terrain.grass_sprites[3], terrain.grass_textures[3], sfTrue);

	sfSprite_setScale(terrain.grass_sprites[3], (sfVector2f) { 0.25, 0.25 });

	for (int i = 9; i < WATER_NUMBER; i++) {

		terrain.water_textures[i] = sfTexture_createFromFile(TERRAIN_PATH, NULL);

		terrain.water_sprites[i] = sfSprite_create();

		sfSprite_setTexture(terrain.water_sprites[i], terrain.water_textures[i], sfTrue);
		sfSprite_setScale(terrain.water_sprites[i], (sfVector2f) { 0.615,0.615 });

	}

	sfSprite_setTextureRect(terrain.grass_sprites[0], (sfIntRect) { 672, 160, 32, 32 });
	sfSprite_setTextureRect(terrain.grass_sprites[1], (sfIntRect) { 704, 160, 32, 32 });
	sfSprite_setTextureRect(terrain.grass_sprites[2], (sfIntRect) { 736, 160, 32, 32 });
	sfSprite_setTextureRect(terrain.grass_sprites[3], (sfIntRect) { 223, 288, 64, 64 });

	sfSprite_setTextureRect(terrain.water_sprites[0], (sfIntRect) { 706, 454, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[1], (sfIntRect) { 196, 378, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[2], (sfIntRect) { 228, 416, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[3], (sfIntRect) { 224, 355, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[4], (sfIntRect) { 256, 380, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[5], (sfIntRect) { 196, 354, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[6], (sfIntRect) { 254, 354, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[7], (sfIntRect) { 202, 408, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[8], (sfIntRect) { 256, 415, 32, 32 });
	sfSprite_setTextureRect(terrain.water_sprites[9], (sfIntRect) { 225, 288, 26, 26});
	sfSprite_setTextureRect(terrain.water_sprites[10], (sfIntRect) { 258, 288, 26, 26 });
	sfSprite_setTextureRect(terrain.water_sprites[11], (sfIntRect) { 226, 326, 26, 26 });
	sfSprite_setTextureRect(terrain.water_sprites[12], (sfIntRect) { 262, 326, 26, 26 });

}

void create_terrain() {

	for(int i = 0;i < TERRAIN_WIDTH;i++){

		for (int e = 0; e < TERRAIN_HEIGHT; e++) {

			terrain.terrain[i][e] = perlin2d(i, e, 0.05, 12);

		}

	}

}

void show_terrain(sfRenderWindow* window) {

	int x = rand() % 10;

	for (int i = 0; i < TERRAIN_WIDTH; i++) {

		for (int e = 0; e < TERRAIN_HEIGHT; e++) {

			if (terrain.terrain[i][e] > GRASS_NUMBER_PERLIN) {
				
				if (terrain.terrain[i][e] > GRASS_NUMBER_PERLIN && terrain.terrain[i][e] < 0.55) {

					sfSprite_setPosition(terrain.grass_sprites[1], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.grass_sprites[1], NULL);
					
				}else if (terrain.terrain[i][e] > 0.55) {

					sfSprite_setPosition(terrain.grass_sprites[1], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.grass_sprites[1], NULL);

				}

			}else if (terrain.terrain[i][e] < 0.4) {

				sfSprite_setPosition(terrain.water_sprites[0], (sfVector2f) { i * 16, e * 16});

				sfRenderWindow_drawSprite(window, terrain.water_sprites[0], NULL);

			}
			else if (terrain.terrain[i][e] < GRASS_NUMBER_PERLIN && terrain.terrain[i][e] > 0.4) {

				if(terrain.terrain[i + 1][e] < 0.4 && terrain.terrain[i - 1][e] < 0.4 &&
					terrain.terrain[i + 1][e - 1] < 0.4 && terrain.terrain[i + 1][e + 1] < 0.4 &&
					terrain.terrain[i - 1][e - 1] < 0.4 && terrain.terrain[i - 1][e + 1] < 0.4 &&
					terrain.terrain[i][e - 1] < 0.4 && terrain.terrain[i][e + 1] < 0.4) {

					sfSprite_setPosition(terrain.grass_sprites[3], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.grass_sprites[3], NULL);

				}else

				if (terrain.terrain[i + 1][e] < 0.4 && terrain.terrain[i - 1][e] > 0.4 &&
					terrain.terrain[i][e + 1] > 0.4 && terrain.terrain[i][e - 1] > 0.4) {

					sfSprite_setPosition(terrain.water_sprites[1], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[1], NULL);

				}
				else if (terrain.terrain[i][e - 1] < 0.4 && terrain.terrain[i][e + 1] > 0.4 &&
					terrain.terrain[i + 1][e] > 0.4 && terrain.terrain[i - 1][e] > 0.4) {

					sfSprite_setPosition(terrain.water_sprites[2], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[2], NULL);

				}
				else if (terrain.terrain[i][e + 1] < 0.4 && terrain.terrain[i][e - 1] > 0.4 && 
					terrain.terrain[i + 1][e] > 0.4 && terrain.terrain[i - 1][e] > 0.4) {

					sfSprite_setPosition(terrain.water_sprites[3], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[3], NULL);

				}
				else if (terrain.terrain[i - 1][e] < 0.4 && terrain.terrain[i + 1][e] > 0.4 &&
					terrain.terrain[i][e + 1] > 0.4 && terrain.terrain[i][e - 1] > 0.4) {

					sfSprite_setPosition(terrain.water_sprites[4], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[4], NULL);

				}
				else if (terrain.terrain[i + 1][e] > 0.4 && terrain.terrain[i][e - 1] > 0.4 &&
					terrain.terrain[i + 1][e + 1] < 0.4 && terrain.terrain[i - 1][e] > 0.4 &&
					terrain.terrain[i][e + 1] > 0.4) {

					sfSprite_setPosition(terrain.water_sprites[5], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[5], NULL);

				}
				else if (terrain.terrain[i - 1][e] > 0.4 && terrain.terrain[i][e - 1] > 0.4 &&
					terrain.terrain[i + 1][e + 1] > 0.4 && terrain.terrain[i + 1][e] > 0.4
					&& terrain.terrain[i - 1][e - 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[8], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[8], NULL);

				}
				else if (terrain.terrain[i - 1][e] > 0.4 && terrain.terrain[i][e - 1] > 0.4 &&
					terrain.terrain[i + 1][e + 1] > 0.4 && terrain.terrain[i + 1][e] > 0.4
					&& terrain.terrain[i - 1][e + 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[6], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[6], NULL);

				}
				else if (terrain.terrain[i - 1][e] > 0.4 && terrain.terrain[i][e - 1] > 0.4 &&
					terrain.terrain[i + 1][e + 1] > 0.4 && terrain.terrain[i + 1][e] > 0.4
					&& terrain.terrain[i + 1][e - 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[7], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[7], NULL);

				}
				
				else if (terrain.terrain[i - 1][e] < 0.4 && terrain.terrain[i][e - 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[9], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[9], NULL);

				}
				else if (terrain.terrain[i + 1][e] < 0.4 && terrain.terrain[i][e - 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[10], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[10], NULL);

				}
				else if (terrain.terrain[i - 1][e] < 0.4 && terrain.terrain[i][e + 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[11], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[11], NULL);

				}
				else if (terrain.terrain[i + 1][e] < 0.4 && terrain.terrain[i][e + 1] < 0.4) {

					sfSprite_setPosition(terrain.water_sprites[12], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.water_sprites[12], NULL);

				}
				else {

					sfSprite_setPosition(terrain.grass_sprites[1], (sfVector2f) { i * 16, e * 16 });

					sfRenderWindow_drawSprite(window, terrain.grass_sprites[1], NULL);

				}

			}

		}

	}

}

void destroy_terrain() {

	for (int i = 0; i < WATER_NUMBER; i++) {

		sfSprite_destroy(terrain.water_sprites[i]);
		sfTexture_destroy(terrain.water_textures[i]);

	}

	for (int i = 0; i < GRASS_NUMBER; i++) {

		sfSprite_destroy(terrain.grass_sprites[i]);
		sfTexture_destroy(terrain.grass_textures[i]);

	}


}