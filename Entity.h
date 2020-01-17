#pragma once

#include <SFML/Graphics.h>

#define CHEST_SPRITE "Sprites/Entity/chest.png"
#define BAG_PATH "Sprites/UI/inventory.png"
#define CLOSE_BAG_BUTTON_PATH "Sprites/UI/close_x.png"

typedef struct Chest {

	sfTexture* texture;
	sfTexture* slots_texture;
	sfTexture* close_texture;

	sfSprite* sprite;
	sfSprite* slots_sprite;
	sfSprite* close_sprite;

	int closed_open;

} Chest;

static int is_button_pressed;

void init_entity_miscs();

void spawn_chest(Chest*, sfVector2f);

void init_chest(Chest*);
void show_chest(sfRenderWindow*, sfEvent*, Chest*);
void destroy_chest(Chest*);

int check_is_mouse_entity(sfRenderWindow* window, sfSprite* sprite);
