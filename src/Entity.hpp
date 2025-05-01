#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <SDL2/SDL.h>
#include "vec2.hpp"
#include "Config.hpp"
#include <string>

class Entity {

public:
	Entity() = delete;
	
	virtual ~Entity();
	virtual void process();
	virtual void render(SDL_Renderer* ren);
	
	vec2f get_pos() const;
	vec2f get_size() const;

protected:
	Entity(Config& config, vec2f pos, vec2f size, SDL_Color color);
	Entity(Config& config, vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path);
	
	SDL_Color color;
	SDL_Texture* sprite;
	vec2f pos;
	vec2f size;

	Config& config;

};


#endif
