#pragma once

#include "entity.h"

class Projectile : public Entity {
public:
	Projectile(float x, float y);

	void update() override;
	void render() override;
};
