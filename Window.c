#include "Window.h"

void init_window() {

	mode = (sfVideoMode){ 800, 600, 32 };

	window = sfRenderWindow_create(mode, "Mutar", sfClose, NULL);

	sfRenderWindow_setMouseCursorVisible(window, sfFalse);

}

void destroy_window() {

	sfRenderWindow_destroy(window);

}