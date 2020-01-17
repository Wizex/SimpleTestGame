#include "UI_Main_Menu.h"
#include "Audio.h"
#include "GLOBAL_GAME_INFO.h"
#include <stdlib.h>
#include <stdio.h>

void init_UI(sfRenderWindow* window) {

	init_UI_miscs();

	init_main_menu();
	init_main_menu_options();
	init_main_menu_start();

	init_UI_audio();

	sfView* view = sfView_create();

	sfView_setSize(view, (sfVector2f) { 800, 600 });

	sfView_setCenter(view, (sfVector2f) { 400, 300 });

	sfRenderWindow_setView(window, view);

	sfView_destroy(view);

}

void init_UI_audio() {

	sfMusic_setLoop(main_audio, sfTrue);

}

void init_main_menu() {

	main_menu.main_text = (Text*)malloc(sizeof(Text));

	main_menu.main_text->font = sfFont_createFromFile(FONT_TITLE);

	main_menu.main_text->str = sfText_create();

	sfText_setString(main_menu.main_text->str, "Mutar");

	sfText_setFont(main_menu.main_text->str, main_menu.main_text->font);

	sfText_setCharacterSize(main_menu.main_text->str, 70);

	sfText_setOrigin(main_menu.main_text->str, (sfVector2f) { sfText_getLocalBounds(main_menu.main_text->str).width / 2, sfText_getLocalBounds(main_menu.main_text->str).height / 2 });

	sfText_setPosition(main_menu.main_text->str, (sfVector2f) { 400, 40 });

	sfText_setColor(main_menu.main_text->str, (sfColor) { 189, 94, 0, 255 });

	main_menu.buttons = (Text_button*)malloc(sizeof(Text_button) * MAIN_MENU_BUTTONS_NUMBER);

	for (int i = 0; i < MAIN_MENU_BUTTONS_NUMBER; i++) {

		main_menu.buttons[i].text.font = sfFont_createFromFile(FONT);

		main_menu.buttons[i].text.str = sfText_create();

		main_menu.buttons[i].texture = sfTexture_createFromFile(BACKGROUND_BUTTON_SPRITE, NULL);

		main_menu.buttons[i].sprite = sfSprite_create();

		sfSprite_setTexture(main_menu.buttons[i].sprite, main_menu.buttons[i].texture, sfTrue);

		sfSprite_setTextureRect(main_menu.buttons[i].sprite, (sfIntRect) {40, 150, 400, 178});

	}

	sfText_setString(main_menu.buttons[0].text.str, "Start");
	sfText_setString(main_menu.buttons[1].text.str, "Options");
	sfText_setString(main_menu.buttons[2].text.str, "Exit");

	for (int i = 0; i < MAIN_MENU_BUTTONS_NUMBER; i++) {

		sfText_setFont(main_menu.buttons[i].text.str, main_menu.buttons[i].text.font);

		sfText_setCharacterSize(main_menu.buttons[i].text.str, 75);

		sfText_setColor(main_menu.buttons[i].text.str, (sfColor) { 102, 37, 23, 255 });

	}

	sfText_setOrigin(main_menu.buttons[0].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu.buttons[0].text.str).width / 2, sfText_getLocalBounds(main_menu.buttons[0].text.str).height / 2 });
	sfText_setOrigin(main_menu.buttons[1].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu.buttons[1].text.str).width / 2, sfText_getLocalBounds(main_menu.buttons[1].text.str).height / 2 });
	sfText_setOrigin(main_menu.buttons[2].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu.buttons[2].text.str).width / 2, sfText_getLocalBounds(main_menu.buttons[2].text.str).height / 2 });

	sfText_setPosition(main_menu.buttons[0].text.str, (sfVector2f) { 400, 150 });
	sfText_setPosition(main_menu.buttons[1].text.str, (sfVector2f) { 400, 300 });
	sfText_setPosition(main_menu.buttons[2].text.str, (sfVector2f) { 400, 450 });

	sfSprite_setOrigin(main_menu.buttons[0].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu.buttons[0].sprite).width / 2, sfSprite_getLocalBounds(main_menu.buttons[0].sprite).height / 2 });
	sfSprite_setOrigin(main_menu.buttons[1].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu.buttons[1].sprite).width / 2, sfSprite_getLocalBounds(main_menu.buttons[1].sprite).height / 2 });
	sfSprite_setOrigin(main_menu.buttons[2].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu.buttons[2].sprite).width / 2, sfSprite_getLocalBounds(main_menu.buttons[2].sprite).height / 2 });

	sfSprite_setScale(main_menu.buttons[0].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu.buttons[0].text.str).width + 60) / sfSprite_getLocalBounds(main_menu.buttons[0].sprite).width, 0.8});
	sfSprite_setScale(main_menu.buttons[1].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu.buttons[1].text.str).width + 60) / sfSprite_getLocalBounds(main_menu.buttons[1].sprite).width, 0.8 });
	sfSprite_setScale(main_menu.buttons[2].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu.buttons[2].text.str).width + 60) / sfSprite_getLocalBounds(main_menu.buttons[2].sprite).width, 0.8 });

	sfSprite_setPosition(main_menu.buttons[0].sprite, (sfVector2f) { 400, 180 });
	sfSprite_setPosition(main_menu.buttons[1].sprite, (sfVector2f) { 400, 330 });
	sfSprite_setPosition(main_menu.buttons[2].sprite, (sfVector2f) { 400, 480 });

}

void init_main_menu_options() {

	main_menu_options.texture_background_options = sfTexture_createFromFile(BACKGROUND_OPTIONS_SPRITE, NULL);

	sfTexture_setSmooth(main_menu_options.texture_background_options, sfTrue);

	main_menu_options.sprite_background_options = sfSprite_create();

	sfSprite_setTexture(main_menu_options.sprite_background_options, main_menu_options.texture_background_options, sfTrue);

	sfSprite_setScale(main_menu_options.sprite_background_options, (sfVector2f) { 1, 1.2 });
	sfSprite_setOrigin(main_menu_options.sprite_background_options, (sfVector2f) { sfSprite_getLocalBounds(main_menu_options.sprite_background_options).width / 2, sfSprite_getLocalBounds(main_menu_options.sprite_background_options).height / 2 });

	sfSprite_setPosition(main_menu_options.sprite_background_options, (sfVector2f) { 400, 300 });

	main_menu_options.buttons = (Text_button*)malloc(sizeof(Text_button) * MAIN_MENU_OPTIONS_BUTTONS_NUMBER);

	for (int i = 0; i < MAIN_MENU_OPTIONS_BUTTONS_NUMBER; i++) {

		main_menu_options.buttons[i].text.font = sfFont_createFromFile(FONT);

		main_menu_options.buttons[i].text.str = sfText_create();

		main_menu_options.buttons[i].texture = sfTexture_createFromFile(BACKGROUND_BUTTON_SPRITE, NULL);

		main_menu_options.buttons[i].sprite = sfSprite_create();

		sfSprite_setTexture(main_menu_options.buttons[i].sprite, main_menu_options.buttons[i].texture, sfTrue);

		sfSprite_setTextureRect(main_menu_options.buttons[i].sprite, (sfIntRect) { 40, 150, 400, 178 });

	}

	sfText_setString(main_menu_options.buttons[0].text.str, "Back");
	sfText_setString(main_menu_options.buttons[1].text.str, "Apply");

	for (int i = 0; i < MAIN_MENU_OPTIONS_BUTTONS_NUMBER; i++) {

		sfText_setFont(main_menu_options.buttons[i].text.str, main_menu_options.buttons[i].text.font);

		sfText_setCharacterSize(main_menu_options.buttons[i].text.str, 65);

		sfText_setColor(main_menu_options.buttons[i].text.str, (sfColor) { 102, 37, 23, 255 });

	}

	sfText_setOrigin(main_menu_options.buttons[0].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu_options.buttons[0].text.str).width / 2, sfText_getLocalBounds(main_menu_options.buttons[0].text.str).height / 2 });
	sfText_setOrigin(main_menu_options.buttons[1].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu_options.buttons[1].text.str).width / 2, sfText_getLocalBounds(main_menu_options.buttons[1].text.str).height / 2 });

	sfText_setPosition(main_menu_options.buttons[0].text.str, (sfVector2f) { 280, 470 });
	sfText_setPosition(main_menu_options.buttons[1].text.str, (sfVector2f) { 510, 470 });

	sfSprite_setOrigin(main_menu_options.buttons[0].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_options.buttons[0].sprite).width / 2, sfSprite_getLocalBounds(main_menu_options.buttons[0].sprite).height / 2 });
	sfSprite_setOrigin(main_menu_options.buttons[1].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_options.buttons[1].sprite).width / 2, sfSprite_getLocalBounds(main_menu_options.buttons[1].sprite).height / 2 });

	sfSprite_setScale(main_menu_options.buttons[0].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_options.buttons[0].text.str).width + 30) / sfSprite_getLocalBounds(main_menu_options.buttons[0].sprite).width, 0.6 });
	sfSprite_setScale(main_menu_options.buttons[1].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_options.buttons[1].text.str).width + 30) / sfSprite_getLocalBounds(main_menu_options.buttons[1].sprite).width, 0.6 });

	sfSprite_setPosition(main_menu_options.buttons[0].sprite, (sfVector2f) { 280, 490 });
	sfSprite_setPosition(main_menu_options.buttons[1].sprite, (sfVector2f) { 510, 490 });

	main_menu_options.checkboxes = (Checkbox_button*)malloc(sizeof(Checkbox_button) * MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER);

	for (int i = 0; i < MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER; i++) {

		main_menu_options.checkboxes[i].text.font = sfFont_createFromFile(FONT);

		main_menu_options.checkboxes[i].text.str = sfText_create();

		main_menu_options.checkboxes[i].sprite = sfSprite_create();

		main_menu_options.checkboxes[i].space = 70;

		main_menu_options.checkboxes[i].texture = sfTexture_createFromFile(CHECKBOX, NULL);

		sfTexture_setSmooth(main_menu_options.checkboxes[i].texture, sfTrue);

		sfSprite_setTexture(main_menu_options.checkboxes[i].sprite, main_menu_options.checkboxes[i].texture, sfTrue);

	}

	music_state ? sfSprite_setTextureRect(main_menu_options.checkboxes[0].sprite, (sfIntRect) { 329, 25, 73, 73 }) :
				  sfSprite_setTextureRect(main_menu_options.checkboxes[0].sprite, (sfIntRect) { 233, 25, 73, 73 });

	audio_state ? sfSprite_setTextureRect(main_menu_options.checkboxes[1].sprite, (sfIntRect) { 329, 25, 73, 73 }) : 
				  sfSprite_setTextureRect(main_menu_options.checkboxes[1].sprite, (sfIntRect) { 233, 25, 73, 73 });

	window_mode_state ? sfSprite_setTextureRect(main_menu_options.checkboxes[2].sprite, (sfIntRect) { 329, 25, 73, 73 }) :
						sfSprite_setTextureRect(main_menu_options.checkboxes[2].sprite, (sfIntRect) { 233, 25, 73, 73 });

	sfText_setString(main_menu_options.checkboxes[0].text.str, "Music");
	sfText_setString(main_menu_options.checkboxes[1].text.str, "Audio");
	sfText_setString(main_menu_options.checkboxes[2].text.str, "Window mode");

	for (int i = 0; i < MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER; i++) {

		sfText_setFont(main_menu_options.checkboxes[i].text.str, main_menu_options.checkboxes[i].text.font);

		sfText_setCharacterSize(main_menu_options.checkboxes[i].text.str, 70);

		sfText_setColor(main_menu_options.checkboxes[i].text.str, (sfColor) { 102, 37, 23, 255 });

	}

	sfText_setPosition(main_menu_options.checkboxes[0].text.str, (sfVector2f) { 220, 100 });
	sfText_setPosition(main_menu_options.checkboxes[1].text.str, (sfVector2f) { 220, 200 });
	sfText_setPosition(main_menu_options.checkboxes[2].text.str, (sfVector2f) { 220, 300 });

	sfSprite_setScale(main_menu_options.checkboxes[0].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_options.checkboxes[0].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[0].sprite).height, (sfText_getLocalBounds(main_menu_options.checkboxes[0].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[0].sprite).height });
	sfSprite_setScale(main_menu_options.checkboxes[1].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_options.checkboxes[1].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[1].sprite).height, (sfText_getLocalBounds(main_menu_options.checkboxes[1].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[1].sprite).height });
	sfSprite_setScale(main_menu_options.checkboxes[2].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_options.checkboxes[2].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[2].sprite).height, (sfText_getLocalBounds(main_menu_options.checkboxes[2].text.str).height) / sfSprite_getLocalBounds(main_menu_options.checkboxes[2].sprite).height });

	sfSprite_setPosition(main_menu_options.checkboxes[0].sprite, (sfVector2f) { sfText_getPosition(main_menu_options.checkboxes[0].text.str).x - main_menu_options.checkboxes[0].space, 120 });
	sfSprite_setPosition(main_menu_options.checkboxes[1].sprite, (sfVector2f) { sfText_getPosition(main_menu_options.checkboxes[1].text.str).x - main_menu_options.checkboxes[1].space, 220 });
	sfSprite_setPosition(main_menu_options.checkboxes[2].sprite, (sfVector2f) { sfText_getPosition(main_menu_options.checkboxes[2].text.str).x - main_menu_options.checkboxes[2].space, 320 });

	main_menu_options.audio_slider = (Slider*)malloc(sizeof(Slider));
	main_menu_options.music_slider = (Slider*)malloc(sizeof(Slider));

	main_menu_options.audio_slider->line_texture = sfTexture_createFromFile(SLIDER_LINE, NULL);
	main_menu_options.audio_slider->slider_texture = sfTexture_createFromFile(SLIDER_SPRITE, NULL);
	main_menu_options.audio_slider->background_texture = sfTexture_createFromFile(SLIDER_BACKGROUND, NULL);

	main_menu_options.music_slider->line_texture = sfTexture_createFromFile(SLIDER_LINE, NULL);
	main_menu_options.music_slider->slider_texture = sfTexture_createFromFile(SLIDER_SPRITE, NULL);
	main_menu_options.music_slider->background_texture = sfTexture_createFromFile(SLIDER_BACKGROUND, NULL);

	sfTexture_setSmooth(main_menu_options.music_slider->slider_texture, sfTrue);
	sfTexture_setSmooth(main_menu_options.audio_slider->slider_texture, sfTrue);

	main_menu_options.audio_slider->line_sprite = sfSprite_create();
	main_menu_options.audio_slider->slider_sprite = sfSprite_create();
	main_menu_options.audio_slider->background_sprite = sfSprite_create();

	main_menu_options.music_slider->line_sprite = sfSprite_create();
	main_menu_options.music_slider->slider_sprite = sfSprite_create();
	main_menu_options.music_slider->background_sprite = sfSprite_create();

	sfSprite_setTexture(main_menu_options.audio_slider->line_sprite, main_menu_options.audio_slider->line_texture, sfTrue);
	sfSprite_setTexture(main_menu_options.audio_slider->slider_sprite, main_menu_options.audio_slider->slider_texture, sfTrue);
	sfSprite_setTexture(main_menu_options.audio_slider->background_sprite, main_menu_options.audio_slider->background_texture, sfTrue);
	
	sfSprite_setTextureRect(main_menu_options.audio_slider->line_sprite, (sfIntRect) { 535, 64, 98, 26 });

	sfSprite_setTexture(main_menu_options.music_slider->line_sprite, main_menu_options.music_slider->line_texture, sfTrue);
	sfSprite_setTexture(main_menu_options.music_slider->slider_sprite, main_menu_options.music_slider->slider_texture, sfTrue);
	sfSprite_setTexture(main_menu_options.music_slider->background_sprite, main_menu_options.music_slider->background_texture, sfTrue);

	sfSprite_setTextureRect(main_menu_options.music_slider->line_sprite, (sfIntRect) { 535, 64, 98, 26 });

	main_menu_options.audio_slider->value = sound_volume;
	main_menu_options.music_slider->value = music_volume;

	sfSprite_setOrigin(main_menu_options.audio_slider->background_sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_options.audio_slider->background_sprite).width / 2, sfSprite_getLocalBounds(main_menu_options.audio_slider->background_sprite).height / 2 });
	sfSprite_setOrigin(main_menu_options.music_slider->background_sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_options.music_slider->background_sprite).width / 2, sfSprite_getLocalBounds(main_menu_options.music_slider->background_sprite).height / 2 });

	sfSprite_setScale(main_menu_options.audio_slider->line_sprite, (sfVector2f) { 2, 0.2 });
	sfSprite_setScale(main_menu_options.music_slider->line_sprite, (sfVector2f) { 2, 0.2 });

	sfSprite_setScale(main_menu_options.audio_slider->slider_sprite, (sfVector2f) { 0.05, 0.05 });
	sfSprite_setScale(main_menu_options.music_slider->slider_sprite, (sfVector2f) { 0.05, 0.05 });

	sfSprite_setScale(main_menu_options.audio_slider->background_sprite, (sfVector2f) { 0.3, 0.3 });
	sfSprite_setScale(main_menu_options.music_slider->background_sprite, (sfVector2f) { 0.3, 0.3 });

	sfSprite_setPosition(main_menu_options.audio_slider->line_sprite, (sfVector2f) { 385, 250 });
	sfSprite_setPosition(main_menu_options.music_slider->line_sprite, (sfVector2f) { 385, 150 });

	sfSprite_setPosition(main_menu_options.audio_slider->slider_sprite, (sfVector2f) { sfSprite_getPosition(main_menu_options.audio_slider->line_sprite).x + (sfSprite_getGlobalBounds(main_menu_options.audio_slider->line_sprite).width * main_menu_options.audio_slider->value / 100.0) - sfSprite_getGlobalBounds(main_menu_options.audio_slider->slider_sprite).width, 240 });
	sfSprite_setPosition(main_menu_options.music_slider->slider_sprite, (sfVector2f) { sfSprite_getPosition(main_menu_options.music_slider->line_sprite).x + (sfSprite_getGlobalBounds(main_menu_options.music_slider->line_sprite).width * main_menu_options.music_slider->value / 100.0) - sfSprite_getGlobalBounds(main_menu_options.music_slider->slider_sprite).width, 140 });

	sfSprite_setPosition(main_menu_options.audio_slider->background_sprite, (sfVector2f) { 480, 255 });
	sfSprite_setPosition(main_menu_options.music_slider->background_sprite, (sfVector2f) { 480, 155 });

}

void init_main_menu_start() {

	main_menu_start.buttons = (Text_button*)malloc(sizeof(Text_button) * MAIN_MENU_START_BUTTONS_NUMBER);

	for (int i = 0; i < MAIN_MENU_START_BUTTONS_NUMBER; i++) {

		main_menu_start.buttons[i].text.font = sfFont_createFromFile(FONT);

		main_menu_start.buttons[i].text.str = sfText_create();

		main_menu_start.buttons[i].texture = sfTexture_createFromFile(BACKGROUND_BUTTON_SPRITE, NULL);

		main_menu_start.buttons[i].sprite = sfSprite_create();

		sfSprite_setTexture(main_menu_start.buttons[i].sprite, main_menu_start.buttons[i].texture, sfTrue);

		sfSprite_setTextureRect(main_menu_start.buttons[i].sprite, (sfIntRect) { 40, 150, 400, 178 });

	} 

	sfText_setString(main_menu_start.buttons[0].text.str, "Continue game");
	sfText_setString(main_menu_start.buttons[1].text.str, "New game");
	sfText_setString(main_menu_start.buttons[2].text.str, "Back");

	for (int i = 0; i < MAIN_MENU_START_BUTTONS_NUMBER; i++) {

		sfText_setFont(main_menu_start.buttons[i].text.str, main_menu_start.buttons[i].text.font);

		sfText_setCharacterSize(main_menu_start.buttons[i].text.str, 75);

		sfText_setColor(main_menu_start.buttons[i].text.str, (sfColor) { 102, 37, 23, 255 });

	}

	sfText_setOrigin(main_menu_start.buttons[0].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu_start.buttons[0].text.str).width / 2, sfText_getLocalBounds(main_menu_start.buttons[0].text.str).height / 2 });
	sfText_setOrigin(main_menu_start.buttons[1].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu_start.buttons[1].text.str).width / 2, sfText_getLocalBounds(main_menu_start.buttons[1].text.str).height / 2 });
	sfText_setOrigin(main_menu_start.buttons[2].text.str, (sfVector2f) { sfText_getLocalBounds(main_menu_start.buttons[2].text.str).width / 2, sfText_getLocalBounds(main_menu_start.buttons[2].text.str).height / 2 });

	sfText_setPosition(main_menu_start.buttons[0].text.str, (sfVector2f) { 400, 150 });
	sfText_setPosition(main_menu_start.buttons[1].text.str, (sfVector2f) { 400, 300 });
	sfText_setPosition(main_menu_start.buttons[2].text.str, (sfVector2f) { 400, 450 });

	sfSprite_setOrigin(main_menu_start.buttons[0].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_start.buttons[0].sprite).width / 2, sfSprite_getLocalBounds(main_menu_start.buttons[0].sprite).height / 2 });
	sfSprite_setOrigin(main_menu_start.buttons[1].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_start.buttons[1].sprite).width / 2, sfSprite_getLocalBounds(main_menu_start.buttons[1].sprite).height / 2 });
	sfSprite_setOrigin(main_menu_start.buttons[2].sprite, (sfVector2f) { sfSprite_getLocalBounds(main_menu_start.buttons[2].sprite).width / 2, sfSprite_getLocalBounds(main_menu_start.buttons[2].sprite).height / 2 });

	sfSprite_setScale(main_menu_start.buttons[0].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_start.buttons[0].text.str).width + 60) / sfSprite_getLocalBounds(main_menu_start.buttons[0].sprite).width, 0.8 });
	sfSprite_setScale(main_menu_start.buttons[1].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_start.buttons[1].text.str).width + 60) / sfSprite_getLocalBounds(main_menu_start.buttons[1].sprite).width, 0.8 });
	sfSprite_setScale(main_menu_start.buttons[2].sprite, (sfVector2f) { (sfText_getLocalBounds(main_menu_start.buttons[2].text.str).width + 60) / sfSprite_getLocalBounds(main_menu_start.buttons[2].sprite).width, 0.8 });

	sfSprite_setPosition(main_menu_start.buttons[0].sprite, (sfVector2f) { 400, 180 });
	sfSprite_setPosition(main_menu_start.buttons[1].sprite, (sfVector2f) { 400, 330 });
	sfSprite_setPosition(main_menu_start.buttons[2].sprite, (sfVector2f) { 400, 480 });

}

void init_UI_miscs() {

	texture_background = sfTexture_createFromFile(BACKGROUND_SPRITE, NULL);

	sprite_background = sfSprite_create();

	sfSprite_setTexture(sprite_background, texture_background, sfTrue);

	sfSprite_setScale(sprite_background, (sfVector2f) { 0.78125, 0.78 });

	menu_stages = MENU;

	main_menu_options.audio_checkbox_state = audio_state;
	main_menu_options.music_checkbox_state = music_state;
	main_menu_options.window_mode_checkbox_state = window_mode_state;

	is_mouse_pressed = 0;

}

void show_UI(const sfRenderWindow* window, sfEvent* event) {

	sfRenderWindow_drawSprite(window, sprite_background, NULL);

	switch (menu_stages) {

		case MENU:

			show_main_menu(window, event);

			break;

		case MENU_START:

			show_main_menu_start(window, event);

			break;

		case MENU_OPTIONS:

			show_main_menu_options(window, event);

			break;

		default:

			break;

	}

}

void show_main_menu(const sfRenderWindow* window, sfEvent* event) {

	if (event->type == sfEvtMouseButtonPressed && is_mouse_pressed == 0) {

		is_mouse_pressed = 1;

		if (check_is_mouse_text_button(window, &main_menu.buttons[2]))

			sfRenderWindow_close(window);

		else if (check_is_mouse_text_button(window, &main_menu.buttons[1])) {

			sfSound_play(button_click);

			menu_stages = MENU_OPTIONS;

		}
		else if (check_is_mouse_text_button(window, &main_menu.buttons[0])) {

			sfSound_play(button_click);

			menu_stages = MENU_START;

		}

	}
	else if (event->type == sfEvtMouseButtonReleased && is_mouse_pressed == 1)

		is_mouse_pressed = 0;

	for (int i = 0; i < MAIN_MENU_BUTTONS_NUMBER; i++)

		show_text_button(window, &main_menu.buttons[i]);

	sfRenderWindow_drawText(window, main_menu.main_text->str, NULL);

}

void show_main_menu_options(const sfRenderWindow* window, sfEvent* event) {

	sfRenderWindow_drawSprite(window, main_menu_options.sprite_background_options, NULL);

	if (event->type == sfEvtMouseButtonPressed && is_mouse_pressed == 0) {

		is_mouse_pressed = 1;

		if (check_is_mouse_text_button(window, &main_menu_options.buttons[0])) {

			sfSound_play(button_click);

			menu_stages = MENU;

		}
		else if (check_is_mouse_text_button(window, &main_menu_options.buttons[1]))

			sfSound_play(button_click);

		if (check_is_mouse_checkbox(window, &main_menu_options.checkboxes[0])) {

			sfSound_play(switch_click);

			main_menu_options.music_checkbox_state = !main_menu_options.music_checkbox_state;

			music_state = main_menu_options.music_checkbox_state;

			if (main_menu_options.music_checkbox_state)

				sfSprite_setTextureRect(main_menu_options.checkboxes[0].sprite, (sfIntRect) { 329, 25, 73, 73 });

			else if (!main_menu_options.music_checkbox_state)

				sfSprite_setTextureRect(main_menu_options.checkboxes[0].sprite, (sfIntRect) { 233, 25, 73, 73 });

			if (main_menu_options.music_checkbox_state)

				change_music_volume(music_volume);

			else if (!main_menu_options.music_checkbox_state)

				change_music_volume(0);

		}else if (check_is_mouse_checkbox(window, &main_menu_options.checkboxes[1])) {

			sfSound_play(switch_click);

			main_menu_options.audio_checkbox_state = !main_menu_options.audio_checkbox_state;

			audio_state = main_menu_options.audio_checkbox_state;

			if (main_menu_options.audio_checkbox_state)

				sfSprite_setTextureRect(main_menu_options.checkboxes[1].sprite, (sfIntRect) { 329, 25, 73, 73 });

			else if (!main_menu_options.audio_checkbox_state)

				sfSprite_setTextureRect(main_menu_options.checkboxes[1].sprite, (sfIntRect) { 233, 25, 73, 73 });

			if (main_menu_options.audio_checkbox_state)

				change_sounds_volume(sound_volume);

			else if (!main_menu_options.audio_checkbox_state)

				change_sounds_volume(0);

		}else if (check_is_mouse_checkbox(window, &main_menu_options.checkboxes[2])) {

			sfSound_play(switch_click);

			main_menu_options.window_mode_checkbox_state = !main_menu_options.window_mode_checkbox_state;

			window_mode_state = main_menu_options.window_mode_checkbox_state;

			if (main_menu_options.window_mode_checkbox_state) 

				sfSprite_setTextureRect(main_menu_options.checkboxes[2].sprite, (sfIntRect) { 329, 25, 73, 73 });

			else if (!main_menu_options.window_mode_checkbox_state)

				sfSprite_setTextureRect(main_menu_options.checkboxes[2].sprite, (sfIntRect) { 233, 25, 73, 73 });

		}

	}
	else if (event->type == sfEvtMouseButtonReleased && is_mouse_pressed == 1)

		is_mouse_pressed = 0;

	if (is_mouse_pressed == 1) {

		if (check_is_mouse_slider(window, main_menu_options.audio_slider)) {

			if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(main_menu_options.audio_slider->line_sprite).x && sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(main_menu_options.audio_slider->line_sprite).x + sfSprite_getGlobalBounds(main_menu_options.audio_slider->line_sprite).width - sfSprite_getGlobalBounds(main_menu_options.audio_slider->slider_sprite).width / 2) {

				sfSprite_setPosition(main_menu_options.audio_slider->slider_sprite, (sfVector2f) { sfMouse_getPositionRenderWindow(window).x - (sfSprite_getGlobalBounds(main_menu_options.audio_slider->slider_sprite).width / 2), sfSprite_getPosition(main_menu_options.audio_slider->slider_sprite).y });

				main_menu_options.audio_slider->value = ((sfMouse_getPositionRenderWindow(window).x - sfSprite_getPosition(main_menu_options.audio_slider->line_sprite).x) / sfSprite_getGlobalBounds(main_menu_options.audio_slider->line_sprite).width) * 100;

				sound_volume = main_menu_options.audio_slider->value;

				if (main_menu_options.audio_checkbox_state)

					change_sounds_volume(sound_volume);

			}

		}

		if (check_is_mouse_slider(window, main_menu_options.music_slider)) {

			if (sfMouse_getPositionRenderWindow(window).x > sfSprite_getPosition(main_menu_options.music_slider->line_sprite).x && sfMouse_getPositionRenderWindow(window).x < sfSprite_getPosition(main_menu_options.music_slider->line_sprite).x + sfSprite_getGlobalBounds(main_menu_options.music_slider->line_sprite).width - sfSprite_getGlobalBounds(main_menu_options.music_slider->slider_sprite).width / 2) {

				sfSprite_setPosition(main_menu_options.music_slider->slider_sprite, (sfVector2f) { sfMouse_getPositionRenderWindow(window).x - (sfSprite_getGlobalBounds(main_menu_options.music_slider->slider_sprite).width / 2), sfSprite_getPosition(main_menu_options.music_slider->slider_sprite).y });

				main_menu_options.music_slider->value = ((sfMouse_getPositionRenderWindow(window).x - sfSprite_getPosition(main_menu_options.music_slider->line_sprite).x) / sfSprite_getGlobalBounds(main_menu_options.music_slider->line_sprite).width) * 100;
				
				music_volume = main_menu_options.music_slider->value;

				if (main_menu_options.music_checkbox_state)

					change_music_volume(music_volume);

			}

		}

	}

	for (int i = 0; i < MAIN_MENU_OPTIONS_BUTTONS_NUMBER; i++)

		show_text_button(window, &main_menu_options.buttons[i]);

	for (int i = 0; i < MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER; i++)

		show_checkbox_button(window, &main_menu_options.checkboxes[i]);

	show_slider(window, main_menu_options.audio_slider);
	show_slider(window, main_menu_options.music_slider);

}

void show_main_menu_start(const sfRenderWindow* window, sfEvent* event) {

	if (event->type == sfEvtMouseButtonPressed && is_mouse_pressed == 0) {

		is_mouse_pressed = 1;

		if (check_is_mouse_text_button(window, &main_menu_start.buttons[2])) {

			sfSound_play(button_click);

			menu_stages = MENU;

		}else if (check_is_mouse_text_button(window, &main_menu_start.buttons[1])) {

			sfSound_play(button_click);
		
			game_stage = GAME;
			menu_stages = MENU;

		}else if (check_is_mouse_text_button(window, &main_menu_start.buttons[0]))

			sfSound_play(button_click);

	}else if (event->type == sfEvtMouseButtonReleased && is_mouse_pressed == 1)

		is_mouse_pressed = 0;

	for (int i = 0; i < MAIN_MENU_START_BUTTONS_NUMBER; i++)

		show_text_button(window, &main_menu_start.buttons[i]);

}

void destroy_UI() {

	destroy_buttons();

	destroy_texts();

	destroy_sliders();

	destroy_backgrounds();

}

void destroy_sliders() {

	destroy_slider(main_menu_options.audio_slider);
	destroy_slider(main_menu_options.music_slider);

	free(main_menu_options.audio_slider);
	free(main_menu_options.music_slider);

}

void destroy_backgrounds() {

	sfSprite_destroy(main_menu_options.sprite_background_options);
	sfSprite_destroy(sprite_background);

	sfTexture_destroy(main_menu_options.texture_background_options);
	sfTexture_destroy(texture_background);

}

void destroy_texts() {

	destroy_text(main_menu.main_text);

	free(main_menu.main_text);

}

void destroy_checkboxes() {

	for (int i = 0; i < MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER; i++)

		destroy_checkbox(&main_menu_options.checkboxes[i]);

	free(main_menu_options.checkboxes);

}

void destroy_buttons() {

	for (int i = 0; i < MAIN_MENU_BUTTONS_NUMBER; i++)

		destroy_text_button(&main_menu.buttons[i]);

	for (int i = 0; i < MAIN_MENU_OPTIONS_BUTTONS_NUMBER; i++) 

		destroy_text_button(&main_menu_options.buttons[i]);

	for(int i = 0;i < MAIN_MENU_START_BUTTONS_NUMBER;i++)

		destroy_text_button(&main_menu_start.buttons[i]);

	free(main_menu.buttons);
	free(main_menu_options.buttons);
	free(main_menu_start.buttons);

}