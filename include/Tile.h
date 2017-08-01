/*
 * Tile.h
 *
 *  Created on: 31-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_TILE_H_
#define INCLUDE_TILE_H_

#include <Globals.h>

class Graphics;

struct SDL_Texture;

class Tile {
public:
	Tile();
	Tile(SDL_Texture *tileSet, IntPair size, IntPair tileSetPosition, IntPair position);
	void update(int elapsedTime);
	void draw(Graphics &graphics);
	private:
	SDL_Texture *tileSet;
	IntPair size;
	IntPair tileSetPosition;
	IntPair position;
};

#endif /* INCLUDE_TILE_H_ */
