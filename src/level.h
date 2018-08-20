#pragma once

#include <vector>
#include "lowg/window.h"
#include "lowg/layer.h"

class Entity;
class Ship;
class Player;
class Enemy;
class ParticleSpawner;

class Level {
	friend class Player;
	friend class Enemy;
	friend class ParticleSpawner;
private:
	lowg::Window* window;
	Ship* player;
	lowg::Layer* layer;

	float timer;
	float enemySpawnDelay;
	bool gameOver;

	std::vector<Entity*> entities;
	std::vector<Entity*> stars;
	std::vector<Entity*> enemies;
	std::vector<Entity*> projectiles;
	std::vector<Entity*> particles;
public:
	Level(lowg::Window* window);
	~Level();

	void update();
	void render();

	void addEntity(Entity* entity);
	void addProjectile(Entity* entity);
	void addParticle(Entity* particle);

	bool isGameOver() const { return gameOver; }
};
