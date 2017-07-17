/*
 * Sprite.cpp
 *
 *  Created on: 17-Jul-2017
 *      Author: anubhav
 */

#include "Sprite.h"
#include "Graphics.h"
#include <iostream>

Sprite::Sprite() {

}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
		x(posX), y(posY) {
	sourceRect.x = sourceX;
	sourceRect.y = sourceY;
	sourceRect.w = width;
	sourceRect.h = height;

	spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (spriteSheet == NULL) {
		std::cerr << "Could not load sprite image." << std::endl;
	}

}

Sprite::~Sprite() {
}

void Sprite::update() {
}

void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect destRectangle = { x, y, sourceRect.w, sourceRect.h };
	graphics.blitSurface(spriteSheet, &sourceRect, &destRectangle);

}
