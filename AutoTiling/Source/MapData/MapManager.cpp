#include "MapManager.h"
#include <Source/Device/ImageLoader.h>
#include <Source/Device/Input.h>
#include <Source/MapData/CalcLandImageNo.h>
#include <Source/Type/GirthState.h>
#include <DxLib.h>

MapManager::MapManager() {
}

MapManager::~MapManager() {
}

void MapManager::DrawMap() {
	for (int i = 0; i < landMap[0].size(); i++) {
		for (int j = 0; j < landMap.size(); j++) {
			DrawMaptip(Vector2(j*MAPTIP_SIZE_X, i*MAPTIP_SIZE_Y), Vector2(j, i));
		}
	}
}

void MapManager::Initialize() {
	SetupLandMap();
	SetupMaptips();
}

void MapManager::Update() {
	WriteTerrain();
}

void MapManager::DrawMaptip(const Vector2 & position, const Vector2 & mapNo) {
	for (int i = 0; i < 4; i++) {
		DrawGraph(position.X + i%2*MAPTIP_SIZE_X/2, position.Y+i/2*MAPTIP_SIZE_Y/2, maptips[mapNo.X][mapNo.Y].GetImageHandle((ePlaceInMaptip)i),TRUE);
	}

}

void MapManager::SetupLandMap() {
	for (int i = 0; i < landMap.size(); i++) {
		for (int j = 0; j < landMap[0].size(); j++) {
			landMap[i][j] = false;
		}
	}
	landMap = landMap;
}

void MapManager::SetupMaptips() {
	for (int i = 0; i < maptips.size(); i++) {
		for (int j = 0; j < maptips[0].size(); j++) {
			GirthState gs = GetGirthState(i, j);
			maptips[i][j] = CalcLandImageNo::MakeImage(gs);
		}
	}
}

void MapManager::WriteTerrain() {
	Vector2 mouseCoord = Input::GetMousePosition() / Vector2(MAPTIP_SIZE_X, MAPTIP_SIZE_Y);
	if (!CalcLandImageNo::isInField(mouseCoord.X, mouseCoord.Y)) { return; }
	if (Input::isLeftClick()) {
		WriteLand(mouseCoord);
	}
	if (Input::isRightClick()) {
		WriteSea(mouseCoord);
	}
}

void MapManager::WriteLand(const Vector2& coord) {
	//指定された座標を陸にする
	landMap[coord.X][coord.Y] = true;
	SetupMaptips();
}

void MapManager::WriteSea(const Vector2& coord) {
	//指定された座標を海にする
	landMap[coord.X][coord.Y] = false;
	SetupMaptips();
}

GirthState MapManager::GetGirthState(int x, int y) {
	GirthState resoult;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int targetX = x + j-1;
			int targetY = y + i-1;
			resoult.girth[i * 3 + j] = (CalcLandImageNo::isInField(targetX, targetY)) ? landMap[targetX][targetY]: false;
		}
	}
	return resoult;
}
