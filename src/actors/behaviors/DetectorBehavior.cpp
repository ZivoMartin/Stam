#include "DetectorBehavior.hpp"
#include <iostream>
#include "../bricks/Detector.hpp"

DetectorBehavior::DetectorBehavior(Entity* e)
	: Behavior(e) {
	this->e = dynamic_cast<Detector*>(e);
	if (!this->e)
		throw std::runtime_error("WanderBehavior requires a Movable entity");

}

void DetectorBehavior::behave(Context& ctx) {
	for (auto& e : ctx.entities) 
		e->accept(this->e);
}

void Detector::check(Antelope& e) {}

void Detector::check(Lion& e) {}
