#pragma once

#include "ship.h"

class Level;

class Enemy : public Ship {
private:
	Level* level;
public:
	Enemy(float x, float y, Level* level);

	void update() override;
	void render() override;
};
