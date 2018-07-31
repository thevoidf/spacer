#include "player.h"

Player::Player(float x, float y, Level* level, lowg::Window* window)
	: Ship(x, y), level(level), window(window)
{
}

void Player::update()
{
	float speed = 0.5f;

	if (window->isKeyPressed(GLFW_KEY_A))
		sprite->position.x -= speed;
	if (window->isKeyPressed(GLFW_KEY_D))
		sprite->position.x += speed;
	if (window->isKeyPressed(GLFW_KEY_W))
		sprite->position.y += speed;
	if (window->isKeyPressed(GLFW_KEY_S))
		sprite->position.y -= speed;

	if (window->isKeyDown(GLFW_KEY_SPACE)) {
		level->addProjectile(new Projectile(sprite->position.x, sprite->position.y + 0.5f));
		level->addProjectile(new Projectile(sprite->position.x + 1.2f, sprite->position.y + 2.0f));
		level->addProjectile(new Projectile(sprite->position.x + 2.5f, sprite->position.y + 0.5f));
	}
}

void Player::render()
{
}
