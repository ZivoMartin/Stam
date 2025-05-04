#ifndef __LION__
#define __LION__

#include "Specie.hpp"
#include "../bricks/Movable.hpp"
#include "../behaviors/Wanderer.hpp"
#include "../../util/vec2.hpp"

class Antelope;

class Lion : public Movable {

public:
	Lion(Config& config, vec2f pos);
	
	void process(Context& ctx) override;
	void init_behaviors() override;
	Specie get_specie() override;
	
private:	
	
	inline static const vec2f size = vec2f(40, 40);
	inline static const int speed = 2;
	inline static const float sight_range = 300;

protected:
	
};



#endif // __LION__
