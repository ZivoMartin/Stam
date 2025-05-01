#include "Wanderer.hpp"
#include <iostream>

Wanderer::Wanderer(Config& config, vec2f pos) :
	Movable(config, pos, default_size, default_color) {
	this->change_dir();
	this->speed = 3;
}

void Wanderer::change_dir() {
	int new_dir = config.random_dir();
	go_to_by_dir(new_dir);
	target_changer = dir_duration_gen.random_number();
}

void Wanderer::process() {
	if (this->target_changer -- == 0 || !this->is_mobile()) change_dir();
	
	Movable::process();
}
