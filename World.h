#pragma once

#include <SFML/Graphics.h>
#include "Terrain.h"
#include "Characters.h"
#include "Entity.h"

#define GHOSTS 2

static Character ghosts[GHOSTS];

static Chest chest;

static Player player;

static sfView* view;

static void spawn_characters();
static void terrain_player_collision();

void create_world();
void show_world(sfRenderWindow*, sfEvent*, float*);
void destroy_world();

