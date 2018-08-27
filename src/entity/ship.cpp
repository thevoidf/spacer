#include "ship.h"

#include "lowg/texture.h"

Ship::Ship(float x, float y)
	: Entity(x, y)
{
	sprite = new lowg::Sprite(x, y, 4.0f, 4.0f, new lowg::Texture("assets/textures/ship.png", GL_RGBA, GL_BGRA));
}

void Ship::update()
{
}

void Ship::render()
{
}
