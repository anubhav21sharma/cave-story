/*
 * Tile.cpp
 *
 *  Created on: 31-Jul-2017
 *      Author: anubhav
 */

#include <Graphics.h>
#include <SDL2/SDL_rect.h>
#include <Tile.h>
#include <utility>

Tile::Tile() {
}

Tile::Tile(SDL_Texture* tileSet, IntPair size, IntPair tileSetPosition, IntPair position) :
		tileSet(tileSet),
				size(size),
				tileSetPosition(tileSetPosition),
				position(IntPair(position.first * globals::SPRITE_SCALE, position.second * globals::SPRITE_SCALE)) {
}

void Tile::update(int elapsedTime) {

}

void Tile::draw(Graphics& graphics) {
	SDL_Rect destRect = { position.first, position.second, size.first * globals::SPRITE_SCALE, size.second * globals::SPRITE_SCALE };
	SDL_Rect sourceRect = { tileSetPosition.first, tileSetPosition.second, size.first, size.second };

	graphics.blitSurface(tileSet, &sourceRect, &destRect);
}

