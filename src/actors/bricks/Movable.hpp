#ifndef __MOVABLE_H__
#define __MOVABLE_H__
#include <SDL2/SDL.h>
#include "../../util/vec2.hpp"
#include "Entity.hpp"
#include "../../util/Config.hpp"
#include <string>

enum MovementType {
	MovementByTarget,
	MovementByDir,
	MovementStatic
};

struct Movement {
	MovementType tag;
	union {
		int dir;
		vec2f target;
	} data;
};

class Movable : public Entity {

public:
	Movable() = delete;
	
	virtual void process(Context& ctx) override;

	void go_to_by_target(vec2f pos);	
	void go_to_by_dir(int dir);	
	bool is_mobile();	

protected:
	Movable(Config& config, vec2f pos, vec2f size, float speed, SDL_Color color);
	Movable(Config& config, vec2f pos, vec2f size, float speed, SDL_Renderer* ren, std::string sprite_path);


	Movement movement = {
		.tag = MovementStatic,
		.data = {}
	};

	float speed;
};


#endif
