/*
 * Graphics.h
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_GRAPHICS_H_
#define INCLUDE_GRAPHICS_H_

#include <utility>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
	Graphics();
	~Graphics();

	SDL_Surface *loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destRectangle);
	void flip();
	void clear();

	SDL_Renderer* getRenderer() const;

private:
	const std::pair<const int, const int> WIN_DIM = { 640, 480 };
	SDL_Window *window;
	SDL_Renderer *renderer;

	std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif /* INCLUDE_GRAPHICS_H_ */
