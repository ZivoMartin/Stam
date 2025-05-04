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

        std::vector<Square> row;
        for (char c : line) {
            if (c < '0' || c > '2') {
                std::cerr << "Invalid character in the map : '" << c << "'\n";
                std::exit(1);
            }
            row.push_back(Square(c - '0'));
        }

        map.push_back(std::move(row));
    }

    if (map.empty()) {
        std::cerr << "Empty file or invalid map.\n";
        std::exit(1);
    }
}



void Map::render(SDL_Renderer* ren, Context& ctx) const {
	
}

Square Map::get(int i, int j) const {
	return map[i][j];
}
