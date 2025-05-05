#ifndef __MAP__
#define __MAP__

#include "../util/Context.hpp"
#include "../util/Config.hpp"
#include "../util/SpriteSet.hpp"
#include "Void.hpp"
#include "Square.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <memory>
#include <SDL2/SDL.h>

#define DEFAULT_WIDTH 300
#define DEFAULT_HEIGHT 300

class Map {

public:
	explicit Map(Config& config);
    void init(SpriteSet& sprite_set, const std::string& path);
    void init(SpriteSet& sprite_set);
    
	void render(SDL_Renderer* ren, Context& ctx) const;

private:
	
	int width = DEFAULT_WIDTH;
	int height = DEFAULT_HEIGHT;

    Void void_square;
	std::vector<std::vector<std::unique_ptr<Square>>> map;
	Config& config;	
	
};


#endif // __MAP__
