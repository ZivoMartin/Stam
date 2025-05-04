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
#include "environment/Map.hpp"

#define M_WIDTH 1400
#define M_HEIGHT 900

enum AppMode {
	AppTest,
	AppRandom,
	AppCustom
};

class Application {

public:
	Application(AppMode mode);
	~Application();

	void test_init();
	
	int run();
	bool is_running() const;
	void stop();
	
private:
	void process();
	void render();
	
	Map map;
	std::vector<std::unique_ptr<Entity>> entities;

	Config config;

	vec2i cam_position = vec2i(430, 470);
	bool running = false;
	SDL_Window* win = 0;
	SDL_Renderer* ren = 0;

};


#endif
