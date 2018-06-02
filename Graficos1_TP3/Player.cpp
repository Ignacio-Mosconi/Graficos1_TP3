#include "Player.h"

Player::Player(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	_bullets = new Bullet[BULLETS];
	_lives = PLAYER_LIVES;
	_speed = PLAYER_SPEED;
	_shotCooldown = 0;
}

Player::~Player()
{
	delete[] _bullets;
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

void Player::shoot(float elapsed)
{
	if (_shotCooldown <= 0)
	{
		Bullet* pAux = _bullets;
		_shotCooldown = PLAYER_SHOT_COOLDOWN;
		for (int i = 0; i < BULLETS; i++)
		{
			if (!pAux->isEnabled())
			{
				pAux->setPosition(_x + PLAYER_WIDTH, _y + PLAYER_HEIGHT / 2);
				pAux->enable();
				break;
			}
			pAux++;
		}
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

	if (al_key_down(&keyState, ALLEGRO_KEY_S))
		shoot(elapsed);
	_shotCooldown -= elapsed;
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