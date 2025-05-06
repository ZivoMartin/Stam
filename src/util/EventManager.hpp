#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__

#include "Config.hpp"
#include "vec2.hpp"
#include <SDL2/SDL.h>

class EventManager {

public:
    explicit EventManager(Config& config);
    void process(SDL_Window* w);
    const vec2i& get_cam_position() const;
    bool is_running() const;
    
private:
    bool running;
    vec2i cam_position;
    bool mouse_pressed;
    Config& config;
};

#endif
