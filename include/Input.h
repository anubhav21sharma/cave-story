/*
 * Input.h
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_INPUT_H_
#define INCLUDE_INPUT_H_

#include <map>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>

class Input {
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event &event);
	void keyDownEvent(const SDL_Event &event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> pressedKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
};

#endif /* INCLUDE_INPUT_H_ */
