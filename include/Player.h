/*
 * Player.h
 *
 *  Created on: 19-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <AnimatedSprite.h>
#include <Globals.h>
#include <string>

class Graphics;

class Player: public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	void moveLeft();
	void moveRight();
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

private:
	float dx, dy;
	Direction facing;

};

#endif /* INCLUDE_PLAYER_H_ */
