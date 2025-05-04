#ifndef __MAP__
#define __MAP__

#include "../util/Context.hpp"
#include "../util/Config.hpp"
#include "Square.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <memory>

#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 300

class Map {

public:
	Map(Config& config, const std::string& path);
	Map(Config& config);

	void render(SDL_Renderer* ren, Context& ctx) const;
	
	const int tiles_size = 100; // in pixel

private:
	
	int width = DEFAULT_WIDTH;
	int height = DEFAULT_HEIGHT;
	
	std::vector<std::vector<std::unique_ptr<Square>>> map;
	Config& config;	
	
};


#endif // __MAP__
