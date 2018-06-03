#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "State.h"
using namespace std;

class GameOver : public State
{
private:
	ALLEGRO_FONT* _titleFont;
	ALLEGRO_FONT* _textFont;

	string _gameOverText;
	string _highestScoreText;
	string _restartText;
	string _goBackText;

	bool _restarted;
	bool _wentBack;
	bool _quited;

protected:
	void input();
	void update(float elapsed);
	void draw() const;

public:
	GameOver(ALLEGRO_DISPLAY* display);
	~GameOver();

	void show(int highestScore);

	inline bool quited() { return _quited; }
	inline bool wentBack() { return _wentBack; }
	void setRestarted(bool restarted) { _restarted = restarted; }
	void setWentBack(bool wentBack) { _wentBack = wentBack; }
};

#endif