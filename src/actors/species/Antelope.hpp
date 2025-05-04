#ifndef __ANTELOPE__
#define __ANTELOPE__

#include <optional>
#include "Specie.hpp"
#include "../bricks/Movable.hpp"
#include "../behaviors/Wanderer.hpp"
#include "../../util/vec2.hpp"

class Antelope : public Movable {

public:
	Antelope(Config& config, vec2f pos);
	
	void process(Context& ctx) override;
	void init_behaviors() override;
	Specie get_specie() override;

private:
	inline static const vec2f size = vec2f(40, 40);
	inline static const float speed = 4.0;
	inline static const float sight_range = 200;

protected:
	
};



#endif // __ANTELOPE__
