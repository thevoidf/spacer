#pragma once

#include <vector>
#include <chrono>
#include "lowg/window.h"
#include "state.h"

class Entity;
class Ship;
class Player;
class Enemy;
class ParticleSpawner;

namespace lowg {
	class Text;
	class Layer;
}

class Level {
	friend class Player;
	friend class Enemy;
	friend class ParticleSpawner;
	friend class Menu;
private:
	lowg::Window* window;
	Ship* player;
	lowg::Layer* layer;
public:
	lowg::Text* gameOverText;
	std::chrono::time_point<std::chrono::high_resolution_clock> timer;
private:	
	float enemySpawnDelay;
	State& state;

	std::vector<Entity*> entities;
	std::vector<Entity*> stars;
	std::vector<Entity*> enemies;
	std::vector<Entity*> projectiles;
	std::vector<Entity*> particles;
public:
	Level(lowg::Window* window, State& state);
	~Level();

	void update();
	void render();

	void addEntity(Entity* entity);
	void addProjectile(Entity* entity);
	void addParticle(Entity* particle);
};
