#ifndef __CONTEXT__
#define __CONTEXT__

#include <vector>
#include <memory>
#include "vec2.hpp"

class Entity;

class Context {

public:
	Context(std::vector<std::unique_ptr<Entity>>& entities,  const vec2i& cam_position) :
		entities(entities), cam_position(cam_position) {}
	
	std::vector<std::unique_ptr<Entity>>& entities;
	const vec2i& cam_position;
	
};


#endif // __CONTEXT__
