#pragma once

#include <SFML/Graphics.h>

#define GHOST_PATH "Sprites/Player/ghost.png"
#define PLAYER_PATH "Sprites/Player/animation.png"

typedef enum ANIMATIONS { RUNNING, IDLE } ANIMATIONS;
typedef enum DIRECTIONS { TOP, DOWN, LEFT, RIGHT, TOP_LEFT, TOP_RIGHT, DOWN_LEFT, DOWN_RIGHT, NCOL } DIRECTIONS;

typedef struct Character {

	DIRECTIONS movement;

	int health_points;
	int damage;

	float x_speed;
	float y_speed;

	int x_position;
	int y_position;

	sfImage* image;

	sfTexture* anim;

	sfSprite* sprite;

	float current_frame;

} Character;

typedef struct Player {

	ANIMATIONS animation;
	DIRECTIONS direction, coll;

	int health_points;

	sfTexture* anim;

	sfSprite* sprite;

	float x_speed;
	float y_speed;

	float current_frame;

	int play_running_sound;

} Player;

static int pressed_button;

static void attack_character(Character*, Player*);
static int collision_character(Character*, Player*);

void init_character_ghost(Character*);
void spawn_character(Character*, sfVector2f);
void move_character(Character*, Player*, float);
void show_character(Character*, sfRenderWindow*, float);
void destroy_character(Character*);

void init_player(Player*);
void spawn_player(Player*, sfVector2f);
void move_player(Player*, sfRenderWindow*, float, sfVector2i);
void show_player(Player*, sfRenderWindow*, sfView*);
void collision_player(Player*, sfSprite*);
void collision_player_terrain(Player*, sfFloatRect);
void destroy_player(Player*);