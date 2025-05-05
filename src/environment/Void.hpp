#ifndef __VOID__
#define __VOID__

#include "Square.hpp"

class Void : public Square {

public:
	Void() : Square(SDL_Color {
			.r = 91,
			.g = 46,
			.b = 2,
			.a = 255
		}) {}
	
};


#endif
