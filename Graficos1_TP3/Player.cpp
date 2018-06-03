#include "Player.h"

Player::Player(int x, int y, const char* imagePath) : Entity(x, y, imagePath)
{
	_bullets = new Bullet[BULLETS];
	_shotSound = al_load_sample(SHOT_SOUND_PATH);
	_explosionSound = al_load_sample(EXPLOSION_SOUND_PATH);

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
	int distance = _speed * elapsed;
	switch (direction)
	{
		case LEFT:
			if (_x - distance > PLAYER_MIN_X)
				_x -= distance;
			else
				_x = PLAYER_MIN_X;
			break;
		case RIGHT:
			if (_x + PLAYER_WIDTH + distance < PLAYER_MAX_X)
				_x += distance;
			else
				_x = PLAYER_MAX_X - PLAYER_WIDTH;
			break;
		case UP:
			if (_y + distance > PLAYER_MIN_Y)
				_y -= distance;
			else
				_y = PLAYER_MIN_Y;
			break;
		case DOWN:
			if (_y + PLAYER_HEIGHT + distance < PLAYER_MAX_Y)
				_y += _speed * elapsed;
			else
				_y = PLAYER_MAX_Y - PLAYER_HEIGHT;
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
				al_play_sample(_shotSound, 1, ALLEGRO_AUDIO_PAN_NONE, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
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
		move(LEFT, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		move(RIGHT, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_UP))
		move(UP, elapsed);
	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN))
		move(DOWN, elapsed);

	if (al_key_down(&keyState, ALLEGRO_KEY_S))
		shoot(elapsed);
	_shotCooldown -= elapsed;
}

void Player::die()
{
	_lives--;
	al_play_sample(_explosionSound, 1, ALLEGRO_AUDIO_PAN_NONE, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
	if (_lives > 0)
		respawn();
}

void Player::respawn()
{
	_x = PLAYER_INITIAL_X;
	_y = SCREEN_HEIGHT / 2;
}