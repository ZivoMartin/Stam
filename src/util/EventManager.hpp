#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__

#include "vec2.hpp"
#include <SDL2/SDL.h>

class EventManager {

public:
    EventManager();
    void process();
    const vec2i& get_cam_position() const;
    bool is_running() const;
    
private:
    bool running;
    vec2i cam_position;
    bool mouse_pressed;
};

#endif
