#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#define WINDOW_TITLE "Stam"
#define BG_COLOR 150, 150, 150, 255

#include <vector>
#include <SDL2/SDL.h>
#include "Entity.hpp"

class Application {

public:
	~Application();
	int run();
	bool is_running() const;
	void stop();
	
	static const int window_height = 300;
	static const int window_width = 600;
	
private:
	void process();
	void render();
	
	std::vector<Entity*> entities;
	
	bool running = false;
	SDL_Window* win = 0;
	SDL_Renderer* ren = 0;
};


#endif
