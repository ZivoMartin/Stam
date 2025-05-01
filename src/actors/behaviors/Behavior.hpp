#ifndef __BEHAVIOR__
#define __BEHAVIOR__

#include "../bricks/Entity.hpp"
#include "../bricks/Movable.hpp"

class Behavior {

public:
	virtual void behave(Entity* e) = 0;
	virtual ~Behavior() = default;
};



#endif // __BEHAVIOR__
