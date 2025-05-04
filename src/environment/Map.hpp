#ifndef __MAP__
#define __MAP__

#include "../util/Context.hpp"
#include "../util/Config.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

enum Square {
	Ground,
	Grass,
	Water
};

#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 300

class Map {

public:
	Map(Config& config, const std::string& path);
	Map(Config& config);

	void render(SDL_Renderer* ren, Context& ctx) const;
	Square get(int i, int j) const;
	
	const int tiles_size = 100; // in pixel

private:
	
	int width = DEFAULT_WIDTH;
	int height = DEFAULT_HEIGHT;
	
	std::vector<std::vector<Square>> map;
	Config& config;	
	
};


#endif // __MAP__
