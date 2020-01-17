#pragma once

#include "SFML/Graphics.h"
#include "UI.h"

#define BACKGROUND_SPRITE "Sprites/UI/background.jpg"

#define MAIN_MENU_BUTTONS_NUMBER 3

#define MAIN_MENU_START_BUTTONS_NUMBER 3

#define FONT_TITLE "Fonts/title_font.ttf"

static enum MENU_STAGES { MENU, MENU_START, MENU_OPTIONS } menu_stages;

typedef struct Main_menu {

	Text* main_text;

	Text_button* buttons;

} Main_menu;

typedef struct Main_menu_options {

	enum CHECKBOX_STATE audio_checkbox_state, music_checkbox_state, window_mode_checkbox_state;

	sfTexture* texture_background_options;

	sfSprite* sprite_background_options;

	Slider* audio_slider;
	Slider* music_slider;

	Checkbox_button* checkboxes;

	Text_button* buttons;

} Main_menu_options;

typedef struct Main_menu_start {

	Text_button* buttons;

} Main_menu_start;

static is_mouse_pressed;

static Main_menu main_menu;
static Main_menu_options main_menu_options;
static Main_menu_start main_menu_start;

static sfTexture* texture_background;

static sfSprite* sprite_background;

void init_UI(sfRenderWindow*);
void show_UI(const sfRenderWindow*, sfEvent*);
void destroy_UI();

static void init_UI_miscs();
static void init_UI_audio();
static void init_main_menu();
static void init_main_menu_options();
static void init_main_menu_start();

static void show_main_menu(const sfRenderWindow*, sfEvent*);
static void show_main_menu_options(const sfRenderWindow*, sfEvent*);
static void show_main_menu_start(const sfRenderWindow*, sfEvent*);

static void destroy_texts();
static void destroy_buttons();
static void destroy_sliders();
static void destroy_backgrounds();
