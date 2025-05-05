#include "Watter.hpp"
#include "Ground.hpp"
#include "Grass.hpp"

#include "Map.hpp"
#include <fstream>
#include <iostream>


Map::Map(Config& config) : config(config) {}

void Map::init(SpriteSet&) {
	fprintf(stderr, "TODO: Random map\n");
	exit(1);
}

void  Map::init(SpriteSet& sprite_set, const std::string& path) {
    void_square = Void();
    
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Failed to open file : " << path << "\n";
        std::exit(1);
    }

    std::string line;
    size_t expected_width = 0;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (expected_width == 0)
            expected_width = line.size();
        else if (line.size() != expected_width) {
            std::cerr << "Every lines should have same length.\n";
            std::exit(1);
        }

        std::vector<std::unique_ptr<Square>> row;
        for (char c : line) {
            if (c < '0' || c > '2') {
                std::cerr << "Invalid character in the map : '" << c << "'\n";
                std::exit(1);
            }
			std::unique_ptr<Square> s;
			switch (c) {
			case '0':
				s = std::make_unique<Ground>(sprite_set.get(SpriteGround)); break;
			case '1':
				s = std::make_unique<Grass>(); break;
			case '2':
				s = std::make_unique<Watter>(); break;
			default:
				std::cerr << "Invalid square code: " << c << "\n";
				std::exit(1);
			}
            row.push_back(std::move(s));
        }

        map.push_back(std::move(row));
    }

    if (map.empty()) {
        std::cerr << "Empty file or invalid map.\n";
        std::exit(1);
    }
}


void Map::render(SDL_Renderer* ren, Context& ctx) const {
    int tile_size = config.tile_size;
    vec2i map_dim = config.get_map_dim();
    vec2i cam_pos = ctx.cam_position;

    int map_i_start = cam_pos.x / tile_size;
    int map_j_start = cam_pos.y / tile_size;

    int offset_x = -cam_pos.x % tile_size;
    int offset_y = -cam_pos.y % tile_size;

    int screen_x = 0;

     int clip_left   = std::max(0, -offset_x);
     int clip_top    = std::max(0, -offset_y);

    for (int map_i = map_i_start, dx = offset_x; config.is_valid_pos(vec2f(dx, 0), tile_size); ++map_i, dx += tile_size, screen_x += tile_size) {
        int screen_y = 0;
        for (int map_j = map_j_start, dy = offset_y; config.is_valid_pos(vec2f(0, dy), tile_size); ++map_j, dy += tile_size, screen_y += tile_size) {

            int clip_right  = std::max(0, (dx + tile_size) - map_dim.x);
            int clip_bottom = std::max(0, (dy + tile_size) - map_dim.y);

            SDL_Rect src = {
                .x = 0,
                .y = 0,
                .w = tile_size - clip_right,
                .h = tile_size - clip_bottom
            };
            SDL_Rect dest = {
                .x = screen_x - clip_left,
                .y = screen_y - clip_top,
                .w = src.w,
                .h = src.h
            };

            if (!map_i) {
                src.x = clip_left;
                src.w -= clip_left;
                dest.x += clip_left;
                dest.w -= clip_left;
            }
            
            if (!map_j) {
                src.y = clip_top;
                src.h -= clip_top;
                dest.y += clip_top;
                dest.h -= clip_top;
            }

            if (map_i >= 0 && map_i < (int)map.size() &&
                map_j >= 0 && map_j < (int)map[map_i].size()) {
                map[map_i][map_j]->render(ren, &src, &dest);
            } else {
                void_square.render(ren, &src, &dest);
            }
        }
    }
}





