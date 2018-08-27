#pragma once

#include "lowg/sprite.h"

class Entity {
public:
	lowg::Sprite* sprite;
	bool removed;
public:
	Entity(float x, float y);
	~Entity();

	virtual void update() = 0;
	virtual void render() = 0;

	inline lowg::Sprite* getSprite() const { return sprite; }
	
	void remove() { removed = true; }
	inline const bool isRemoved() const { return removed; }

	bool collision(Entity* other) const;
};
