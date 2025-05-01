#ifndef __WANDERER__
#define __WANDERER__

#include "Config.hpp"
#include "RandomNumberGenerator.hpp"
#include "Movable.hpp"
#include "vec2.hpp"
#include <SDL2/SDL.h>
#include <random>

class Wanderer : public Movable {

public:
	Wanderer(Config& config, vec2f pos);
	
	virtual void process() override;

private:
	void change_dir();
	
	int target_changer;

	inline static const vec2f default_size = vec2f(30, 30);
	inline static const SDL_Color default_color = SDL_Color { 0, 255, 0, 255 };
	inline static RandomNumberGenerator dir_duration_gen = RandomNumberGenerator(0, 100);
};

#endif
