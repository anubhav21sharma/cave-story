/*
 * Input.cpp
 *
 *  Created on: 16-Jul-2017
 *      Author: anubhav
 */

#include "Input.h"

void Input::beginNewFrame() {
	pressedKeys.clear();
	releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event &event) {
	pressedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event) {
	releasedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
	return pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
	return heldKeys[key];
}
