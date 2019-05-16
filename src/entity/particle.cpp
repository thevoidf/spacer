#include "particle.h"
#include <iostream>

Particle::Particle(float x, float y, float xa, float ya, float r, float g, float b)
	: Entity(x, y), xa(xa), ya(ya)
{
	sprite = new lowg::Sprite(x, y, 0.3f, 0.2f, 0.2f, glm::vec4(r, g, b, 1.0f));
	
	sprite->position.x = x;
	sprite->position.y = y;
	sprite->position.z = 0.3f;

	life = rand() % 90 + 5;
}

void Particle::update()
{
	time++;
	sprite->position.x += xa;
	sprite->position.y += ya;

	if (time >= life) remove();
	if (sprite->position.x >= 16.0f || sprite->position.x <= -16.0f || sprite->position.y >= 9.0f || sprite->position.y <= -9.0f) {
		remove();
	}
}

void Particle::render()
{
}
