#pragma once

#include "entity.h"

class Star : public Entity {
private:
	float xa;
	float ya;
public:
	Star(float x, float y);

	void update() override;
	void render() override;
};
