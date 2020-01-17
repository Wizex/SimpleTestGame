#include "World.h"
#include <math.h>

void create_world() {

	init_terrain();
	init_chest(&chest);
	init_player(&player);
	
	for (int i = 0; i < GHOSTS; i++)

		init_character_ghost(&ghosts[i]);

	create_terrain();

	spawn_characters();

	view = sfView_create();

	sfView_setSize(view, (sfVector2f) { 600, 450 });

}

void spawn_characters() {

	sfFloatRect rect = sfSprite_getGlobalBounds(terrain.water_sprites[0]);

	int var = 0;

	for (int i = 24; i < TERRAIN_WIDTH; i++) {

		for (int e = 24; e < TERRAIN_HEIGHT; e++) {

			rect.left = e * 16;
			rect.top = i * 16;

			if (terrain.terrain[i][e] > 0.44 && terrain.terrain[i + 1][e] > 0.44 &&
				terrain.terrain[i - 1][e] > 0.44 && terrain.terrain[i][e - 1] > 0.44 &&
				terrain.terrain[i][e + 1] > 0.44 && terrain.terrain[i + 1][e + 1] > 0.44 &&
				terrain.terrain[i - 1][e - 1] > 0.44 && terrain.terrain[i - 1][e + 1] > 0.44 &&
				terrain.terrain[i + 1][e - 1] > 0.44) {

				spawn_player(&player, (sfVector2f) { rect.left, rect.top });

				var = 1;
				
				break;

			}

		}

		if (var == 1)

			break;

	}

	spawn_chest(&chest, (sfVector2f) { sfSprite_getPosition(player.sprite).x, sfSprite_getPosition(player.sprite).y - 60 });
	
	int x;
	int y;

	sfVector2f player_position = sfSprite_getPosition(player.sprite);

	for (int i = 0; i < GHOSTS; i++) {

		do {

			x = rand() % (16 * TERRAIN_WIDTH);
			y = rand() % (16 * TERRAIN_HEIGHT);
				
		} while (sqrt(pow(x - player_position.x, 2) +
			pow(y - player_position.y, 2)) > 500);

		spawn_character(&ghosts[i], (sfVector2f) { x, y });

	}

}

void terrain_player_collision() {

	sfFloatRect rect = sfSprite_getGlobalBounds(terrain.water_sprites[0]);

	for (int i = 0; i < TERRAIN_WIDTH; i++) {

		for (int e = 0; e < TERRAIN_HEIGHT; e++) {

			if (terrain.terrain[i][e] < 0.41) {

				rect.left = i * 16;
				rect.top = e * 16;

				collision_player_terrain(&player, rect);
				
			}

		}

	}


}

void show_world(sfRenderWindow* window, sfEvent* event, float* time) {

	show_terrain(window);
	show_player(&player, window, view);
	show_chest(window, event, &chest);
	
	for(int i = 0;i < GHOSTS;i++)

		show_character(&ghosts[i], window, 0.05);

	collision_player(&player, chest.sprite);
	terrain_player_collision();

	move_player(&player, window, *time, (sfVector2i) { TERRAIN_WIDTH, TERRAIN_HEIGHT });

	for(int i = 0;i < GHOSTS;i++)

		move_character(&ghosts[i], &player, *time);

}

void destroy_world() {

	destroy_terrain();

	for(int i = 0;i < GHOSTS;i++)

		destroy_character(&ghosts[i]);

	destroy_player(&player);
	destroy_chest(&chest);

	sfView_destroy(view);

}
