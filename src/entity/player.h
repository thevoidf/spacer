#pragma once

#include "lowg/window.h"
#include "ship.h"
#include "projectile.h"
#include "../level.h"

class Level;

class Player : public Ship {
private:
	lowg::Window* window;
	Level* level;
public:
	Player(float x, float y, Level* level, lowg::Window* window);

	void update() override;
	void render() override;
};
