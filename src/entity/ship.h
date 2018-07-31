#pragma once

#include "entity.h"

class Ship : public Entity {
public:
	Ship(float x, float y);

	void update() override;
	void render() override;
};
