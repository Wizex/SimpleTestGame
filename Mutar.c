#include "Mutar.h"
#include "World.h"
#include "UI_Main_Menu.h"
#include "Audio.h"
#include "HUD.h"
#include "Window.h"
#include "Mouse.h"
#include "GLOBAL_GAME_INFO.h"
#include <SFML/System/Clock.h>
#include <stdio.h>

void init(){

	init_audio();

	init_miscs();

	init_window();

}

void init_miscs() {

	init_cursor();

	game_stage = MAIN_MENU;

	audio_state = ON;
	music_state = ON;
	window_mode_state = ON;

	inited_UI = 0;
	inited_world = 0;

	is_mouse_pressed = 0;

}

void start_game(){

    init();

	sfMusic_play(main_audio);

	sfClock* clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)){

		float time = sfClock_getElapsedTime(clock).microseconds;

		sfClock_restart(clock);

		time /= 5000;

		sfEvent event;

        while (sfRenderWindow_pollEvent(window, &event)){

            if (event.type == sfEvtClosed)

                sfRenderWindow_close(window);

        }

        sfRenderWindow_clear(window, sfBlack);
		
		switch (game_stage) {

			case MAIN_MENU:

				if (inited_UI == 0) {

					if (inited_world == 1) {

						destroy_world();

						destroy_HUD();

					}

					init_UI(window);

					inited_UI = 1;
					
					inited_world = 0;

				}

				show_UI(window, &event);

				break;

			case GAME:

				if (inited_world == 0) {

					destroy_UI();

					create_world();

					init_HUD();

					inited_world = 1;

					inited_UI = 0;

				}

				show_world(window, &event, &time);
				show_HUD(window, &event, player.health_points);

				break;

			default:

				break;

		}

		show_cursor(window);

        sfRenderWindow_display(window);

    }

    destroy();

}

void destroy() {

	if (inited_UI)

		destroy_UI();

	if (inited_world) {

		destroy_HUD();
		destroy_world();

	}

	destroy_window();

	destroy_cursor();

}
