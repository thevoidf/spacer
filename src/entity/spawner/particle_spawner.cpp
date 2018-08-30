#include "particle_spawner.h"
#include "lowg/layer.h"
#include "../../level.h"

#include <iostream>

ParticleSpawner::ParticleSpawner(float x, float y, int amount, Level* level)
	: Spawner(x, y, amount, level)
{
	for (int i = 0; i < amount; i++) {
		float xa = 2.0f * ((float) rand() / (float) RAND_MAX) - 1.0f;
		float ya = 2.0f * ((float) rand() / (float) RAND_MAX) - 1.0f;

		Entity* particle = new Particle(x, y, xa, ya, 1.0f, 0.0f, 1.0f);
		level->particles.push_back(particle);
		level->layer->add(particle->getSprite());
	}
}

void ParticleSpawner::update()
{
}

void ParticleSpawner::render()
{
}
