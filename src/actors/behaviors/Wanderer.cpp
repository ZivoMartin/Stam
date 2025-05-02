#include "Wanderer.hpp"
#include <iostream>

Wanderer::Wanderer(Entity* e)
        : MovableBehavior(e) {}

void Wanderer::change_dir() {
	int new_dir = e->get_config().random_dir();
	e->go_to_by_dir(new_dir);
	target_changer = dir_duration_gen.random_number();
}

void Wanderer::behave() {
	printf("%d\n", target_changer);
	if (this->target_changer -- == 0 || !e->is_mobile()) change_dir();	
}

