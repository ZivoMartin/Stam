#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#define WINDOW_TITLE "Stam"
#define BG_COLOR 150, 150, 150, 255

#include <memory> 
#include <vector>
#include <SDL2/SDL.h>
#include "Entity.hpp"
#include "RandomPositionGenerator.hpp"
#include "Config.hpp"

#define M_WIDTH 900
#define M_HEIGHT 600

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
	
	std::vector<std::unique_ptr<Entity>> entities;

	Config config;
	
	bool running = false;
	SDL_Window* win = 0;
	SDL_Renderer* ren = 0;

};


#endif
