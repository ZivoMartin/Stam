#include "Lion.hpp"
#include "Antelope.hpp"
#include "../behaviors/Wanderer.hpp"
#include "../../util/Detector.hpp"

Lion::Lion(Config& config, vec2f pos):
	Movable(config, pos, size, speed, SDL_Color {255, 0, 0, 255}) {
}


void Lion::process(Context& ctx) {
	Movable::process(ctx);
	Detector d(ctx, *this);
	Detected detected = d.get(SpecieAntelope);
	if (d.detected(SpecieAntelope) && detected.dist <= sight_range) {
		remove_behavior<Wanderer>();
		go_to_by_target(detected.elt->get_pos());
	} else 
		add_behavior<Wanderer>(this);
	

}

void Lion::init_behaviors() {
    add_behavior<Wanderer>(this);
}

Specie Lion::get_specie() {
	return SpecieLion;
}
