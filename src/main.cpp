#include <iostream>
#include <chrono>
#include "lowg/window.h"
#include "level.h"
#include "menu.h"
#include "state.h"

#define WIDTH 720
#define HEIGHT 640

void log_state(State state);

int main()
{
	lowg::Window window("Spacer", WIDTH, HEIGHT);
	State state = MENU;
	Level level(&window, state);
	Menu menu(&window, level, state);

	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> prev = std::chrono::high_resolution_clock::now();
	int frames = 0;

	float lag = 0.0f;
	float FPS = 20.0f * 1000000.0f;
	while (!window.shouldClose()) {
		window.clear(0.0f, 0.0f, 0.0f, 0.0f);

		std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
		float delta = (now - prev).count();
		prev = now;
		lag += delta;

		if (lag >= FPS) {
			if (state == MENU || state == OPTIONS)
				menu.update();
			else if (state >= PLAYING && state <= HOLD)
				level.update();
			else if (state == EXIT)
				exit(EXIT_SUCCESS);
			window.syncKeys();
			lag -= FPS;
		}

		if (state == MENU || state == OPTIONS)
			menu.render();
		else if (state >= PLAYING && state <= HOLD)
			level.render();

		frames++;
		std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
		if (duration.count() >= 1.0f) {
			std::cout << "Frames: " << frames << std::endl;
			frames = 0;
			start = std::chrono::high_resolution_clock::now();
		}
		window.update();
	}
}

void log_state(State state)
{
	if (state == MENU) std::cout << "MENU" << std::endl;
	if (state == PLAYING) std::cout << "PLAYING" << std::endl;
	if (state == END) std::cout << "END" << std::endl;
	if (state == HOLD) std::cout << "HOLD" << std::endl;
	if (state == OPTIONS) std::cout << "OPTIONS" << std::endl;
	if (state == EXIT) std::cout << "EXIT" << std::endl;
}
