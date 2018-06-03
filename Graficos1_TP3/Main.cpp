#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "Menu.h"
#include "Game.h"
#include "GameOver.h"
#include "Definitions.h"
using namespace std;

int main(int argc, char** argv)
{
	ALLEGRO_DISPLAY* display;
	Game* game;
	Menu* menu;
	GameOver* gameOver;

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

	if (!al_install_audio())
	{
		cerr << "Error installing audio." << endl;
		return 1;
	}

	if (!al_init_acodec_addon())
	{
		cerr << "Error initializing Allegro acodec." << endl;
		return 1;
	}

	menu = new Menu(display);
	game = new Game(display);
	gameOver = new GameOver(display);

	while (!menu->quited() && !game->quited() && !gameOver->quited())
	{
		menu->show();
		if (menu->started())
		{
			menu->setStarted(false);
			gameOver->setWentBack(false);
			while (!game->quited() && !gameOver->wentBack() && !gameOver->quited())
			{ 
				game->run();
				if (!game->quited())
				{
					gameOver->show(game->getHighestScore());
					gameOver->setRestarted(false);
				}
			}
		}
	}

	al_destroy_display(display);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_uninstall_audio();
	delete menu;
	delete game;
	delete gameOver;
	return 0;
}