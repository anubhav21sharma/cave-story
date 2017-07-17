/*
 * Game.cpp
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#include "Game.h"
#include "SDL2/SDL.h"
#include "Graphics.h"
#include "Input.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			} else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			} else if (event.type == SDL_QUIT) {
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE))
			return;

	}

}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {

}
