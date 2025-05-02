#ifndef __BEHAVIOR__
#define __BEHAVIOR__

#include "../bricks/Entity.hpp"
#include "../bricks/Movable.hpp"
#include "../../util/Context.hpp"

class Behavior {

public:
	virtual void behave(Context& ctx) = 0;
	virtual ~Behavior() = default;

protected:
	Behavior(Entity* e) : e(e) {}
	
	Entity* e;
};



#endif // __BEHAVIOR__
