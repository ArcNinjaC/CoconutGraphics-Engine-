#pragma once
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cmath>

namespace CoconutGraphics {

	class Window {
		const int width, height;
		const char* title_caption;

		bool RUNNING = false;

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

	public :
		Window(int w_width = 100, int w_height = 100, const char* caption = "SDL WINDOW") :
			width(w_width),
			height(w_height),
			title_caption(caption)
		{}

		bool get_current_state() {
			return RUNNING;
		}

		void draw_triangle(projected_triangle_data shape) {
			floor(255 * shape.color.x);
			SDL_Color color = SDL_Color{ 
				(unsigned char)(255 * shape.color.x),
				(unsigned char)(255 * shape.color.x) ,
				(unsigned char)(255 * shape.color.x) };
		}

		void start() {
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				std::cout << "SDL could not be initialized: " << SDL_GetError() << '\n';
			}
			else {
				std::cout << "SDL HAS SUCCESSFULLY INITIALIZED" << '\n';
			}

			window = SDL_CreateWindow(title_caption, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

			if (window) {
				std::cout << "Window successfully created" << '\n';
				SDL_SetWindowMinimumSize(window, 100, 100);
			}

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
				std::cout << "Renderer successfully created" << '\n';
				RUNNING = true;
			}

		}

		void end() {

			RUNNING = false;

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
		}
	};
}