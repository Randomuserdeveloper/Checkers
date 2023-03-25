#include "Checker.h"

Checker::Checker(Vector2f position, SDL_Texture* texture, unsigned short color) : Entity(position, texture) {
	this->color = color;
}
