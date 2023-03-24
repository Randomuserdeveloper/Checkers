#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"

class Entity {
public:
	Entity(Vector2f position, SDL_Texture* texture);


	Vector2f& getPosition();
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
private:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};