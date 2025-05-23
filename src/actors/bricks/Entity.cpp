#include "Entity.hpp"
#include "../behaviors/Behavior.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>


Entity::Entity(Config& config, vec2f pos, vec2f size, SDL_Color color)
    : color(color), sprite(nullptr), pos(pos), size(size) , config(config) {}


Entity::Entity(Config& config, vec2f pos, vec2f size, SDL_Renderer* ren, std::string sprite_path)
    : pos(pos), size(size), config(config) {
	SDL_Surface* surface = IMG_Load(sprite_path.c_str());
    if (!surface) {
		SDL_Log("IMG_Load failed: %s", IMG_GetError());
		this->sprite = nullptr;
		return;
	}
    this->sprite = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);

}

Entity::~Entity() {
	if (this->sprite) SDL_DestroyTexture(this->sprite);
}

void Entity::process(Context& ctx) {
	for (auto& b : behaviors)
		b->behave(ctx);
}

void Entity::render(Context& ctx, SDL_Renderer* ren) {
    const vec2i& cam_pos = ctx.cam_position;
    
    if (!config.is_on_screen(cam_pos, pos))  return;

	SDL_FRect rect = SDL_FRect {
		.x = this->pos.x - cam_pos.x,
		.y = this->pos.y - cam_pos.y,
		.w = this->size.x,
		.h = this->size.y,
	};

	if (!this->sprite) {
		SDL_SetRenderDrawColor(ren, this->color.r, this->color.g, this->color.b, this->color.a);
		SDL_RenderDrawRectF(ren, &rect);
	} else 
		SDL_RenderCopyF(ren, this->sprite, NULL, &rect);
}

vec2f Entity::get_pos() const {
	return this->pos;
}

vec2f Entity::get_size() const {
	return this->size;
}

Config& Entity::get_config() const {
	return this->config;
}

void Entity::init_behaviors() {}
