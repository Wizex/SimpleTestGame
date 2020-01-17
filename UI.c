#include "UI.h"
#include <stdlib.h>
#include "GLOBAL_GAME_INFO.h"

void show_text_button(sfRenderWindow* window, Text_button* text_button) {

	sfRenderWindow_drawSprite(window, text_button->sprite, NULL);
	sfRenderWindow_drawText(window, text_button->text.str, NULL);

}

void show_checkbox_button(sfRenderWindow* window, Checkbox_button* checkbox_button) {

	sfRenderWindow_drawText(window, checkbox_button->text.str, NULL);
	sfRenderWindow_drawSprite(window, checkbox_button->sprite, NULL);

}

void show_slider(sfRenderWindow* window, Slider* slider) {

	sfRenderWindow_drawSprite(window, slider->background_sprite, NULL);
	sfRenderWindow_drawSprite(window, slider->line_sprite, NULL);
	sfRenderWindow_drawSprite(window, slider->slider_sprite, NULL);

}

void show_sprite_static(const sfRenderWindow* window, sfSprite* sprite, sfVector2i position) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, position, sfRenderWindow_getView(window));

	sfSprite_setPosition(sprite, (sfVector2f) { var.x, var.y });

	sfRenderWindow_drawSprite(window, sprite, NULL);

}

int check_is_mouse_sprite(sfRenderWindow* window, sfSprite* sprite) {

	if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(sprite).x &&
		sfMouse_getPositionRenderWindow(window).y > sfSprite_getPosition(sprite).y &&
		sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(sprite).x + sfSprite_getGlobalBounds(sprite).width &&
		sfMouse_getPositionRenderWindow(window).y < sfSprite_getPosition(sprite).y + sfSprite_getGlobalBounds(sprite).height) {

		return 1;

	}

	return 0;

}

int check_is_mouse_sprite_static(const sfRenderWindow* window, sfSprite* sprite) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y }, sfRenderWindow_getView(window));

	if (var.x > sfSprite_getPosition(sprite).x &&
		var.y > sfSprite_getPosition(sprite).y &&
		var.x < sfSprite_getPosition(sprite).x + sfSprite_getGlobalBounds(sprite).width &&
		var.y < sfSprite_getPosition(sprite).y + sfSprite_getGlobalBounds(sprite).height)

		return 1;

	return 0;

}

int check_is_mouse_checkbox(const sfRenderWindow* window, Checkbox_button* checkbox_button) {

	if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(checkbox_button->sprite).x&&
		sfMouse_getPositionRenderWindow(window).y > sfSprite_getPosition(checkbox_button->sprite).y&&
		sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(checkbox_button->sprite).x + sfSprite_getGlobalBounds(checkbox_button->sprite).width &&
		sfMouse_getPositionRenderWindow(window).y < sfSprite_getPosition(checkbox_button->sprite).y + sfSprite_getGlobalBounds(checkbox_button->sprite).height) {

		return 1;

	}

	return 0;

}

int check_is_mouse_slider(const sfRenderWindow* window, Slider* slider) {

	if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(slider->slider_sprite).x &&
		sfMouse_getPositionRenderWindow(window).y > sfSprite_getPosition(slider->slider_sprite).y &&
		sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(slider->slider_sprite).x + sfSprite_getGlobalBounds(slider->slider_sprite).width &&
		sfMouse_getPositionRenderWindow(window).y < sfSprite_getPosition(slider->slider_sprite).y + sfSprite_getGlobalBounds(slider->slider_sprite).height)

		return 1;

	return 0;
}

int check_is_mouse_text_button(const sfRenderWindow* window, Text_button* button) {

	if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(button->sprite).x - (sfSprite_getGlobalBounds(button->sprite).width / 2) &&
		sfMouse_getPositionRenderWindow(window).y > sfSprite_getPosition(button->sprite).y - (sfSprite_getGlobalBounds(button->sprite).height / 2) &&
		sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(button->sprite).x + (sfSprite_getGlobalBounds(button->sprite).width / 2) &&
		sfMouse_getPositionRenderWindow(window).y < sfSprite_getPosition(button->sprite).y + (sfSprite_getGlobalBounds(button->sprite).height / 2))

		return 1;

	return 0;

}

int check_is_mouse_text_button_static(const sfRenderWindow* window, Text_button* button) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y }, sfRenderWindow_getView(window));

	if (var.x > sfSprite_getPosition(button->sprite).x - (sfSprite_getGlobalBounds(button->sprite).width / 2) &&
		var.y > sfSprite_getPosition(button->sprite).y - (sfSprite_getGlobalBounds(button->sprite).height / 2) &&
		var.x < sfSprite_getPosition(button->sprite).x + (sfSprite_getGlobalBounds(button->sprite).width / 2) &&
		var.y < sfSprite_getPosition(button->sprite).y + (sfSprite_getGlobalBounds(button->sprite).height / 2))

		return 1;

	return 0;

}

int check_is_mouse_checkbox_static(const sfRenderWindow* window, Checkbox_button* button) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y }, sfRenderWindow_getView(window));

	if (var.x > sfSprite_getPosition(button->sprite).x &&
		var.y > sfSprite_getPosition(button->sprite).y &&
		var.x < sfSprite_getPosition(button->sprite).x + sfSprite_getGlobalBounds(button->sprite).width &&
		var.y < sfSprite_getPosition(button->sprite).y + sfSprite_getGlobalBounds(button->sprite).height)

		return 1;

	return 0;

}

int check_is_mouse_slider_static(const sfRenderWindow* window, Slider* slider) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { sfMouse_getPositionRenderWindow(window).x, sfMouse_getPositionRenderWindow(window).y }, sfRenderWindow_getView(window));

	if (var.x > sfSprite_getPosition(slider->slider_sprite).x &&
		var.y > sfSprite_getPosition(slider->slider_sprite).y &&
		var.x < sfSprite_getPosition(slider->slider_sprite).x + (sfSprite_getGlobalBounds(slider->slider_sprite).width / 2) &&
		var.y < sfSprite_getPosition(slider->slider_sprite).y + (sfSprite_getGlobalBounds(slider->slider_sprite).height / 2))

		return 1;

	return 0;

}

void destroy_slider(Slider* slider) {

	sfSprite_destroy(slider->line_sprite);
	sfSprite_destroy(slider->slider_sprite);
	sfSprite_destroy(slider->background_sprite);

	sfTexture_destroy(slider->line_texture);
	sfTexture_destroy(slider->slider_texture);
	sfTexture_destroy(slider->background_texture);

}

void destroy_checkbox(Checkbox_button* button) {

	destroy_text(&button->text);

	sfSprite_destroy(button->sprite);

}

void destroy_text(Text* text) {

	sfFont_destroy(text->font);
	sfText_destroy(text->str);

}

void destroy_text_button(Text_button* text_button) {

	sfText_destroy(text_button->text.str);
	sfFont_destroy(text_button->text.font);

	sfSprite_destroy(text_button->sprite);
	sfTexture_destroy(text_button->texture);

}