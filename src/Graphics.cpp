/*
 * Graphics.cpp
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#include "Graphics.h"
#include <SDL2/SDL.h>

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(WIN_DIM.first, WIN_DIM.second, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "CaveStory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}

