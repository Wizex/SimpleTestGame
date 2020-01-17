#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>

static int inited_UI;
static int inited_world;

static void init();
static void init_miscs();
static void destroy();

void start_game();