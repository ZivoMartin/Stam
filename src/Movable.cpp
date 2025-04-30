#include "Movable.hpp"

Movable::Movable(vec2f pos, vec2f size, SDL_Color color) :
	Entity(pos, size, color), target(pos) {}

Movable::Movable(vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path) :
	Entity(pos, size, ren, sprite_path), target(pos) {}

void Movable::process() {
	this->pos = pos.move(this->target, this->speed);
	
}

