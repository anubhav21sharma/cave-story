/*
 * Level.cpp
 *
 *  Created on: 20-Jul-2017
 *      Author: anubhav
 */

#include <Graphics.h>
#include <Level.h>
#include <SDL2/SDL_render.h>

Level::Level() {
}

Level::Level(std::string mapName, IntPair spawnPoint, Graphics& graphics) :
		mapName(mapName), spawnPoint(spawnPoint), size( { 0, 0 }) {
	loadMap(mapName, graphics);
}

void Level::update(int elapsedTime) {
}

void Level::draw(Graphics& graphics) {
	SDL_Rect sourceRect = { 0, 0, 64, 64 };
	SDL_Rect destRect = { 0, 0, 64, 64 };
	for (int x = 0; x < size.first / 64; x++) {
		for (int y = 0; y < size.second / 64; y++) {
			destRect.x = x * 64;
			destRect.y = y * 64;
			graphics.blitSurface(backgroundTexture, &sourceRect, &destRect);
		}
	}
}

void Level::loadMap(std::string mapName, Graphics& graphics) {
	backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/backgrounds/bkBlue.png"));
	size = {1280,960};
}

Level::~Level() {
}
