#include "EventManager.hpp"

EventManager::EventManager()
    : running(true), cam_position(vec2i(0, 0)), mouse_pressed(false) {}

void EventManager::process() {
    SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			running = false; break;
        case SDL_MOUSEMOTION:
            if (mouse_pressed) {
                cam_position += vec2i(e.motion.xrel, e.motion.yrel);
                printf("Bonjour : la souris se déplace à (%d, %d)\n", e.motion.x, e.motion.y);

                break;
            }
        case SDL_MOUSEBUTTONDOWN:
            if (e.button.button == SDL_BUTTON_LEFT) mouse_pressed = true; break;
        case SDL_MOUSEBUTTONUP:
            if (e.button.button == SDL_BUTTON_LEFT) mouse_pressed = false; break;
		default:;
		}
	}
}


const vec2i& EventManager::get_cam_position() const {
    return cam_position;
}

bool EventManager::is_running() const {
    return running;
}
