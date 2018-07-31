#pragma once

#include "entity.h"

class Particle : public Entity {
private:
	float xa;
	float ya;
	float time;
	float life;
public:
	Particle(float x, float y, float xa, float ya, float r, float g, float b);

	void update() override;
	void render() override;
};
