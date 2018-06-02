#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include "State.h"
#include "Player.h"
#include "Asteroid.h"
#include "HUD.h"

class Game : public State
{
private:
	Player* _player;
	Bullet* _pBullets;
	Asteroid* _asteroids[ASTEROIDS];
	HUD* _hud;

	bool _gameOver;
	int _score;

protected:
	void input();
	void update();
	void draw() const;

	bool collide(Entity* a, Entity* b);

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();
};

#endif

