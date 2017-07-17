/*
 * Game.h
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

class Graphics;

class Game {
public:
	Game();
	~Game();
	private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

};

#endif /* INCLUDE_GAME_H_ */
