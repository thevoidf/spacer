#include "level.h"
#include <iostream>
#include <time.h>
#include "lowg/batchrenderer2d.h"
#include "lowg/shader.h"
#include "entity/star.h"
#include "entity/ship.h"
#include "entity/player.h"
#include "entity/enemy.h"
#include "lowg/text.h"
#include "entity/spawner/particle_spawner.h"

Level::Level(lowg::Window* window, State& state)
	: window(window), state(state)
{
	lowg::Shader* shader = new lowg::Shader("assets/shaders/simple.vert", "assets/shaders/simple.frag");
	layer = new lowg::Layer(new lowg::BatchRenderer2D(), shader, glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
	player = new Player(0.0f, 0.0f, this, window);
	layer->add(player->getSprite());

	timer = std::chrono::high_resolution_clock::now();
	gameOverText = new lowg::Text("Game Over!", -5.0f, 2.0f, glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	enemySpawnDelay = 0.5;

	srand(time(NULL));
}

void Level::update()
{
	int starX = rand() % (16 * 2) - 16;
	int starY = (rand() % (9 * 2) - 9) - 10;

	Entity* star = new Star(starX, starY);
	stars.push_back(star);
	layer->add(star->getSprite());

	for (unsigned int i = 0; i < stars.size(); i++) {
		stars[i]->update();

		if (stars[i]->isRemoved()) {
			layer->remove(stars[i]->getSprite());
			delete stars[i];
			stars.erase(stars.begin() + i);
		}
	}
	
	if (player->isRemoved()) {
		if (state == PLAYING) {
			layer->remove(player->getSprite());
			state = END;
		}
	} else {
		player->update();
	}

	for (unsigned int i = 0; i < entities.size(); i++) {
		Entity* entity = entities[i];
		entity->update();
	}

	if (state == PLAYING) {
		std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - timer;
		if (duration.count() >= enemySpawnDelay) {
			int enemyX = rand() % 16 + (4 - 16);
			Ship* enemy = new Enemy(enemyX, 10.0f, this);
			enemies.push_back(enemy);
			layer->add(enemy->getSprite());

			timer = std::chrono::high_resolution_clock::now();
		}
	}

	for (unsigned int i = 0; i < enemies.size(); i++) {
		Entity* enemy = enemies[i];

		enemy->update();

		if (enemy->isRemoved()) {
			layer->remove(enemy->getSprite());
			delete enemy;
			enemies.erase(enemies.begin() + i);
		}
	}

	for (unsigned int i = 0; i < projectiles.size(); i++) {
		Entity* projectile = projectiles[i];
		projectile->update();

		if (projectile->isRemoved()) {
			layer->remove(projectile->getSprite());
			delete projectile;
			projectiles.erase(projectiles.begin() + i);
		}
	}

	for (unsigned int i = 0; i < particles.size(); i++) {
		Entity* particle = particles[i];
		particle->update();

		if (particle->isRemoved()) {
			layer->remove(particle->getSprite());
			delete particle;
			particles.erase(particles.begin() + i);
		}
	}

	if (window->isKeyDown(GLFW_KEY_ESCAPE))
		state = MENU;

	if (state == END) {
		layer->add(gameOverText);
		state = HOLD;
	} else if (state == HOLD && window->isKeyDown(GLFW_KEY_ENTER)) {
		for (unsigned int i = 0; i < stars.size(); i++) {
			layer->remove(stars[i]->getSprite());
			delete stars[i];
			stars.erase(stars.begin() + i);
		}

		for (unsigned int i = 0; i < enemies.size(); i++) {
			layer->remove(enemies[i]->getSprite());
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}

		player->getSprite()->position.x = 0.0f;
		player->getSprite()->position.y = 0.0f;
		layer->add(player->getSprite());
		player->removed = false;

		layer->remove(gameOverText);

		state = PLAYING;
	}

	// std::cout << "entities: " << entities.size() << std::endl;
	// std::cout << "projectiles: " << projectiles.size() << std::endl;
	// std::cout << "layer: " << layer->getRenderables().size() << std::endl;
	// std::cout << "particles: " << particles.size() << std::endl;
}

void Level::render()
{
	layer->render();
}

void Level::addEntity(Entity* entity)
{
	entities.push_back(entity);
	layer->add(entity->getSprite());
}

void Level::addProjectile(Entity* entity)
{
	projectiles.push_back(entity);
	layer->add(entity->getSprite());
}

void Level::addParticle(Entity* particle)
{
	particles.push_back(particle);
	layer->add(particle->getSprite());
}

Level::~Level()
{
}
