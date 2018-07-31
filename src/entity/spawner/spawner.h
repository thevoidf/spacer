#pragma once

#include "../entity.h"

class Level;

class Spawner : public Entity {
private:
	unsigned int amount;
	Level* level;
public:
	Spawner(float x, float y, int amount, Level* level);
};
