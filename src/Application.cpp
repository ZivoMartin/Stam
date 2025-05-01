#include "Application.hpp"
#include <SDL2/SDL.h>


Application::Application(AppMode mode) :
    config(Config(vec2(M_WIDTH, M_HEIGHT))){

	if (SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "Failed to init SDL\n");
		return;
	}
	this->win = SDL_CreateWindow(WINDOW_TITLE, 100, 100, config.map_dim.x, config.map_dim.y, 0);
	if (!this->win) {
		fprintf(stderr, "Failed to init Window\n");
		return;
	}
	this->ren = SDL_CreateRenderer(this->win, 0, 0);
	if (!this->ren) {
		fprintf(stderr, "Failed to init ren\n");
		return;
	}
	switch (mode) {
	case AppTest:
		test_init(); break;
	case AppRandom:
		fprintf(stderr, "AppRandom is not ready"); exit(1);
	case AppCustom:
		fprintf(stderr, "AppCustom is not ready"); exit(1);

	}
	
}

void Application::test_init() {

}

const int TARGET_FPS = 60;
const int FRAME_DELAY_MS = 1000 / TARGET_FPS;

int Application::run() {
	this->running = true;
	while (this->is_running()) {
		Uint32 frame_start = SDL_GetTicks();
		
		this->process();
		this->render();
		
		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < FRAME_DELAY_MS) SDL_Delay(FRAME_DELAY_MS - frame_time); 
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
	for (auto& e: entities) e->process();
}

void Application::render() {
	SDL_SetRenderDrawColor(this->ren, BG_COLOR);
	SDL_RenderClear(this->ren);
	for (auto& e: entities) e->render(this->ren);
	SDL_RenderPresent(this->ren);
}

Application::~Application() {
	if (this->win) SDL_DestroyWindow(this->win);
	if (this->ren) SDL_DestroyRenderer(this->ren);
}

