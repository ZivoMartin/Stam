#ifndef __CONFIG__
#define __CONFIG__

#include "vec2.hpp"
#include "../random_generators/RandomNumberGenerator.hpp"
#include "../random_generators/RandomPositionGenerator.hpp"

class Config {
	
public:
	Config(int tile_size, vec2i map_dim)
		: tile_size(tile_size), map_dim(map_dim), posgen(map_dim), dirgen(0, 360) {}
    Config() = default;

    const int tile_size;

	int random_dir() {
		return dirgen.random_number();
	}
	
	vec2f random_pos() {
		return posgen.random_position();
	}

	bool is_valid_pos(vec2f pos) {
		return pos.x < map_dim.x && pos.y < map_dim.y && pos.x >= 0 && pos.y >= 0;
	}
    
    bool is_valid_pos(vec2f pos, float limit) {
		return pos.x < map_dim.x && pos.y < map_dim.y && pos.x >= -limit && pos.y >= -limit;
	}

    const vec2i& get_map_dim() const {
        return map_dim;
    }

private:
    vec2i map_dim;
	RandomPositionGenerator posgen;
	RandomNumberGenerator dirgen;	
};


#endif
