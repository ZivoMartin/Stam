#ifndef __MOVABLE_BEHAVIOR__
#define __MOVABLE_BEHAVIOR__

#include "Behavior.hpp"
#include "../bricks/Entity.hpp"
#include "../bricks/Movable.hpp"
#include <iostream>

class MovableBehavior : public Behavior {

public:
	virtual ~MovableBehavior() = default;

protected:
	MovableBehavior(Entity* e)
        : Behavior(e) {
		this->e = dynamic_cast<Movable*>(e);
        if (!this->e)
            throw std::runtime_error("WanderBehavior requires a Movable entity");
	}
	
	Movable* e;
};



#endif // __MOVABLE_BEHAVIOR__
