#ifndef __ANTELOPE__
#define __ANTELOPE__

#include "../bricks/Movable.hpp"
#include "../behaviors/Wanderer.hpp"
#include "../../util/vec2.hpp"

class Antelope : public Movable {

public:
	Antelope(Config& config, vec2f pos);
	
	void process() override;

private:
	inline static const vec2f size = vec2f(40, 40);
	
};



#endif // __ANTELOPE__
