#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	srand(time(0));

	_player = new Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, PLAYER_PATH);
	_pBullets = _player->getBullets();
	for (int i = 0; i < ASTEROIDS; i++)
		_asteroids[i] = new Asteroid(ASTEROID_MAX_X, rand() % (ASTEROID_MAX_Y - ASTEROID_HEIGHT - ASTEROID_MIN_Y + 1) + ASTEROID_MIN_Y,
			ASTEROID_PATH);

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
		pAux++;
	}

	for (int i = 0; i < ASTEROIDS; i++)
	{
		_asteroids[i]->update(elapsed);
		cout << elapsed << endl;
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

void Game::run()
{
	while (!_gameOver)
	{
		input();
		update();
		draw();
	}
}