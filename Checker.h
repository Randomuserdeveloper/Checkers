#pragma once
#include "Entity.h"
#include "Math.h"
#include <SDL.h>

class Checker : public Entity {
public:
	Checker(Vector2f position, SDL_Texture* texture);

};

