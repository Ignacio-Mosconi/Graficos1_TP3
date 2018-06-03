#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include "State.h"
#include "Player.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "HUD.h"

class Game : public State
{
private:
	Player* _player;
	Bullet* _pBullets;
	Asteroid* _asteroids[ASTEROIDS];
	Spaceship* _spaceships[SPACESHIPS];
	HUD* _hud;

	bool _gameOver;
	bool _quited;
	bool _paused;
	int _score;

	bool collide(Entity* a, Entity* b);
	void playerEnemyCollision(Player* p, Enemy* e);
	void bulletEnemyCollision(Bullet* b, Enemy* e);

	void pause();
	void resume();

protected:
	void input();
	void update(float elapsed);
	void draw() const;

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();

	bool quited() { return _quited; }
};

#endif

