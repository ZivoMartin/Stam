#ifndef __CONTEXT__
#define __CONTEXT__

#include <vector>
#include <memory>

class Entity;

class Context {

public:
	Context(std::vector<std::unique_ptr<Entity>>& entities) : entities(entities) {}
	
	std::vector<std::unique_ptr<Entity>>& entities;
	
};


#endif // __CONTEXT__
