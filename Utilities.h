#pragma once
#include <SDL.h>

namespace Utilities {
	inline float timeInSeconds() {
		float t = SDL_GetTicks();
		t *= 0.001f;
		return t;
	}
};
