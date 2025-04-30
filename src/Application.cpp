#include "Application.hpp"
#include <SDL2/SDL.h>

int Application::run() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "Failed to init SDL\n");
		return 1;
	}
	this->win = SDL_CreateWindow(WINDOW_TITLE, 100, 100, this->window_width, this->window_height, 0);
	if (!this->win) {
		fprintf(stderr, "Failed to init Window\n");
		return 1;
	}
	this->ren = SDL_CreateRenderer(this->win, 0, 0);
	if (!this->ren) {
		fprintf(stderr, "Failed to init ren\n");
		return 1;
	}

	this->running = true;
	while (this->is_running()) {
		this->process();
		this->render();
	}
	
	return 0;

}

bool Application::is_running() const {
	return this->running;
}

void Application::stop() {
	this->running = false;
}


void Application::process() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			this->stop(); break;
		default:;
		}
	}
	for (Entity* e: this->entities) e->process();
}

void Application::render() {
	SDL_SetRenderDrawColor(this->ren, BG_COLOR);
	SDL_RenderClear(this->ren);
	for (Entity* e: this->entities) e->render(this->ren);
	SDL_RenderPresent(this->ren);
}

Application::~Application() {
	if (this->win) SDL_DestroyWindow(this->win);
	if (this->ren) SDL_DestroyRenderer(this->ren);
}

