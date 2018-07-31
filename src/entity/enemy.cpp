#include "enemy.h"
#include "../level.h"
#include "projectile.h"
#include "spawner/particle_spawner.h"

Enemy::Enemy(float x, float y, Level* level)
	: Ship(x, y), level(level)
{
}

void Enemy::update()
{
	sprite->position.y -= 0.1f;

	for (unsigned int i = 0; i < level->projectiles.size(); i++) {
		if (((Projectile*)level->projectiles[i])->collision(this)) {
			remove();

			new ParticleSpawner(sprite->position.x, sprite->position.y, 100, level);
			level->layer->remove(level->projectiles[i]->getSprite());
			level->projectiles.erase(level->projectiles.begin() + i);
		}
	}

	if (sprite->position.y <= -10.0f) {
		remove();
	}
}

void Enemy::render()
{
}
