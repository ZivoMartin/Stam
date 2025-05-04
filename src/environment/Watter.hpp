#ifndef __WATTER__
#define __WATTER__

#include "Square.hpp"

class Watter : public Square {

public:
	Watter() : Square(SDL_Color {
			.r = 0,
			.g = 0,
			.b = 200,
			.a = 255
		}) {}
	
};


#endif
