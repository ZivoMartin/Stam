#ifndef __MOVABLE_H__
#define __MOVABLE_H__
#include <SDL2/SDL.h>
#include "vec2.hpp"
#include "Entity.hpp"
#include <string>

class Movable : Entity {

public:
	Movable() = delete;
	
	virtual void process() override;
	

protected:
	Movable(vec2f pos, vec2f size, SDL_Color color);
	Movable(vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path);

	vec2f target;
	float speed;
};


#endif
