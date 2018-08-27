#include "menu.h"

#include <iostream>
#include "lowg/window.h"
#include "lowg/layer.h"
#include "lowg/batchrenderer2d.h"
#include "lowg/text.h"
#include "level.h"

Menu::Menu(lowg::Window* window, Level& level, State& state)
	: window(window), level(level), state(state), selectedItem(0), selectedDifficulty(DifficultyEasy)
{
	using namespace lowg;
	
	Shader* shader = new Shader("assets/shaders/simple.vert", "assets/shaders/simple.frag");
	layer = new Layer(new BatchRenderer2D(), shader, glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	title = new Text("Spacer", -2.0f, 6.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	
	items.push_back(new Text("Play", -2.0f, 3.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
	items.push_back(new Text("Options", -2.0f, 1.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
	items.push_back(new Text("Exit", -2.0f, -1.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
	
	options.push_back(new Text("Difficulty: Easy", -2.0f, 3.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));
	options.push_back(new Text("Back", -2.0f, 1.0f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f)));

	layer->add(title);
	unsigned int i;
	for (i = 0; i < items.size(); i++)
		layer->add(items[i]);
}

void Menu::update()
{
	if (window->isKeyDown(GLFW_KEY_DOWN))
		selectedItem++;
	if (window->isKeyDown(GLFW_KEY_UP))
		selectedItem--;

	if (state == MENU) {
		if (selectedItem == 0 && window->isKeyDown(GLFW_KEY_ENTER))
			state = PLAYING;
		if (selectedItem == 1 && window->isKeyDown(GLFW_KEY_ENTER)) {
			unsigned int i;
			for (i = 0; i < items.size(); i++)
				layer->remove(items[i]);
			for (i = 0; i < options.size(); i++)
				layer->add(options[i]);
			selectedItem = 0;
			state = OPTIONS;
		}
		if (selectedItem == 2 && window->isKeyDown(GLFW_KEY_ENTER))
			state = EXIT;
		
		if (selectedItem < 0)
			selectedItem = items.size() - 1;
		if (selectedItem >= items.size())
			selectedItem = 0;

		for (unsigned int i = 0; i < items.size(); i++)
			items[i]->color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
		items[selectedItem]->color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
	} else if (state == OPTIONS) {

		if (selectedDifficulty >= DifficultyNormal)
			selectedDifficulty = DifficultyEasy;
		else if (selectedDifficulty < DifficultyNormal)
			selectedDifficulty = DifficultyNormal;
		
		if (window->isKeyDown(GLFW_KEY_LEFT)) {
			options[0]->text = "Difficulty: Easy";
			selectedDifficulty = DifficultyEasy;
			level.enemySpawnDelay = 0.5;
		} else if (window->isKeyDown(GLFW_KEY_RIGHT)) {
			options[0]->text = "Difficulty: Normal";
			selectedDifficulty = DifficultyNormal;
			level.enemySpawnDelay = 0.3;
		}

		if (selectedItem == 1 && window->isKeyDown(GLFW_KEY_ENTER)) {
			unsigned int i;
			for (i = 0; i < options.size(); i++)
				layer->remove(options[i]);
			for (i = 0; i < items.size(); i++)
				layer->add(items[i]);
			
			selectedItem = 0;
			state = MENU;
		}
		
		if (selectedItem < 0)
			selectedItem = options.size() - 1;
		if (selectedItem >= options.size())
			selectedItem = 0;

		for (unsigned int i = 0; i < options.size(); i++)
			options[i]->color = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
		options[selectedItem]->color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
	}
}

void Menu::render()
{
	layer->render();
}
