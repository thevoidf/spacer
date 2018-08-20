#include <iostream>
#include "lowg/window.h"
#include "level.h"

#define WIDTH 720
#define HEIGHT 640

int main()
{
	lowg::Window window("Spacer", WIDTH, HEIGHT);
	Level level(&window);

	double start = glfwGetTime();
	int frames = 0;
	while (!window.shouldClose()) {
		window.clear(0.0f, 0.0f, 0.0f, 0.0f);

		// implement game loop
		level.update();
		level.render();

		frames++;
		if (glfwGetTime() - start >= 1.0) {
			std::cout << "Frames: " << frames << std::endl;
			frames = 0;
			start += 1.0;
		}
		
		window.update();
	}
}
