#ifndef __GROUND__
#define __GROUND__

#include "Square.hpp"

class Ground : public Square {

public:
	explicit Ground(SDL_Texture* tex) : Square(tex) {}
	
};


#endif
