/*
 * Globals.h
 *
 *  Created on: 17-Jul-2017
 *      Author: anubhav
 */

#ifndef INCLUDE_GLOBALS_H_
#define INCLUDE_GLOBALS_H_

#include <utility>

namespace globals {
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const float SPRITE_SCALE = 8.0f;
}

enum Direction {
	LEFT, RIGHT, UP, DOWN
};

typedef std::pair<int, int> IntPair;

#endif /* INCLUDE_GLOBALS_H_ */
