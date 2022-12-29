#pragma once
#include "shapes.h"
#include "camera.h"
#include "window.h"
#include "rendering.h"
#include <vector>

namespace CoconutGraphics {
	struct scene_data {
		// storing all the objects in our scene
		std::vector<mesh> objects;

		camera camera;
		vector3 light_dir;
		double CLOSE_UP;

		scene_data(std::vector<mesh> objs = {}) : objects(objs) {}

		int render(int width, int height) {
			return 0;
		}
	};

	class scene {
	protected : 
		bool running = false;
		scene_data MyScene;
		void handleEvents() {}
		void onFrame(double time, double dt) {}

		void renderSelf(Window &window) {
			std::vector<projected_triangle_data> drawing_data = getSceneProjectedTriangleData(MyScene);
			for (projected_triangle_data Triangle : drawing_data) {
				window.draw_triangle(Triangle);
			}


		}

	public:
		void run(int fps, int width, int height, const char* title) {
			running = true;

			Window window = Window(width, height, title);

			double delta_time = 1 / (double)fps;
			double time = 0;


			// game loop
			window.start();
			while (running) {

				SDL_Event event;
				SDL_PollEvent(&event);

				renderSelf(window);

				if (event.type == SDL_QUIT) {
					running = false;
				}
				handleEvents();

				onFrame(time, delta_time);

				SDL_Delay((delta_time * 1000));
				time += delta_time;
			}
			window.end();
		}
	};
}