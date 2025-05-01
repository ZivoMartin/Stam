#ifndef __CONFIG__
#define __CONFIG__

#include "vec2.hpp"
#include "../random_generators/RandomNumberGenerator.hpp"
#include "../random_generators/RandomPositionGenerator.hpp"

class Config {
	
public:
	Config(vec2i map_dim)
		: map_dim(map_dim), posgen(map_dim), dirgen(0, 360) {}

	const vec2i map_dim;

	int random_dir() {
		return dirgen.random_number();
	}
	
	vec2f random_pos() {
		return posgen.random_position();
	}

	bool is_valid_pos(vec2f pos) {
		return pos.x < map_dim.x && pos.y < map_dim.y && pos.x >= 0 && pos.y >= 0;
	}

private:
	RandomPositionGenerator posgen;
	RandomNumberGenerator dirgen;	
};


#endif
