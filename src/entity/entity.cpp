#include "entity.h"

Entity::Entity(float x, float y)
	: removed(false)
{
}


bool Entity::collision(Entity* other) const
{
	lowg::Sprite a = *sprite;
	lowg::Sprite b = *other->getSprite();
	
	return a.position.x < b.position.x + b.getSize().x &&
		  a.position.x + a.getSize().x > b.position.x &&
			a.position.y < b.position.y + b.getSize().y &&
			a.getSize().y + a.position.y > b.position.y;
}

Entity::~Entity()
{
}
