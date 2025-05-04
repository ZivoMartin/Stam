#ifndef __GROUND__
#define __GROUND__

#include "Square.hpp"

class Ground : public Square {

public:
	Ground(SDL_Renderer* ren) : Square(ren, "../../res/Ground.png") {}
	
};


#endif
