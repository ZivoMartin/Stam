#ifndef __CONFIG__
#define __CONFIG__

#include "vec2.hpp"
#include "../random_generators/RandomNumberGenerator.hpp"
#include "../random_generators/RandomPositionGenerator.hpp"

class Config {
	
public:
	Config(int tile_size, vec2i map_dim)
		: tile_size(tile_size), screen_dim(map_dim), map_dim(map_dim), posgen(map_dim), dirgen(0, 360) {}
    Config() = default;

    const int tile_size = 100;

	int random_dir() {
		return dirgen.random_number();
	}

	vec2f random_pos() {
		return posgen.random_position();
	}

    void actualise_screen_dim(vec2i dim) {
        screen_dim = dim;
    }

	bool is_valid_map_pos(const vec2f& pos) const {
        return is_valid_pos(map_dim, pos);
	}
    
    bool is_valid_map_pos(const vec2f& pos, float limit) const {
        return is_valid_pos(map_dim, pos, limit);
	}
    
	bool is_valid_screen_pos(const vec2f& pos) const {
        return is_valid_pos(screen_dim, pos);
	}
    
    bool is_valid_screen_pos(const vec2f& pos, float limit) const {
        return is_valid_pos(screen_dim, pos, limit);
	}

    bool is_on_screen(const vec2i& cam_position, const vec2f& pos) {
        return pos.x > cam_position.x && pos.x < cam_position.x + screen_dim.x &&
               pos.y > cam_position.y && pos.y < cam_position.y + screen_dim.y;
    }

    const vec2i& get_screen_dim() const {
        return screen_dim;
    }

    void set_map_dim(vec2i dim) {
        map_dim = dim;
    }

private:
    bool is_valid_pos(const vec2i& dim, const vec2f& pos, int limit) const {
        return pos.x < dim.x && pos.y < dim.y && pos.x >= -limit && pos.y >= -limit;
    }

    bool is_valid_pos(const vec2i& dim, const vec2f& pos) const {
        return pos.x < dim.x && pos.y < dim.y && pos.x >= 0 && pos.y >= 0;
    }

    vec2i screen_dim;
    vec2i map_dim;
	RandomPositionGenerator posgen;
	RandomNumberGenerator dirgen;	
};


#endif
