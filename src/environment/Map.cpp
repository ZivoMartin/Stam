#include "Watter.hpp"
#include "Ground.hpp"
#include "Grass.hpp"

#include "Map.hpp"
#include <fstream>
#include <iostream>

Map::Map(Config& config) : config(config) {
	fprintf(stderr, "TODO: Random map\n");
	exit(1);
}

Map::Map(Config& config, const std::string& path) : config(config) {
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
				s = std::make_unique<Ground>(ren); break;
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
	int i = ctx.cam_position.x / tiles_size, j = ctx.cam_position.y / tiles_size;
	int dx = ctx.cam_position.x % tiles_size, dy = ctx.cam_position.y % tiles_size;
	
	while (config.is_valid_pos(vec2f(i, j) * tiles_size)) {
		while (config.is_valid_pos(vec2f(i, j) * tiles_size)) {
		    SDL_Rect r = {
				.x = tiles_size * i - dx,
				.y = tiles_size * j - dy,
				.w = tiles_size,
				.h = tiles_size,
			};
			map[i][j]->render(ren, r);
			j += 1;
		}
		i += 1;
		j = ctx.cam_position.y / tiles_size;
	}
}

