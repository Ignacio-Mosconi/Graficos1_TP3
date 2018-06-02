#include "Bullet.h"

Bullet::Bullet()
{
	_sprite = al_load_bitmap(BULLET_PATH);
	_speed = BULLET_SPEED;
	_enabled = false;
}

Bullet::~Bullet()
{

}

void Bullet::update(float elapsed)
{
	if (_enabled)
	{
		if (_x < BULLET_MAX_X)
			_x += _speed * elapsed;
		else
			_enabled = false;
	}
}