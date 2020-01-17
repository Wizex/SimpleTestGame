#pragma once

#include <SFML/Graphics.h>

static sfVideoMode mode;
static sfEvent event;

sfRenderWindow* window;

void init_window();
void destroy_window();
