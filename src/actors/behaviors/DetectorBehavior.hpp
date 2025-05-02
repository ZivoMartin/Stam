#ifndef __DETECTOR_BEHEVIOR__
#define __DETECTOR_BEHEVIOR__

#include "../bricks/Detector.hpp"
#include "Behavior.hpp"
#include "../bricks/Entity.hpp"
#include "../../util/Context.hpp"

class DetectorBehavior : public Behavior {

public:

	DetectorBehavior(Entity* e);
	void behave(Context& ctx) override;

private:
	Detector* e;
};


#endif // __DETECTOR_BEHEVIOR__

