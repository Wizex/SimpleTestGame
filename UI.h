#pragma once

#include <SFML/Graphics.h>

#define BACKGROUND_BUTTON_SPRITE "Sprites/UI/background_button.png"
#define BACKGROUND_OPTIONS_SPRITE "Sprites/UI/big_board.png"

#define CHECKBOX "Sprites/UI/checkboxes.png"

#define SLIDER_LINE "Sprites/UI/uioptions.png"
#define SLIDER_SPRITE "Sprites/UI/slider.png"
#define SLIDER_BACKGROUND "Sprites/UI/small_stone.png"

#define MAIN_MENU_OPTIONS_BUTTONS_NUMBER 2
#define MAIN_MENU_OPTIONS_CHECKBOXES_NUMBER 3
#define MAIN_MENU_OPTIONS_SLIDERS_NUMBER 2

#define CURSOR_SPRITE "Sprites/UI/cursors.png"

#define FONT "Fonts/font.ttf"

typedef struct Text{

    sfFont *font;

    sfText* str;

} Text;

typedef struct Text_button{

    Text text;

	sfTexture* texture;

	sfSprite* sprite;

} Text_button;

typedef struct Checkbox_button {

	sfTexture* texture;

	sfSprite* sprite;

	Text text;

	int space;

} Checkbox_button;

typedef struct Slider {

	sfTexture* slider_texture;
	sfTexture* line_texture;
	sfTexture* background_texture;

	sfSprite* slider_sprite;
	sfSprite* line_sprite;
	sfSprite* background_sprite;

	float value;

} Slider;

void show_text_button(sfRenderWindow*, Text_button*);
void show_checkbox_button(sfRenderWindow*, Checkbox_button*);
void show_slider(sfRenderWindow*, Slider*);

void show_sprite_static(const sfRenderWindow*, sfSprite*, sfVector2i);

int check_is_mouse_text_button(sfRenderWindow*, Text_button*);
int check_is_mouse_checkbox(sfRenderWindow*, Checkbox_button*);
int check_is_mouse_slider(sfRenderWindow*, Slider*);
int check_is_mouse_sprite(sfRenderWindow*, sfSprite*);

int check_is_mouse_text_button_static(const sfRenderWindow*, Text_button*);
int check_is_mouse_checkbox_static(const sfRenderWindow*, Checkbox_button*);
int check_is_mouse_slider_static(const sfRenderWindow*, Slider*);
int check_is_mouse_sprite_static(const sfRenderWindow*, sfSprite*);

void destroy_text(Text*);
void destroy_text_button(Text_button*);
void destroy_slider(Slider*);
void destroy_checkbox(Checkbox_button*);