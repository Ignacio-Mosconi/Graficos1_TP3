#include "Game.h"

Game::Game(ALLEGRO_DISPLAY* display) : State(display)
{
	srand(time(0));

	_player = new Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, PLAYER_PATH);
	_hud = new HUD(_display);

	_gameOver = false;
	_score = 0;
}

Game::~Game()
{
	if (_player)
		delete _player;
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
}

void Game::draw()
{
	if (_canDraw)
	{
		_canDraw = false;
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));

		al_draw_bitmap(_player->getSprite(), _player->getX(), _player->getY(), false);
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