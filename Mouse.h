#pragma once

#include <SFML/Graphics.h>

#define CURSOR_SPRITE "Sprites/UI/cursors.png"

static sfTexture* cursor_texture;
static sfSprite* cursor_sprite;

void init_cursor();
void show_cursor(sfRenderWindow* window);
void destroy_cursor();