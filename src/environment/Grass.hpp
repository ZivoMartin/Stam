#ifndef __GRASS__
#define __GRASS__

#include "Square.hpp"

class Grass : public Square {

public:
	Grass() : Square(SDL_Color {
			.r = 0,
			.g = 200,
			.b = 0,
			.a = 255
		}) {}
	
};


#endif
