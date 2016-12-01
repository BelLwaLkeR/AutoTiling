#pragma once

//地形の種類
enum class eLandImageType {
	LAND,		//陸地
	CROSS,		//上下左右に陸地
	SALTIRE,	//斜め方向に陸地
	TOP_BOTTOM,	//上下のみに陸地
	LEFT_RIGHT,	//左右のみに陸地
	SEA			//海
};

