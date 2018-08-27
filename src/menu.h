#pragma once

#include <vector>
#include "state.h"

class Level;
namespace lowg {
	class Window;
	class Layer;
	class BatchRenderer2D;
	class Text;
}

enum Difficulty { DifficultyEasy = 0, DifficultyNormal };

class Menu {
private:
	lowg::Window* window;
	lowg::Layer* layer;
	lowg::Text* title;
	std::vector<lowg::Text*> items;
	std::vector<lowg::Text*> options;
	int selectedItem;
	Difficulty selectedDifficulty;
	Level& level;
	State& state;
public:
	Menu(lowg::Window* window, Level& level, State& state);

	void update();
	void render();
};
