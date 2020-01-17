#include "Characters.h"
#include "Audio.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void init_character_ghost(Character* character) {

	character->damage = 1;

	character->health_points = 1;

	character->current_frame = 0;

	character->image = sfImage_createFromFile(GHOST_PATH);

	sfImage_createMaskFromColor(character->image, (sfColor) {255, 255, 255}, 0);

	character->anim = sfTexture_createFromImage(character->image, NULL);

	character->sprite = sfSprite_create();

	character->x_speed = 0.4f;
	character->y_speed = 0.4f;	

	character->movement = RIGHT;
		
	sfSprite_setTexture(character->sprite, character->anim, sfTrue);

	sfSprite_setScale(character->sprite, (sfVector2f) { 1, 1 });

	sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288, 0, 48, 48 });

}

void init_player(Player* player) {

	player->health_points = 4;

	pressed_button = 0;

	player->x_speed = 0.8f;
	player->y_speed = 0.8f;

	player->anim = sfTexture_createFromFile(PLAYER_PATH, NULL);

	player->sprite = sfSprite_create();

	player->animation = IDLE;

	player->direction = DOWN;

	player->coll = NCOL;

	sfSprite_setScale(player->sprite, (sfVector2f) { 0.05f, 0.05f });

	sfSprite_setOrigin(player->sprite, (sfVector2f) { sfSprite_getLocalBounds(player->sprite).width / 2, sfSprite_getLocalBounds(player->sprite).height / 2 });

	sfSprite_setTexture(player->sprite, player->anim, sfTrue);

	player->play_running_sound = 1;

	player->current_frame = 0;

}

void spawn_player(Player* player, sfVector2f position) {

	sfSprite_setPosition(player->sprite, position);

}

void spawn_character(Character* character, sfVector2f position) {

	sfSprite_setPosition(character->sprite, position);

	character->x_position = position.x;
	character->y_position = position.y;

}

void attack_character(Character* character, Player* player) {

	sfFloatRect character_box = sfSprite_getGlobalBounds(character->sprite);
	sfFloatRect player_box = sfSprite_getGlobalBounds(player->sprite);

	if (sfFloatRect_intersects(&player_box, &character_box, NULL)) {

		sfSound_play(beat_player);

		player->health_points -= 1;

		if (character->movement == TOP) 

			sfSprite_move(player->sprite, (sfVector2f) { 0, -30});

		else if (character->movement == LEFT)

			sfSprite_move(player->sprite, (sfVector2f) { -30, 0 });

		else if (character->movement == RIGHT)

			sfSprite_move(player->sprite, (sfVector2f) { 30, 0 });

		else if (character->movement == DOWN)

			sfSprite_move(player->sprite, (sfVector2f) { 0, 30 });

	}

}

void move_player(Player* player, sfRenderWindow* window, float time, sfVector2i map_size) {

	pressed_button = 0;

	static sfVector2f vect;

	if (player->coll != NCOL)

		sfSprite_setPosition(player->sprite, vect);

	else

		vect = sfSprite_getPosition(player->sprite);

	if (sfKeyboard_isKeyPressed(sfKeyLeft) && sfSprite_getPosition(player->sprite).x > 6 && player->coll != LEFT) {

		sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460 * (int)player->current_frame, 1200, 460, 600 });

		sfSprite_move(player->sprite, (sfVector2f) { -player->x_speed, 0 });

		player->direction = LEFT;
		player->animation = RUNNING;

		pressed_button = 1;

	}else if (sfKeyboard_isKeyPressed(sfKeyRight) && sfSprite_getPosition(player->sprite).x < map_size.x * 16 - 24 && player->coll != RIGHT) {

		sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460 * (int)player->current_frame, 600, 460, 600 });

		sfSprite_move(player->sprite, (sfVector2f) { player->x_speed, 0 });

		player->direction = RIGHT;
		player->animation = RUNNING;

		pressed_button = 1;

	}else if (sfKeyboard_isKeyPressed(sfKeyDown) && sfSprite_getPosition(player->sprite).y < map_size.y * 16 - 32 && player->coll != DOWN) {

		sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460 * (int)player->current_frame, 0, 460, 600 });

		sfSprite_move(player->sprite, (sfVector2f) { 0, player->y_speed });

		player->direction = DOWN;
		player->animation = RUNNING;

		pressed_button = 1;

	}else if (sfKeyboard_isKeyPressed(sfKeyUp) && sfSprite_getPosition(player->sprite).y > 0 && player->coll != TOP) {

		sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460 * (int)player->current_frame, 1800, 460, 600 });

		sfSprite_move(player->sprite, (sfVector2f) { 0, -player->y_speed });

		player->direction = TOP;
		player->animation = RUNNING;

		pressed_button = 1;

	}
	
	if (player->play_running_sound == 1 && player->animation == RUNNING) {

		sfSound_play(player_running);

		player->play_running_sound = 0;

	}else if (player->animation == IDLE)

		sfSound_pause(player_running);

	player->current_frame += time * 0.05f;

	if (pressed_button == 0) 

		player->animation = IDLE;

	if ((int)player->current_frame > 3)

		player->current_frame = 0;

	if (player->animation == IDLE) {

		player->play_running_sound = 1;

		if (player->direction == LEFT) {

			sfSprite_setTextureRect(player->sprite, (sfIntRect) { 0, 1200, 460, 600 });

		}
		else if (player->direction == RIGHT) {

			sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460, 600, 460, 600 });

		}
		else if (player->direction == DOWN) {

			sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460, 0, 460, 600 });

		}
		else if (player->direction == TOP) {

			sfSprite_setTextureRect(player->sprite, (sfIntRect) { 460, 1800, 460, 600 });

		}

	}

}

void move_character(Character* character, Player* player, float time) {
	
	character->current_frame += time * 0.03;

	if (character->current_frame > 3)

		character->current_frame = 0;

	if (sqrt(pow(sfSprite_getPosition(player->sprite).x - sfSprite_getPosition(character->sprite).x, 2) +
		pow(sfSprite_getPosition(player->sprite).y - sfSprite_getPosition(character->sprite).y, 2)) > 100) {

		if (character->movement == RIGHT) {

			sfSprite_move(character->sprite, (sfVector2f) { character->x_speed, 0 });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 96, 48, 48 });

			if (sfSprite_getPosition(character->sprite).x > character->x_position + 100) {

				character->movement = DOWN;

			}

		}
		else if (character->movement == LEFT) {

			sfSprite_move(character->sprite, (sfVector2f) { -character->x_speed, 0 });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 48, 48, 48 });

			if (sfSprite_getPosition(character->sprite).x < character->x_position - 100) {

				character->movement = TOP;

			}

		}
		else if (character->movement == TOP) {

			sfSprite_move(character->sprite, (sfVector2f) { 0, -character->y_speed });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 144, 48, 48 });

			if (sfSprite_getPosition(character->sprite).y < character->y_position - 100) {

				character->movement = RIGHT;

			}

		}
		else if (character->movement == DOWN) {

			sfSprite_move(character->sprite, (sfVector2f) { 0, character->y_speed });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 0, 48, 48 });

			if (sfSprite_getPosition(character->sprite).y > character->y_position + 100) {

				character->movement = LEFT;

			}

		}

	}
	else if (sqrt(pow(sfSprite_getPosition(player->sprite).x - sfSprite_getPosition(character->sprite).x, 2) +
		pow(sfSprite_getPosition(player->sprite).y - sfSprite_getPosition(character->sprite).y, 2)) < 100) {

		attack_character(character, player); 

		int x;
		int y;

		if (sfSprite_getPosition(player->sprite).x - sfSprite_getPosition(character->sprite).x != 0) {

			x = sfSprite_getPosition(player->sprite).x - sfSprite_getPosition(character->sprite).x;

		}

		if (sfSprite_getPosition(player->sprite).y - sfSprite_getPosition(character->sprite).y != 0) {

			y = sfSprite_getPosition(player->sprite).y - sfSprite_getPosition(character->sprite).y;

		}

		if (x > 0) {

			character->movement = RIGHT;
			sfSprite_move(character->sprite, (sfVector2f) { character->x_speed, 0 });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 96, 48, 48 });

		}
		else if (x < 0) {

			character->movement = LEFT;
			sfSprite_move(character->sprite, (sfVector2f) { -character->x_speed, 0 });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 48, 48, 48 });

		}
		else if (y >= 0 && x == 0) {

			character->movement = DOWN;
			sfSprite_move(character->sprite, (sfVector2f) { 0, character->y_speed });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 0, 48, 48 });

		}
		else if (y <= 0 && x == 0) {

			character->movement = TOP;
			sfSprite_move(character->sprite, (sfVector2f) { 0, -character->y_speed });
			sfSprite_setTextureRect(character->sprite, (sfIntRect) { 288 + ((int)character->current_frame * 48), 144, 48, 48 });

		}

	}

}

void show_player(Player* player, sfRenderWindow* window, sfView* view) {

	if (player->health_points > 0) {

		sfRenderWindow_drawSprite(window, player->sprite, NULL);

		static sfVector2f player_position;
		
		if (sfSprite_getPosition(player->sprite).x - 300 < 0 && sfSprite_getPosition(player->sprite).y - 225 > 0)

			player_position = (sfVector2f){ 300, sfSprite_getPosition(player->sprite).y };

		if (sfSprite_getPosition(player->sprite).x - 300 > 0 && sfSprite_getPosition(player->sprite).y - 225 < 0)

			player_position = (sfVector2f){ sfSprite_getPosition(player->sprite).x, 225 };

		if (sfSprite_getPosition(player->sprite).x + 300 > 1024 && sfSprite_getPosition(player->sprite).y + 225 < 1024)

			player_position = (sfVector2f){ 724 , sfSprite_getPosition(player->sprite).y };
		
		if (sfSprite_getPosition(player->sprite).x + 300 < 1024 && sfSprite_getPosition(player->sprite).y + 225 > 1024)

			player_position = (sfVector2f){ sfSprite_getPosition(player->sprite).x , 799 };

		if (sfSprite_getPosition(player->sprite).x - 300 < 0 && sfSprite_getPosition(player->sprite).y + 225 > 1024)

			player_position = (sfVector2f){ 300, 799 };

		if (sfSprite_getPosition(player->sprite).x + 300 > 1024 && sfSprite_getPosition(player->sprite).y - 225 < 0)

			player_position = (sfVector2f){ 724, 225 };

		if ((sfSprite_getPosition(player->sprite).x - 300 > 0 && sfSprite_getPosition(player->sprite).y - 225 > 0) &&
			(sfSprite_getPosition(player->sprite).x + 300 < 1024 && sfSprite_getPosition(player->sprite).y + 225 < 1024))

			player_position = (sfVector2f){ sfSprite_getPosition(player->sprite).x, sfSprite_getPosition(player->sprite).y };

		sfView_setCenter(view, (sfVector2f) { player_position.x, player_position.y });

		sfRenderWindow_setView(window, view);

	}

}

void collision_player(Player* player, sfSprite* sprite) {

	sfFloatRect rect_player = sfSprite_getGlobalBounds(player->sprite);
	sfFloatRect rect_sprite = sfSprite_getGlobalBounds(sprite);

	if (sfFloatRect_intersects(&rect_player, &rect_sprite, NULL) && player->coll == NCOL) {

		if (player->direction == LEFT) {

			player->coll = LEFT;

		}
		else if (player->direction == RIGHT) {

			player->coll = RIGHT;

		}
		else if (player->direction == DOWN) {

			player->coll = DOWN;

		}
		else if (player->direction == TOP) {

			player->coll = TOP;

		}

	}
	else if (!sfFloatRect_intersects(&rect_player, &rect_sprite, NULL) && player->coll == NCOL ||
		!sfFloatRect_intersects(&rect_player, &rect_sprite, NULL) && player->coll != NCOL)

		player->coll = NCOL;

}

void collision_player_terrain(Player* player, sfFloatRect rect) {

	sfFloatRect var = sfSprite_getGlobalBounds(player->sprite);

	if (sfFloatRect_intersects(&var, &rect, NULL) && player->coll == NCOL) {

		if (player->direction == LEFT) {

			player->coll = LEFT;

		}
		else if (player->direction == RIGHT) {

			player->coll = RIGHT;

		}
		else if (player->direction == DOWN) {

			player->coll = DOWN;

		}
		else if (player->direction == TOP) {

			player->coll = TOP;

		}

	}
	else if (!sfFloatRect_intersects(&var, &rect, NULL) && player->coll == NCOL)

		player->coll = NCOL;

}

void show_character(Character* character,sfRenderWindow* window, float time) {

	sfRenderWindow_drawSprite(window, character->sprite, NULL);

}

void destroy_character(Character* character) {

	sfSprite_destroy(character->sprite);
	sfTexture_destroy(character->anim);
	sfImage_destroy(character->image);

}

void destroy_player(Player* player) {

	sfSprite_destroy(player->sprite);
	sfTexture_destroy(player->anim);

}
