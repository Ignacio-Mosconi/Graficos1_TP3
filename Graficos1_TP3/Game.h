#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include "State.h"
#include "Player.h"
#include "HUD.h"

class Game : public State
{
private:
	Player * _player;
	HUD* _hud;

	bool _gameOver;
	int _score;

protected:
	void input();
	void update();
	void draw();

	bool collide(Entity* a, Entity* b);

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();
};

#endif

