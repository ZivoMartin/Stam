#include "Application.hpp"
#include "actors/species/Antelope.hpp"
#include "actors/species/Lion.hpp"
#include <SDL2/SDL.h>


Application::Application(AppMode mode) :
    config(Config(TILE_SIZE, vec2i(M_WIDTH, M_HEIGHT))), map(Map(config)), event_manager(EventManager(config)) {

	if (SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "Failed to init SDL\n");
		return;
	}
	this->win = SDL_CreateWindow(WINDOW_TITLE, 100, 100, config.get_screen_dim().x, config.get_screen_dim().y, 0);
	if (!this->win) {
		fprintf(stderr, "Failed to init Window\n");
		return;
	}
	this->ren = SDL_CreateRenderer(this->win, 0, 0);
	if (!this->ren) {
		fprintf(stderr, "Failed to init ren\n");
		return;
	}
    
    sprite_set.init(config, ren);
    map.init(sprite_set, "map.txt");
    config.set_map_dim(map.get_map_dim());

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
	for (int i = 0; i < 10; i++) 
		entities.push_back(std::make_unique<Antelope>(config, config.random_pos()));
	for (int i = 0; i < 10; i++) 
		entities.push_back(std::make_unique<Lion>(config, config.random_pos()));

	for (auto& e: entities) e->init_behaviors();
}

const int TARGET_FPS = 60;
const int FRAME_DELAY_MS = 1000 / TARGET_FPS;

int Application::run() {
	while (event_manager.is_running()) {
		Uint32 frame_start = SDL_GetTicks();
		
		this->process();
		this->render();
		
		Uint32 frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < FRAME_DELAY_MS) SDL_Delay(FRAME_DELAY_MS - frame_time); 
	}
	
	return 0;

}

Context Application::build_context() {
    return Context(entities, event_manager.get_cam_position());    
}

void Application::process() {
    event_manager.process(win);
    Context ctx = build_context();
	for (auto& entitie : entities) entitie->process(ctx);
}

void Application::render() {
	SDL_SetRenderDrawColor(this->ren, BG_COLOR);
	SDL_RenderClear(this->ren);
	
	Context ctx = build_context();
	map.render(ren, ctx);
	for (auto& e: entities) e->render(ctx, this->ren);
	SDL_RenderPresent(this->ren);
}

Application::~Application() {
	if (this->win) SDL_DestroyWindow(this->win);
	if (this->ren) SDL_DestroyRenderer(this->ren);
}

