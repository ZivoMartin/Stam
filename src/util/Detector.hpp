#ifndef __DETECTOR__
#define __DETECTOR__

#include "../actors/bricks/Entity.hpp"
#include "../actors/species/Specie.hpp"
#include "Context.hpp"
#include <map>

class Antelope;
class Lion;

struct Detected {
	Detected(Entity* elt, float dist): elt(elt), dist(dist) {}
	Detected() = default;
	Entity* elt;
	float dist;
};

class Detector {

public:

	Detector(Context& ctx, Entity& detector) {
		for (auto& e : ctx.entities) {
			float d = e->get_pos().dist(detector.get_pos());
			Specie s = e->get_specie();
			if (!detected(s) || detected_map[s].dist > d)
				detected_map[s] = Detected(e.get(), d);
				
		}
	}

	bool detected(Specie s) {
		return detected_map.find(s) != detected_map.end();
	}

	Detected get(Specie s) {
		return detected_map[s];
	}
	
	std::map<Specie, Detected> detected_map;

};


#endif // __DETECTOR__
