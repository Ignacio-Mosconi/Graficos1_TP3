#ifndef HUD_H
#define HUD_H

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "Definitions.h"
using namespace std;

enum Element
{
	SCORE, LIVES
};

class HUD
{
private:
	ALLEGRO_DISPLAY * _display;
	ALLEGRO_FONT* _hudFont;
	ALLEGRO_FONT* _pausedFont;

	string _scoreText;
	string _livesText;
	string _pausedText;

public:
	HUD(ALLEGRO_DISPLAY* _display);
	~HUD();

	void update(Element element, int amount);
	void draw(const int playerLives, const bool isPaused) const; 
};

#endif
