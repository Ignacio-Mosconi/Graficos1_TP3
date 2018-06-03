#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "Menu.h"
#include "Game.h"
#include "Definitions.h"
using namespace std;

int main(int argc, char** argv)
{
	ALLEGRO_DISPLAY* display;
	Game* game;
	Menu* menu;

	if (!al_init())
	{
		cerr << "Error initializing Allegro." << endl;
		return 1;
	}

	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!display)
	{
		cerr << "Error creating display." << endl;
		return 1;
	}

	if (!al_install_keyboard())
	{
		cerr << "Error installing keyboard." << endl;
		return 1;
	}

	if (!al_install_mouse())
	{
		cerr << "Error installing mouse." << endl;
		return 1;
	}

	if (!al_init_image_addon())
	{
		cerr << "Error initializing Allegro Image." << endl;
		return 1;
	}

	if (!al_init_font_addon())
	{
		cerr << "Error initializing Allegro Font." << endl;
		return 1;
	}

	if (!al_init_ttf_addon())
	{
		cerr << "Error initializing Allegro TTF." << endl;
		return 1;
	}
	menu = new Menu(display);
	game = new Game(display);

	while (!menu->quited())
	{
		menu->show();
		if (menu->started())
		{
			menu->setStarted(false);
			game->run();
		}
	}

	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	return 0;
}