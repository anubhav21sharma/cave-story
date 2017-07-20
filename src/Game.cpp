/*
 * Game.cpp
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#include <Game.h>
#include <Graphics.h>
#include <Input.h>
#include <Player.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_timer.h>
#include <algorithm>

namespace {
const int FPS = 50;
const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

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

	player = Player(graphics, 120, 100);
	level = Level("Map1", { 100, 100 }, graphics);

	int LAST_UPDATE_TIME = SDL_GetTicks();

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
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT))
			player.moveLeft();
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT))
			player.moveRight();

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT))
			player.stopMoving();

		const int CUR_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CUR_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CUR_TIME_MS;

		draw(graphics);
	}

}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	level.draw(graphics);
	player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime) {
	player.update(elapsedTime);
	level.update(elapsedTime);
}
