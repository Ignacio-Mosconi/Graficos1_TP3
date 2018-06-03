#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
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

	ALLEGRO_SAMPLE* _music;
	ALLEGRO_SAMPLE* _selectSound;
	ALLEGRO_SAMPLE* _gameOverSound;

	bool _gameOver;
	bool _quited;
	bool _paused;
	int _score;
	int _highestScore;

	bool collide(Entity* a, Entity* b);
	void playerEnemyCollision(Player* p, Enemy* e);
	void bulletEnemyCollision(Bullet* b, Enemy* e);

	void pause();
	void resume();
	void reset();

protected:
	void input();
	void update(float elapsed);
	void draw() const;

public:
	Game(ALLEGRO_DISPLAY* display);
	~Game();

	void run();

	inline int getHighestScore() { return _highestScore; }
	inline bool quited() { return _quited; }
};

#endif

