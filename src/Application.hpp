#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#define WINDOW_TITLE "Stam"
#define BG_COLOR 150, 150, 150, 255

#include <memory> 
#include <vector>
#include <SDL2/SDL.h>
#include "actors/bricks/Entity.hpp"
#include "random_generators/RandomPositionGenerator.hpp"
#include "util/Config.hpp"
#include "util/Context.hpp"
#include "util/SpriteSet.hpp"
#include "environment/Map.hpp"
#include "util/EventManager.hpp"

#define TILE_SIZE 100
#define M_WIDTH 1400
#define M_HEIGHT 900

enum AppMode {
	AppTest,
	AppRandom,
	AppCustom
};

class Application {

public:
	explicit Application(AppMode mode);
	~Application();

	void test_init();
	
	int run();
	
private:
	void process();
	void render();
    Context build_context();
    
	std::vector<std::unique_ptr<Entity>> entities;

    SpriteSet sprite_set;
	Config config;
	Map map;
    EventManager event_manager;
	

	SDL_Window* win = 0;
	SDL_Renderer* ren = 0;

};


#endif
