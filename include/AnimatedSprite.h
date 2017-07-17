/*
 * AnimatedSprite.h
 *
 *  Created on: 17-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_ANIMATEDSPRITE_H_
#define INCLUDE_ANIMATEDSPRITE_H_

#include <Globals.h>
#include <SDL2/SDL_rect.h>
#include <Sprite.h>
#include <map>
#include <string>
#include <vector>

class Graphics;

class AnimatedSprite: public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
	void playAnimation(std::string animation, bool once = false);
	void update(int elapsedTime);
	void draw(Graphics &graphics, int x, int y);
	virtual void setupAnimations();

protected:
	double timeToUpdate;
	bool currentAnimationOnce;
	std::string currentAnimation;

	void addAnimation(int frames, int x, int y, std::string name, int width, int height, IntPair offset);
	void resetAnimation();
	void stopAnimation();
	void setVisible(bool visible);
	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> animations;
	std::map<std::string, IntPair> offsets;

	int frameIndex;
	double timeElapsed;
	bool visible;

};

#endif /* INCLUDE_ANIMATEDSPRITE_H_ */
