#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Definitions.h"

class Entity
{
protected:
	ALLEGRO_BITMAP* _sprite;

	int _x;
	int _y;

public:
	Entity() {};
	Entity(int x, int y, const char* imagePath);
	~Entity();

	ALLEGRO_BITMAP* getSprite() { return _sprite; }
	inline int getX() { return _x; }
	inline int getY() { return _y; }
	void setPosition(int x, int y) { _x = x; _y = y; }
};

#endif

