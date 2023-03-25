#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.h"
#include "Entity.h"
#include "Utilities.h"
#include <vector>
#include "Checker.h"

using namespace std;

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << SDL_GetError();

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << SDL_GetError();

	RenderWindow window{ "Checkers", 512, 512 };

	SDL_Texture* redCheckerTexture = window.loadTexture("checkerPieceRed.png");
	SDL_Texture* blackCheckerTexture = window.loadTexture("checkerPieceBlack.png");
	SDL_Texture* redKingCheckerTexture = window.loadTexture("kingCheckerPieceRed.png");
	SDL_Texture* blackKingCheckerTexture = window.loadTexture("kingCheckerPieceBlack.png");
	SDL_Texture* blackCheckerBoardTexture = window.loadTexture("blackCheckerSquare.png");
	SDL_Texture* whiteCheckerBoardTexture = window.loadTexture("whiteCheckerSquare.png");

	vector<Entity> entities;

	const short layers = 8;

	for (float i = 0; i < layers; i++) {
		for (float j = 0; j < layers; j++) {
			if ((static_cast<int>(i) + static_cast<int>(j)) % 2 == 0) {
				Entity whiteCheckerBoard{ Vector2f{j * 64, i * 64}, whiteCheckerBoardTexture };
				entities.push_back(whiteCheckerBoard);
			}
			else {
				Entity blackCheckerBoard{ Vector2f{j * 64, i * 64}, blackCheckerBoardTexture };
				entities.push_back(blackCheckerBoard);

				if ((i != 4 && i != 5) && i < 3) {
					Checker blackCheckerPiece{ Vector2f{j * 64, i * 64}, blackCheckerTexture };
					entities.push_back(blackCheckerPiece);
				}
				else if ((i != 3 && i != 4) && i > 4) {
					Checker redCheckerPiece{ Vector2f{j * 64, i * 64}, redCheckerTexture };
					entities.push_back(redCheckerPiece);
				}
			}
		}
	}

	bool gameRunning = true;

	SDL_Event event;

	const float deltaTime = 0.01f;
	float accumulator = 0.0f;
	float currentTime = Utilities::timeInSeconds();

	while (gameRunning) {
		int startTicks = SDL_GetTicks();

		float newTime = Utilities::timeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= deltaTime) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					gameRunning = false;
			}

			accumulator -= deltaTime;
		}

		const float alpha = accumulator / deltaTime;

		window.clear();

		for (auto& entity : entities)
			window.render(entity);


		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;

		if (frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);

	}

	SDL_Quit();
	return 0;
}