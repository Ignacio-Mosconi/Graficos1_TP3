#include "Player.h"

Player::Player(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	_lives = PLAYER_LIVES;
	_speed = PLAYER_SPEED;
}

Player::~Player()
{

}

void Player::move(Direction direction, float elapsed)
{
	switch (direction)
	{
		case Left:
			if (_x > PLAYER_MIN_X)
				_x -= _speed * elapsed;
			break;
		case Right:
			if (_x + PLAYER_WIDTH < PLAYER_MAX_X)
				_x += _speed * elapsed;
			break;
		case Up:
			if (_y > PLAYER_MIN_Y)
				_y -= _speed * elapsed;
			break;
		case Down:
			if (_y + PLAYER_HEIGHT < PLAYER_MAX_Y)
				_y += _speed * elapsed;
			break;
	}
}

void Player::update(float elapsed)
{
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		move(Left, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		move(Right, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		move(Up, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		move(Down, elapsed);
}

void Player::die()
{
	_lives--;
	if (_lives > 0)
		respawn();
}

void Player::respawn()
{
	_x = SCREEN_WIDTH / 2;
	_y = SCREEN_HEIGHT / 2;
}