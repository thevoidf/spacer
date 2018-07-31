#include "projectile.h"

#include <iostream>

Projectile::Projectile(float x, float y)
	: Entity(x, y)
{
	sprite = new lowg::Sprite(x, y, 1.5f, 1.5f, new lowg::Texture("/home/void/Pictures/ship.png"));
}

void Projectile::update()
{
	sprite->position.y += 0.5f;

	if (sprite->position.y >= 10.0f) {
		remove();
	}
}

void Projectile::render()
{
}

bool Projectile::collision(Entity* other) const
{
	lowg::Sprite a = *sprite;
	lowg::Sprite b = *other->getSprite();
	
	return a.position.x < b.position.x + b.getSize().x &&
		  a.position.x + a.getSize().x > b.position.x &&
			a.position.y < b.position.y + b.getSize().y &&
			a.getSize().y + a.position.y > b.position.y;
}
