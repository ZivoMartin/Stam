#include "Lion.hpp"
#include "Antelope.hpp"
#include "../behaviors/Wanderer.hpp"
#include "../../util/Detector.hpp"

Antelope::Antelope(Config& config, vec2f pos):
	Movable(config, pos, size, speed, SDL_Color {0, 255, 0, 255}) {
}


void Antelope::process(Context& ctx) {	
	Movable::process(ctx);
	Detector d(ctx, *this);
	Detected detected = d.get(SpecieLion);
	if (d.detected(SpecieLion) && detected.dist <= sight_range) {
		remove_behavior<Wanderer>();
		float angle = get_pos().escape_angle(detected.elt->get_pos());
		go_to_by_dir(angle);
	} else {
		add_behavior<Wanderer>(this);
	}
}


void Antelope::init_behaviors() {
    add_behavior<Wanderer>(this);
}

Specie Antelope::get_specie() {
	return SpecieAntelope;
}
