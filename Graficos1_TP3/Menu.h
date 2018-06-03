#ifndef MENU_H
#define MENU_H

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "State.h"
using namespace std;

class Menu : public State
{
private:
	ALLEGRO_FONT* _titleFont;
	ALLEGRO_FONT* _optionsFont;

	string _titleText;
	string _optionsText[MENU_OPTIONS];

	int _optionsTextX[MENU_OPTIONS];
	int _optionsTextY[MENU_OPTIONS];

	int _mouseX;
	int _mouseY;

	bool _selected[MENU_OPTIONS];
	bool _clicked;
	bool _started;
	bool _quited;

	bool isMouseOverText(ALLEGRO_FONT* font, const string& text, const int index);

protected:
	void input();
	void update(float elapsed);
	void draw() const;

public:
	Menu(ALLEGRO_DISPLAY* display);
	~Menu();

	void show();

	inline bool started() { return _started; }
	inline bool quited() { return _quited; }
	void setStarted(bool started) { _started = started; }
};

#endif
