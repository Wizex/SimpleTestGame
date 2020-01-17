#pragma once

#include <SFML/Graphics.h>
#include "UI.h"
#include "GLOBAL_GAME_INFO.h"

#define HEARTS_SPRITE "Sprites/HUD/hearts.png"
#define BAG_PATH "Sprites/UI/inventory.png"
#define CLOSE_BAG_BUTTON_PATH "Sprites/UI/close_x.png"
#define BUTTONS_PATH "Sprites/UI/background_options.jpg"

typedef struct Bag {

	sfTexture* slots_texture;
	sfTexture* close_bag_texture;

	sfSprite* slots_sprite;
	sfSprite* close_bag_sprite;

} Bag;

typedef struct HUD {

	Bag bag;

	Text_button* menu_button;

	sfTexture* bag_texture;
	sfTexture* hearts_points_texture;

	sfSprite* bag_sprite;
	sfSprite* hearts_points_sprite;

	int player_hp;

} HUD;

static HUD hud;

static int bag_display;

static int is_mouse_pressed;

static void init_bag();
static void show_bag(sfRenderWindow*, sfEvent*);
static void destroy_bag();

static void init_HUD_miscs();

void init_HUD();
void show_HUD(sfRenderWindow*, sfEvent*, int);
void destroy_HUD();