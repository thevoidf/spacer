#pragma once

#include "../particle.h"
#include "spawner.h"

class ParticleSpawner : public Spawner {
public:
	ParticleSpawner(float x, float y, int amount, Level* level);

	void update() override;
	void render() override;
};
