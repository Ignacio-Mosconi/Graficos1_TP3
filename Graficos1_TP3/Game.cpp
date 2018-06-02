#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	srand(time(0));

	_player = new Player(PLAYER_INITIAL_X, SCREEN_HEIGHT / 2, PLAYER_PATH);
	_pBullets = _player->getBullets();
	for (int i = 0; i < ASTEROIDS; i++)
		_asteroids[i] = new Asteroid(ASTEROID_MAX_X, 
			rand() % (ASTEROID_MAX_Y - ASTEROID_HEIGHT - ASTEROID_MIN_Y + 1) + ASTEROID_MIN_Y, ASTEROID_PATH);
	for (int i = 0; i < SPACESHIPS; i++)
		_spaceships[i] = new Spaceship(SPACESHIP_MAX_X, 
			rand() % (SPACESHIP_MAX_Y - SPACESHIP_HEIGHT - SPACESHIP_MIN_Y + 1) + SPACESHIP_MIN_Y, SPACESHIP_PATH);

	_hud = new HUD(_display);

	_gameOver = false;
	_score = 0;
}

Game::~Game()
{
	if (_player)
		delete _player;
	for (int i = 0; i < ASTEROIDS; i++)
		if (_asteroids[i])
			delete _asteroids[i];
	for (int i = 0; i < SPACESHIPS; i++)
		if (_spaceships[i])
			delete _spaceships[i];
	if (_hud)
		delete _hud;
}

void Game::input()
{
	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, TIMEOUT);

	if (al_wait_for_event_until(_queue, &event, &timeout))
		switch (event.type)
		{
			case ALLEGRO_EVENT_TIMER:
				_canDraw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				_gameOver = true;
				break;
		}
}

void Game::update()
{
	float elapsed = al_get_time() - _timeAtLastFrame;
	_timeAtLastFrame = al_get_time();

	_player->update(elapsed);

	Bullet* pAux = _pBullets;
	for (int i = 0; i < BULLETS; i++)
	{
		pAux->update(elapsed);
		for (int i = 0; i < ASTEROIDS; i++)
			if (pAux->isEnabled() && _asteroids[i]->isEnabled() && collide(pAux, _asteroids[i]))
				bulletEnemyCollision(pAux, _asteroids[i]);
		for (int i = 0; i < SPACESHIPS; i++)
			if (pAux->isEnabled() && _spaceships[i]->isEnabled() && collide(pAux, _spaceships[i]))
				bulletEnemyCollision(pAux, _spaceships[i]);
		pAux++;
	}

	for (int i = 0; i < ASTEROIDS; i++)
	{
		_asteroids[i]->update(elapsed);
		if (_asteroids[i]->isEnabled() && collide(_player, _asteroids[i]))
			playerEnemyCollision(_player, _asteroids[i]);
	}

	for (int i = 0; i < SPACESHIPS; i++)
	{
		_spaceships[i]->update(elapsed);
		if (_spaceships[i]->isEnabled() && collide(_player, _spaceships[i]))
			playerEnemyCollision(_player, _spaceships[i]);
	}
}

void Game::draw() const
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));

		al_draw_bitmap(_player->getSprite(), _player->getX(), _player->getY(), false);

		Bullet* pAux = _pBullets;
		for (int i = 0; i < BULLETS; i++)
		{
			if (pAux->isEnabled())
				al_draw_bitmap(pAux->getSprite(), pAux->getX(), pAux->getY(), false);
			pAux++;
		}

		for (int i = 0; i < ASTEROIDS; i++)
			if (_asteroids[i]->isEnabled())
				al_draw_bitmap(_asteroids[i]->getSprite(), _asteroids[i]->getX(), _asteroids[i]->getY(), false);

		for (int i = 0; i < SPACESHIPS; i++)
			if (_spaceships[i]->isEnabled())
				al_draw_bitmap(_spaceships[i]->getSprite(), _spaceships[i]->getX(), _spaceships[i]->getY(), false);

		_hud->draw();

		al_flip_display();
	}
}

bool Game::collide(Entity* a, Entity* b)
{
	if (a->getX() + al_get_bitmap_width(a->getSprite()) > b->getX() &&
		a->getX() < b->getX() + al_get_bitmap_width(b->getSprite()) &&
		a->getY() + al_get_bitmap_height(a->getSprite()) > b->getY() &&
		a->getY() < b->getY() + al_get_bitmap_height(b->getSprite()))
		return true;
	else
		return false;
}

void Game::playerEnemyCollision(Player* p, Enemy* e)
{
	p->die();
	e->disable();
	_hud->update(LIVES, p->getLives());
	if (p->getLives() == 0)
		_gameOver = true;
}

void Game::bulletEnemyCollision(Bullet* b, Enemy* e)
{
	b->disable();
	e->disable();
	switch (e->getType())
	{
		case ASTEROID:
			_score += ASTEROID_SCORE;
			break;
		case SPACESHIP:
			_score += SPACESHIP_SCORE;
			break;
	}
	_hud->update(SCORE, _score);
}

void Game::run()
{
	while (!_gameOver)
	{
		input();
		update();
		draw();
	}
}