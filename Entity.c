#include "Entity.h"
#include "UI.h"
#include <stdlib.h>

void init_entity_miscs() {

	is_button_pressed = 0;

}
void spawn_chest(Chest* chest, sfVector2f position) {

	sfSprite_setPosition(chest->sprite, position);

}

void init_chest(Chest* chest) {
		
	chest->texture = sfTexture_createFromFile(CHEST_SPRITE, NULL);

	chest->sprite = sfSprite_create();

	sfSprite_setTexture(chest->sprite, chest->texture, sfTrue);

	sfSprite_setTextureRect(chest->sprite, (sfIntRect) { 3, 19, 27, 31 });

	sfSprite_setPosition(chest->sprite, (sfVector2f) { 460, 460 });

	chest->slots_texture = sfTexture_createFromFile(BAG_PATH, NULL);

	chest->slots_sprite = sfSprite_create();

	sfSprite_setTexture(chest->slots_sprite, chest->slots_texture, sfTrue);

	sfSprite_setTextureRect(chest->slots_sprite, (sfIntRect) { 190, 293, 115, 115 });

	chest->close_texture = sfTexture_createFromFile(CLOSE_BAG_BUTTON_PATH, NULL);

	chest->close_sprite = sfSprite_create();

	sfSprite_setTexture(chest->close_sprite, chest->close_texture, sfTrue);

	sfSprite_setScale(chest->close_sprite, (sfVector2f) { 0.025, 0.025 });

}

void show_chest(sfRenderWindow* window, sfEvent* event, Chest* chest) {

	sfRenderWindow_drawSprite(window, chest->sprite, NULL);

	if (event->type == sfEvtMouseButtonPressed && is_button_pressed == 1) {

		is_button_pressed = 0;

		if (check_is_mouse_entity(window, chest->sprite)) {

			if (chest->closed_open) {

				sfSprite_setTextureRect(chest->sprite, (sfIntRect) { 3, 19, 27, 31 });

				chest->closed_open = 0;

			}
			else if (!chest->closed_open) {

				sfSprite_setTextureRect(chest->sprite, (sfIntRect) { 3, 163, 27, 31 });

				chest->closed_open = 1;

			}

		}

		if (chest->closed_open) {

			if (check_is_mouse_entity(window, chest->close_sprite)) {

				sfSprite_setTextureRect(chest->sprite, (sfIntRect) { 3, 19, 27, 31 });

				chest->closed_open = 0;

			}

		}

	}
	else if (event->type == sfEvtMouseButtonReleased && is_button_pressed == 0)

		is_button_pressed = 1;

	if (chest->closed_open) {
		
		show_sprite_static(window, chest->slots_sprite, (sfVector2i) { 320, 200 });

		show_sprite_static(window, chest->close_sprite, (sfVector2i) { 314, 195 });

	}

}

int check_is_mouse_entity(sfRenderWindow* window, sfSprite* sprite) {

	sfVector2f var = sfRenderWindow_mapPixelToCoords(window, (sfVector2i) { sfMouse_getPosition(window).x, sfMouse_getPosition(window).y }, sfRenderWindow_getView(window));

	if (var.x > sfSprite_getPosition(sprite).x &&
		var.y > sfSprite_getPosition(sprite).y &&
		var.x < sfSprite_getPosition(sprite).x + sfSprite_getGlobalBounds(sprite).width &&
		var.y < sfSprite_getPosition(sprite).y + sfSprite_getGlobalBounds(sprite).height)

		return 1;

	return 0;

}

void destroy_chest(Chest* chest) {

	sfTexture_destroy(chest->texture);

	sfSprite_destroy(chest->sprite);
}