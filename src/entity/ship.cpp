#include "ship.h"

#include "lowg/texture.h"

Ship::Ship(float x, float y)
	: Entity(x, y)
{
	sprite = new lowg::Sprite(x, y, 4.0f, 4.0f, new lowg::Texture("/home/void/Pictures/ship.png"));
}

void Ship::update()
{
}

void Ship::render()
{
}
