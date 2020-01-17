#include "Mouse.h"
#include "UI.h"

void init_cursor() {

	cursor_texture = sfTexture_createFromFile(CURSOR_SPRITE, NULL);

	cursor_sprite = sfSprite_create();

	sfSprite_setTexture(cursor_sprite, cursor_texture, sfTrue);

	sfSprite_setTextureRect(cursor_sprite, (sfIntRect) { 33, 5, 25, 25 });

}

void show_cursor(sfRenderWindow* window) {

	show_sprite_static(window, cursor_sprite, (sfVector2i) { sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y });

}

void destroy_cursor() {

	sfTexture_destroy(cursor_texture);
	sfSprite_destroy(cursor_sprite);

}