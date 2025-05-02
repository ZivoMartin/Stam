#ifndef __WANDERER__
#define __WANDERER__

#include "../../util/Config.hpp"
#include "../../random_generators/RandomNumberGenerator.hpp"
#include "../bricks/Movable.hpp"
#include "../bricks/Entity.hpp"
#include "MovableBehavior.hpp"
#include "../../util/vec2.hpp"
#include <SDL2/SDL.h>
#include <random>

class Wanderer : public MovableBehavior {

public:
	Wanderer(Entity* e);
	
	void behave() override;

private:
	void change_dir();
	
	int target_changer = 0;
	
	inline static const vec2f default_size = vec2f(30, 30);
	inline static const SDL_Color default_color = SDL_Color { 0, 255, 0, 255 };
	inline static RandomNumberGenerator dir_duration_gen = RandomNumberGenerator(0, 100);
};

#endif
