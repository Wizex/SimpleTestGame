#include "HUD.h"
#include "Audio.h"
#include "GLOBAL_GAME_INFO.h"

#include <stdlib.h>
#include <stdio.h>

void init_bag() {

	hud.bag.slots_texture = sfTexture_createFromFile(BAG_PATH, NULL);

	hud.bag.slots_sprite = sfSprite_create();

	sfSprite_setTexture(hud.bag.slots_sprite, hud.bag.slots_texture, sfTrue);

	sfSprite_setTextureRect(hud.bag.slots_sprite, (sfIntRect) { 190, 293, 115, 115 });

	sfSprite_setPosition(hud.bag.slots_sprite, (sfVector2f) { 650, 400 });

	hud.bag.close_bag_texture = sfTexture_createFromFile(CLOSE_BAG_BUTTON_PATH, NULL);

	hud.bag.close_bag_sprite = sfSprite_create();

	sfSprite_setTexture(hud.bag.close_bag_sprite, hud.bag.close_bag_texture, sfTrue);

	sfSprite_setScale(hud.bag.close_bag_sprite, (sfVector2f) { 0.025, 0.025 });

	sfSprite_setPosition(hud.bag.close_bag_sprite, (sfVector2f) { 644, 395 });

}


void init_HUD_miscs() {

	bag_display = 0;

}

void init_HUD() {

	init_bag();

	init_HUD_miscs();

	hud.hearts_points_texture = sfTexture_createFromFile(HEARTS_SPRITE, NULL);

	hud.hearts_points_sprite = sfSprite_create();

	sfSprite_setTexture(hud.hearts_points_sprite, hud.hearts_points_texture, sfTrue);

	sfSprite_setTextureRect(hud.hearts_points_sprite, (sfIntRect) { 167, 162, 160, 160 });

	sfSprite_setScale(hud.hearts_points_sprite, (sfVector2f) { 0.1, 0.1 });
	
	hud.bag_texture = sfTexture_createFromFile("Sprites/HUD/bag.png", NULL);

	hud.bag_sprite = sfSprite_create();

	sfSprite_setTexture(hud.bag_sprite, hud.bag_texture, sfTrue);

	sfSprite_setScale(hud.bag_sprite, (sfVector2f) { 0.25, 0.25 });
	
	hud.menu_button = (Text_button*)malloc(sizeof(Text_button));

	hud.menu_button->texture = sfTexture_createFromFile(BUTTONS_PATH, NULL);

	hud.menu_button->sprite = sfSprite_create();

	sfSprite_setTexture(hud.menu_button->sprite, hud.menu_button->texture, sfTrue);

	hud.menu_button->text.str = sfText_create();

	hud.menu_button->text.font = sfFont_createFromFile(FONT);

	sfSprite_setTextureRect(hud.menu_button->sprite, (sfIntRect) { 427, 547, 98, 14 });

	sfText_setString(hud.menu_button->text.str, "Menu");

	sfText_setFont(hud.menu_button->text.str, hud.menu_button->text.font);

	sfText_setCharacterSize(hud.menu_button->text.str, 20);

	sfText_setColor(hud.menu_button->text.str, (sfColor) { 222, 244, 0, 255 });

	sfText_setOrigin(hud.menu_button->text.str, (sfVector2f) { sfText_getGlobalBounds(hud.menu_button->text.str).width / 2, sfText_getGlobalBounds(hud.menu_button->text.str).height / 2 });

	sfSprite_setOrigin(hud.menu_button->sprite, (sfVector2f) { sfSprite_getGlobalBounds(hud.menu_button->sprite).width / 2, sfSprite_getGlobalBounds(hud.menu_button->sprite).height / 2 });

	sfSprite_setScale(hud.menu_button->sprite, (sfVector2f) { 0.8, 1.9 });

}

void show_bag(sfRenderWindow* window, sfEvent* event) {

	show_sprite_static(window, hud.bag.slots_sprite, (sfVector2i) { 300, 300 });
	show_sprite_static(window, hud.bag.close_bag_sprite, (sfVector2i) { 295, 295 });

	if (event->type == sfEvtMouseButtonPressed && is_mouse_pressed == 1) {

		is_mouse_pressed = 0;

		if (check_is_mouse_sprite_static(window, hud.bag.close_bag_sprite)) {

			sfSound_play(open_close_bag_sound);

			bag_display = 0;

		}

	}
	else if (event->type == sfEvtMouseButtonReleased && is_mouse_pressed == 0)

		is_mouse_pressed = 1;

}

void show_HUD(sfRenderWindow* window, sfEvent* event, int hp) {

	static sfVector2f position;

	if (event->type == sfEvtMouseButtonPressed && is_mouse_pressed == 0) {

		is_mouse_pressed = 1;

		if (check_is_mouse_sprite_static(window, hud.bag_sprite)) {

			sfSound_play(open_close_bag_sound);

			bag_display = 1;

		}

		if (check_is_mouse_text_button_static(window, hud.menu_button)) {

			sfSound_play(button_click);

			game_stage = MAIN_MENU;

		}

	}
	else if (event->type == sfEvtMouseButtonReleased && is_mouse_pressed == 1)

		is_mouse_pressed = 0;

	for (int i = 0; i < hp; i++) 

		show_sprite_static(window, hud.hearts_points_sprite, (sfVector2i) { (i + 1) * 25, 570 });

	show_sprite_static(window, hud.bag_sprite, (sfVector2i) { 752, 552 });

	if(bag_display)

		show_bag(window, event);

	position = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { 400, 19 }, sfRenderWindow_getView(window));

	sfSprite_setPosition(hud.menu_button->sprite, (sfVector2f) { position.x, position.y });

	position = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { 400, 6 }, sfRenderWindow_getView(window));

	sfText_setPosition(hud.menu_button->text.str, (sfVector2f) { position.x, position.y });

	show_text_button(window, hud.menu_button);

}

void destroy_bag() {

	sfSprite_destroy(hud.bag.slots_sprite);
	sfSprite_destroy(hud.bag.close_bag_sprite);

	sfTexture_destroy(hud.bag.slots_texture);
	sfTexture_destroy(hud.bag.close_bag_texture);

}

void destroy_HUD() {

	sfSprite_destroy(hud.bag_sprite);
	sfSprite_destroy(hud.hearts_points_sprite);

	sfTexture_destroy(hud.bag_texture);
	sfTexture_destroy(hud.hearts_points_texture);

	destroy_text_button(hud.menu_button);

	free(hud.menu_button);

	destroy_bag();

}