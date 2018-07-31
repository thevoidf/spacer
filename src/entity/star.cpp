#include "star.h"

Star::Star(float x, float y)
	: Entity(x, y)
{
	xa = 2.0f * ((float) rand() / (float) RAND_MAX) - 1.0f;
	ya = rand() % 1000 / 1000.0f;

	float r = rand() % 1000 / 1000.0f;
	float g = rand() % 1000 / 1000.0f;
	float b = rand() % 1000 / 1000.0f;

	float w = (2.0f * ((float) rand() / (float) RAND_MAX) - 1.0f) / 6.0f;
	sprite = new lowg::Sprite(x, y, w, w, glm::vec4(r, g, b, 1.0f));
}

void Star::update()
{
	glm::vec3 position = sprite->position;

	xa = 2.0f * ((float) rand() / (float) RAND_MAX) - 1.0f;
	ya = rand() % 1000 / 1000.0f;
	
	sprite->position.x += xa / 10.0f;
	sprite->position.y += ya / 10.0f;

	if (position.x >= 16.0f || position.x <= -16.0f || position.y >= 9.0f) {
		remove();
	}
}

void Star::render()
{
}
