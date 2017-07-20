/*
 * Game.h
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include <Level.h>
#include <Player.h>

class Graphics;

class Game {
public:
	Game();
	~Game();

private:

	Player player;
	Level level;

	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

};

#endif /* INCLUDE_GAME_H_ */
