/*
 * Graphics.h
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_GRAPHICS_H_
#define INCLUDE_GRAPHICS_H_

#include <utility>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
private:
	const std::pair<const int, const int> WIN_DIM = { 640, 480 };
	SDL_Window *_window;
	SDL_Renderer *_renderer;
public:
	Graphics();
	~Graphics();
};

#endif /* INCLUDE_GRAPHICS_H_ */
