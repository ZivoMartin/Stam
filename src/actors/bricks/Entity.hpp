#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <SDL2/SDL.h>
#include "../../util/vec2.hpp"
#include "../../util/Config.hpp"
#include <string>
#include <vector>
#include <memory>

class Behavior;

class Entity {

public:
	Entity() = delete;
	
	virtual ~Entity();
	virtual void process();
	virtual void render(SDL_Renderer* ren);
	
	vec2f get_pos() const;
	vec2f get_size() const;
	Config get_config() const;

protected:
	Entity(Config& config, vec2f pos, vec2f size, SDL_Color color);
	Entity(Config& config, vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path);


	template<typename T, typename... Args>
	void add_behavior(Args&&... args) {
		behaviors.push_back(std::make_unique<T>(std::forward<Args>(args)...));
	}

	
	SDL_Color color;
	SDL_Texture* sprite;
	vec2f pos;
	vec2f size;

	Config& config;
	std::vector<std::unique_ptr<Behavior>> behaviors;
	

};


#endif
