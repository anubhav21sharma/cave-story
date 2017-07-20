/*
 * AnimatedSprite.cpp
 *
 *  Created on: 17-Jul-2017
 *      Author: anubhav
 */

#include "AnimatedSprite.h"
#include "Graphics.h"

AnimatedSprite::AnimatedSprite() {
}

AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate) :
		Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
				frameIndex(0),
				timeToUpdate(timeToUpdate),
				visible(true),
				currentAnimationOnce(false),
				currentAnimation("") {
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, IntPair offset) {
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}
	animations.insert( { name, rectangles });
	offsets.insert( { name, offset });
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
	currentAnimationOnce = once;
	if (currentAnimation != animation) {
		currentAnimation = animation;
		frameIndex = 0;
	}
}

void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();
	timeElapsed += elapsedTime;
	if (timeElapsed > timeToUpdate) {
		timeElapsed -= timeToUpdate;
		if (frameIndex < animations[currentAnimation].size() - 1) {
			frameIndex++;
		} else {
			if (currentAnimationOnce) {
				setVisible(false);
			}
			frameIndex = 0;
			animationDone(currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
	if (visible) {
		SDL_Rect destRectangle;
		destRectangle.x = x + offsets[currentAnimation].first;
		destRectangle.y = y + offsets[currentAnimation].second;
		destRectangle.w = sourceRect.w * globals::SPRITE_SCALE;
		destRectangle.h = sourceRect.h * globals::SPRITE_SCALE;

		SDL_Rect sourceRect = animations[currentAnimation][frameIndex];
		graphics.blitSurface(spriteSheet, &sourceRect, &destRectangle);
	}
}

void AnimatedSprite::resetAnimation() {
	animations.clear();
	offsets.clear();
}

void AnimatedSprite::stopAnimation() {
	frameIndex = 0;
	animationDone(currentAnimation);
}

void AnimatedSprite::setVisible(bool visible) {
	this->visible = visible;
}

//void AnimatedSprite::animationDone(std::string currentAnimation) {
//
//}
