#include "Movable.hpp"

Movable::Movable(Config& config, vec2f pos, vec2f size, SDL_Color color) :
	Entity(config, pos, size, color) {}

Movable::Movable(Config& config, vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path) :
	Entity(config, pos, size, ren, sprite_path) {}

void Movable::process() {
	vec2f new_pos;
	switch (movement.tag) {
	case MovementByTarget:
		new_pos = pos.move_towards(movement.data.target, speed); break;
	case MovementByDir:
		new_pos = pos.moved_at_angle(movement.data.dir, speed); break;
	case MovementStatic:
		new_pos = pos; break;
	}
	if (config.is_valid_pos(new_pos)) 
		this->pos = new_pos;
	
	Entity::process();
}


void Movable::go_to_by_dir(int dir) {
	movement.data.dir = dir;
	movement.tag = MovementByDir;
}


void Movable::go_to_by_target(vec2f target) {
	movement.data.target = target;
	movement.tag = MovementByTarget;
}


bool Movable::is_mobile() {
	switch (movement.tag) {
	case MovementByTarget:
		return pos != movement.data.target;
	case MovementStatic:
		return false;
	case MovementByDir:
		return true;
	}
	fprintf(stderr, "Invalid move tag\n");
	exit(1);
}
