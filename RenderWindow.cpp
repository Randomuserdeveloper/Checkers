#include "RenderWindow.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Entity.h"

using namespace std;

RenderWindow::RenderWindow(const char* title, int width, int height) : window{ NULL }, renderer{ NULL } {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Window failed to init. Error: " << SDL_GetError() << endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int RenderWindow::getRefreshRate() {
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
		cout << "Failed to load texture. Error: " << SDL_GetError() << endl;

	return texture;
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity) {
	SDL_Rect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	const int sizeMultiplier = 1;

	SDL_Rect dst;
	dst.x = entity.getPosition().getX() * sizeMultiplier;
	dst.y = entity.getPosition().getY() * sizeMultiplier;
	dst.w = entity.getCurrentFrame().w * sizeMultiplier;
	dst.h = entity.getCurrentFrame().h * sizeMultiplier;

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

RenderWindow::~RenderWindow() {
	SDL_DestroyWindow(window);
}