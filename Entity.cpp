#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Vector2f position, SDL_Texture* texture) : position{ position }, texture{ texture } {
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 64;
	currentFrame.h = 64;
}

Vector2f& Entity::getPosition() {
	return position;
}

void Entity::setPosition(Vector2f position) {
	this->position = position;
}

SDL_Texture* Entity::getTexture() const {
	return texture;
}

SDL_Rect Entity::getCurrentFrame() const {
	return currentFrame;
}