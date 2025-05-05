#ifndef __SQUARE__
#define __SQUARE__

#include <string>
#include <SDL2/SDL.h>

#define NUMBER_OF_SQUARE_KIND 3

class Square {

public:
    Square(SDL_Texture* tex);
	explicit Square(SDL_Color c);
	~Square();
	
	void render(SDL_Renderer* ren, SDL_Rect* src, SDL_Rect* dest) const;

private:
	SDL_Texture* tex = nullptr;
	SDL_Color c;
};


#endif // __SQUARE__
