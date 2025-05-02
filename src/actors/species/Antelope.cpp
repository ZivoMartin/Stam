#include "Lion.hpp"
#include "Antelope.hpp"
#include "../behaviors/Wanderer.hpp"

Antelope::Antelope(Config& config, vec2f pos):
	Movable(config, pos, size, speed, SDL_Color {0, 255, 0, 255}) {
}


void Antelope::process(Context& ctx) {	
	Movable::process(ctx);
}

void Antelope::accept(Detector* visitor) {
	visitor->check(*this);
}


void Antelope::init_behaviors() {
    add_behavior<Wanderer>(this);
}
