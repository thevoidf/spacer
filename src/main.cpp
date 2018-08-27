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
	int frames = 0;
	while (!window.shouldClose()) {
		window.clear(0.0f, 0.0f, 0.0f, 0.0f);

		// log_state(state);

		if (state == MENU || state == OPTIONS) {
			menu.update();
			menu.render();
		} else if (state >= PLAYING && state <= HOLD) {
			level.update();
			level.render();
		} else if (state == EXIT) {
			exit(EXIT_SUCCESS);
		}

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
