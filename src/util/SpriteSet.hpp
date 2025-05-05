#ifndef __SPRITE_SET__
#define __SPRITE_SET__

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "vec2.hpp"
#include "Config.hpp"

enum Sprite {
    SpriteGround
};

class SpriteSet {

public:
    SpriteSet() = default;
    
    void init(Config& config, SDL_Renderer* ren) {
        build("Ground.png", SpriteGround, ren, vec2i(config.tile_size, config.tile_size));
    }
    
    SDL_Texture* get(Sprite s) {
        return map[s];
    }
    
private:
    void build(const std::string& path, Sprite s, SDL_Renderer* ren, vec2i dim) {
        SDL_Surface* surface = IMG_Load(("res/" + path).c_str());
        if (!surface) {
            SDL_Log("IMG_Load failed: %s", IMG_GetError());
            std::exit(1);
        }
        SDL_Texture* original = SDL_CreateTextureFromSurface(ren, surface);
        if (!original) {
            SDL_Log("CreateSurface failed: %s", IMG_GetError());
            std::exit(1);            
        }

        SDL_FreeSurface(surface);
        SDL_Texture* square = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, dim.x, dim.x);
        if (!square) {
            SDL_Log("CreateTexture failed: %s", IMG_GetError());
            SDL_DestroyTexture(original);
            std::exit(1);
        }

        SDL_SetRenderTarget(ren, square);
        SDL_RenderClear(ren);

        SDL_Rect dest = {0, 0, dim.x, dim.y};
        SDL_RenderCopy(ren, original, NULL, &dest);

        SDL_SetRenderTarget(ren, NULL);
        SDL_DestroyTexture(original);

        map[s] =  square;
    }
    
    std::map<Sprite, SDL_Texture*> map;
    
};

#endif // __SPRITE_SET__
