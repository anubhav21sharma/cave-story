/*
 * Level.h
 *
 *  Created on: 20-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_LEVEL_H_
#define INCLUDE_LEVEL_H_

#include <Globals.h>
#include <string>

struct SDL_Texture;

class Graphics;

class Level {
public:
	Level();
	Level(std::string mapName, IntPair spawnPoint, Graphics &graphics);
	~Level();
	void update(int elapsedTime);
	void draw(Graphics &graphics);

private:
	std::string mapName;
	IntPair spawnPoint;
	IntPair size;
	SDL_Texture *backgroundTexture;

	void loadMap(std::string mapName, Graphics &graphics);
};

#endif /* INCLUDE_LEVEL_H_ */
