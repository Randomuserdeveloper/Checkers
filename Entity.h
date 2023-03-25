#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.h"

class Entity {
public:
	Entity(Vector2f position, SDL_Texture* texture);


	Vector2f& getPosition();
	void setPosition(Vector2f position);
	SDL_Texture* getTexture() const;
	SDL_Rect getCurrentFrame() const;
private:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};