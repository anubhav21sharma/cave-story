/*
 * Sprite.h
 *
 *  Created on: 17-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_SPRITE_H_
#define INCLUDE_SPRITE_H_

#include <SDL2/SDL.h>
#include <string>

class Graphics;

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
	private:
	SDL_Rect sourceRect;
	SDL_Texture *spriteSheet;
	float x, y;
};

#endif /* INCLUDE_SPRITE_H_ */
