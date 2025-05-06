#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <SDL2/SDL.h>
#include "../species/Specie.hpp"
#include "../../util/vec2.hpp"
#include "../../util/Config.hpp"
#include "../../util/Context.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Behavior;

class Entity {

public:
	Entity() = delete;
	
	virtual ~Entity();
	virtual void process(Context& ctx);
	virtual void render(Context& ctx, SDL_Renderer* ren);
	virtual void init_behaviors();
	virtual Specie get_specie() = 0;
	
	vec2f get_pos() const;
	vec2f get_size() const;
	Config& get_config() const;
	
protected:
	Entity(Config& config, vec2f pos, vec2f size, SDL_Color color);
	Entity(Config& config, vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path);

	template<typename T, typename... Args>
	void add_behavior(Args&&... args) {
		if (!std::any_of(behaviors.begin(), behaviors.end(), [](const auto& b) {
			return dynamic_cast<T*>(b.get()) != nullptr;
		})) behaviors.push_back(std::make_unique<T>(std::forward<Args>(args)...));
	}

	template<typename T>
	void remove_behavior() {
		behaviors.erase(std::remove_if(behaviors.begin(), behaviors.end(), [](const auto& b) { return dynamic_cast<T*>(b.get()) != nullptr; }),
						behaviors.end());
	}

	
	SDL_Color color;
	SDL_Texture* sprite;
	vec2f pos;
	vec2f size;

	Config& config;
	std::vector<std::unique_ptr<Behavior>> behaviors;
	

};


#endif
