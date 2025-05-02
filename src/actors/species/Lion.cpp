#include "Lion.hpp"
#include "Antelope.hpp"
#include "../behaviors/Wanderer.hpp"

Lion::Lion(Config& config, vec2f pos):
	Movable(config, pos, size, speed, SDL_Color {255, 0, 0, 255}) {
}


void Lion::process(Context& ctx) {
	Movable::process(ctx);
}

void Lion::accept(Detector* visitor) {
	visitor->check(*this);
}

void Lion::init_behaviors() {
    add_behavior<Wanderer>(this);
}
