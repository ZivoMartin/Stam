#include "Square.hpp"
#include "SDL2/SDL_image.h"

Square::Square(SDL_Renderer* ren, std::string& path) {
	SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
		SDL_Log("IMG_Load failed: %s", IMG_GetError());
		return;
	}
    this->tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
}


Square::Square(SDL_Color c) : c(c) {}

Square::~Square() {
	if (tex) SDL_DestroyTexture(tex);
}

void Square::render(SDL_Renderer* ren, SDL_Rect r) {
    if (tex) 
		SDL_RenderCopy(ren, tex, NULL, &r);
	else {
		SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
		SDL_RenderFillRect(ren, &r);
	}
}
