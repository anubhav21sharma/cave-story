/*
 * Player.cpp
 *
 *  Created on: 19-Jul-2017
 *      Author: anubhav
 */

#include <Graphics.h>
#include <Player.h>

namespace playerConstants {
const float WALK_SPEED = 0.2f;
}

Player::Player() {
}

Player::Player(Graphics& graphics, float x, float y) :
		AnimatedSprite(graphics, "content/sprites/MyChar-t.png", 0, 0, 16, 16, x, y, 100) {
//	graphics.loadImage("content/sprites/MyChar.png");
	setupAnimations();
	playAnimation("RunRight");
}

void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, x, y);
}

void Player::update(float elapsedTime) {
	x += dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::animationDone(std::string currentAnimation) {

}

void Player::moveLeft() {
	dx = -playerConstants::WALK_SPEED;
	playAnimation("RunLeft");
	facing = LEFT;
}

void Player::moveRight() {
	dx = playerConstants::WALK_SPEED;
	playAnimation("RunRight");
	facing = RIGHT;
}

void Player::stopMoving() {
	dx = 0.0f;
	playAnimation(facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::setupAnimations() {
	addAnimation(3, 0, 0, "RunLeft", 16, 16, { 0, 0 });
	addAnimation(3, 0, 16, "RunRight", 16, 16, { 0, 0 });
	addAnimation(1, 0, 0, "IdleLeft", 16, 16, { 0, 0 });
	addAnimation(1, 0, 16, "IdleRight", 16, 16, { 0, 0 });
}

