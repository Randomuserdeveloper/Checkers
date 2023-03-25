#pragma once
#include "Entity.h"
#include "Math.h"
#include <SDL.h>

class Checker : public Entity {
public:
	Checker(Vector2f position, SDL_Texture* texture, unsigned short color); // The color of a checker is its team or side (black or red). Use 0 for black and 1 for red
private:
	unsigned short color;
};

