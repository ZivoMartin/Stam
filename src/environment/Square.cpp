#include "Square.hpp"
#include "SDL2/SDL_image.h"

Square::Square(SDL_Texture* tex) : tex(tex) {}

Square::Square(SDL_Color c) : c(c) {}

Square::~Square() {
	if (tex) SDL_DestroyTexture(tex);
}

void Square::render(SDL_Renderer* ren, SDL_Rect* src, SDL_Rect* dest) const {
    if (tex) 
		SDL_RenderCopy(ren, tex, src, dest);
	else {
		SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
		SDL_RenderFillRect(ren, dest);
	}
}
