/*
 * Graphics.cpp
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#include "Graphics.h"
#include "Globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_rect.h>

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "CaveStory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
	if (spriteSheets.find(filePath) == spriteSheets.end()) {
		spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destRectangle) {
	SDL_RenderCopy(renderer, texture, sourceRectangle, destRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(renderer);
}

void Graphics::clear() {
	SDL_RenderClear(renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return renderer;
}
