#include "Entity.h"

Entity::Entity(int x, int y, const char* imagePath)
{
	_sprite = al_load_bitmap(imagePath);
	_x = x;
	_y = y;
}

Entity::~Entity()
{
	al_destroy_bitmap(_sprite);
}