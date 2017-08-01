/*
 * Level.h
 *
 *  Created on: 20-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_LEVEL_H_
#define INCLUDE_LEVEL_H_

#include <Globals.h>
#include <Tile.h>
#include <string>
#include <vector>

struct SDL_Texture;
struct Tileset;
class Graphics;

class Level {
public:
	Level();
	Level(std::string mapName, IntPair spawnPoint, Graphics &graphics);
	~Level();
	void update(int elapsedTime);
	void draw(Graphics &graphics);
	IntPair getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight);

private:
	std::string mapName;
	IntPair spawnPoint;

	IntPair size;
	IntPair tileSize;

	SDL_Texture *backgroundTexture;

	std::vector<Tile> tileList;
	std::vector<Tileset> tilesets;

	void loadMap(std::string mapName, Graphics &graphics);
};

struct Tileset {
	SDL_Texture *texture;
	int firstGid;

	Tileset() {
		firstGid = -1;
	}

	Tileset(SDL_Texture *texture, int firstGid) {
		this->texture = texture;
		this->firstGid = firstGid;
	}
};

#endif /* INCLUDE_LEVEL_H_ */
