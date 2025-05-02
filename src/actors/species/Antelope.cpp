#include "Antelope.hpp"
#include "../behaviors/Wanderer.hpp"

Antelope::Antelope(Config& config, vec2f pos):
	Movable(config, pos, size, SDL_Color {0, 255, 0, 255}) {
	add_behavior<Wanderer>(this);
}


void Antelope::process() {
	Movable::process();
}

