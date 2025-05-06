#include "EventManager.hpp"

EventManager::EventManager(Config& config)
    : running(true), cam_position(vec2i(0, 0)), mouse_pressed(false), config(config) {}

void EventManager::process(SDL_Window* w) {
    SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			running = false; break;
        case SDL_MOUSEMOTION:
            if (mouse_pressed) cam_position += vec2i(e.motion.xrel, e.motion.yrel);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (e.button.button == SDL_BUTTON_LEFT) mouse_pressed = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (e.button.button == SDL_BUTTON_LEFT) mouse_pressed = false;
            break;
		default:;
		}
	}
    vec2i dim;
    SDL_GetWindowSize(w, &dim.x, &dim.y);
    config.actualise_screen_dim(dim);
}


const vec2i& EventManager::get_cam_position() const {
    return cam_position;
}

bool EventManager::is_running() const {
    return running;
}
