/*
 * Level.cpp
 *
 *  Created on: 20-Jul-2017
 *      Author: anubhav
 */

#include <Graphics.h>
#include <Level.h>
#include <SDL2/SDL_render.h>
#include <tinyxml2.h>
#include <sstream>
#include <utility>

using namespace tinyxml2;

Level::Level() {
}

Level::Level(std::string mapName, IntPair spawnPoint, Graphics& graphics) :
		mapName(mapName), spawnPoint(spawnPoint), size( { 0, 0 }) {
	loadMap(mapName, graphics);
}

void Level::update(int elapsedTime) {
}

void Level::draw(Graphics& graphics) {
	for (Tile tile : tileList) {
		tile.draw(graphics);
	}
}

void Level::loadMap(std::string mapName, Graphics& graphics) {
	//Parse the .tmx file
	XMLDocument doc;
	std::stringstream ss;
	ss << "content/maps/" << mapName << ".tmx"; //Pass in Map 1, we get maps/Map 1.tmx
	doc.LoadFile(ss.str().c_str());

	XMLElement* mapNode = doc.FirstChildElement("map");

	//Get the width and the height of the whole map and store it in _size
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);
	size = {width, height};

	//Get the width and the height of the tiles and store it in _tileSize
	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	tileSize = {tileWidth, tileHeight};

	//Loading the tilesets
	XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (pTileset != NULL) {
		while (pTileset) {
			int firstgid;
			const char* source = pTileset->FirstChildElement("image")->Attribute("source");
			char* path;
			std::stringstream ss;
			ss << source;
			pTileset->QueryIntAttribute("firstgid", &firstgid);
			SDL_Texture* tex = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(ss.str()));
			tilesets.push_back(Tileset(tex, firstgid));

			pTileset = pTileset->NextSiblingElement("tileset");
		}
	}

	//Loading the layers
	XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if (pLayer != NULL) {
		while (pLayer) {
			//Loading the data element
			XMLElement* pData = pLayer->FirstChildElement("data");
			if (pData != NULL) {
				while (pData) {
					//Loading the tile element
					XMLElement* pTile = pData->FirstChildElement("tile");
					if (pTile != NULL) {
						int tileCounter = 0;
						while (pTile) {
							//Build each individual tile here
							//If gid is 0, no tile should be drawn. Continue loop
							if (pTile->IntAttribute("gid") == 0) {
								tileCounter++;
								if (pTile->NextSiblingElement("tile")) {
									pTile = pTile->NextSiblingElement("tile");
									continue;
								}
								else {
									break;
								}
							}

							//Get the tileset for this specific gid
							int gid = pTile->IntAttribute("gid");
							Tileset tls;
							int closest = 0;
							for (int i = 0; i < this->tilesets.size(); i++) {
								if (tilesets[i].firstGid <= gid) {
									if (tilesets[i].firstGid > closest) {
										closest = tilesets[i].firstGid;
										tls = tilesets.at(i);
									}
								}
							}

							if (tls.firstGid == -1) {
								//No tileset was found for this gid
								tileCounter++;
								if (pTile->NextSiblingElement("tile")) {
									pTile = pTile->NextSiblingElement("tile");
									continue;
								}
								else {
									break;
								}
							}

							//Get the position of the tile in the level
							int xx = 0;
							int yy = 0;
							xx = tileCounter % width;
							xx *= tileWidth;
							yy += tileHeight * (tileCounter / width);
							IntPair finalTilePosition = { xx, yy };

							//Calculate the position of the tile in the tileset
							IntPair finalTilesetPosition = this->getTilesetPosition(tls, gid, tileWidth, tileHeight);

							Tile tile(tls.texture, { tileWidth, tileHeight }, finalTilesetPosition, finalTilePosition);
							tileList.push_back(tile);
							tileCounter++;
							pTile = pTile->NextSiblingElement("tile");
						}
					}

					pData = pData->NextSiblingElement("data");
				}
			}

			pLayer = pLayer->NextSiblingElement("layer");
		}
	}
}

IntPair Level::getTilesetPosition(Tileset tls, int gid, int tileWidth, int tileHeight) {
	int tilesetWidth, tilesetHeight;
	SDL_QueryTexture(tls.texture, NULL, NULL, &tilesetWidth, &tilesetHeight);
	int tsxx = gid % (tilesetWidth / tileWidth) - 1;
	tsxx *= tileWidth;
	int tsyy = 0;
	int amt = ((gid - tls.firstGid) / (tilesetWidth / tileWidth));
	tsyy = tileHeight * amt;
	IntPair finalTilesetPosition = {tsxx, tsyy};
	return finalTilesetPosition;
}

Level::~Level() {
}
