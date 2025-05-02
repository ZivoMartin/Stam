#ifndef __DETECTOR__
#define __DETECTOR__

#include "Entity.hpp"

class Antelope;
class Lion;

class Detector : public Entity {

public:
	Antelope* antelop_detected = nullptr;
	Lion* lion_detected = nullptr;

	void check(Antelope& e);
	void check(Lion& e);

};


#endif // __DETECTOR__
