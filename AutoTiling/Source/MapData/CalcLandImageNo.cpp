#include "CalcLandImageNo.h"
#include <Source/Device/ImageLoader.h>
#include <Source/Type/MapTip.h>
#include <Source/Type/eGirth.h>
#include <Source/MapData/MapManager.h>

CalcLandImageNo::CalcLandImageNo() {

}

CalcLandImageNo::~CalcLandImageNo() {

}

int CalcLandImageNo::GetLandImageNo(eLandImageType type, ePlaceInMaptip place) {
	int m = (int)type;
	int l = (int)place;

	//4分割されたマップチップの座標を計算
	//(※6地形以外は想定していない)
	int resoult = m * 2 + l + (l & 2)/2 * 10;
	if (type != eLandImageType::SEA) {
		int a = 0;
	}

	return resoult;
}

MapTip & CalcLandImageNo::MakeSimpleTip(eLandImageType type) {
	return MapTip(
		SGLT_IMAGELOADER->GetMaptipImageHandle(GetLandImageNo(type, ePlaceInMaptip::LEFT_TOP)),
		SGLT_IMAGELOADER->GetMaptipImageHandle(GetLandImageNo(type, ePlaceInMaptip::RIGHT_TOP)),
		SGLT_IMAGELOADER->GetMaptipImageHandle(GetLandImageNo(type, ePlaceInMaptip::LEFT_BOTTOM)),
		SGLT_IMAGELOADER->GetMaptipImageHandle(GetLandImageNo(type, ePlaceInMaptip::RIGHT_BOTTOM))
	);
}

MapTip& CalcLandImageNo::MakeImage(const GirthState& adjacentState) {
	if (adjacentState.IsLand()) {
		return MakeLand();
	}
	if (adjacentState.IsSea()) {
		return MakeSea();
	}
	return MakeMapImageEnd(adjacentState);
}

MapTip& CalcLandImageNo::MakeSea() {
	return MakeSimpleTip(eLandImageType::SEA);
}


MapTip& CalcLandImageNo::MakeLand() {
	return MakeSimpleTip(eLandImageType::LAND);
}

MapTip& CalcLandImageNo::MakeMapImageEnd(const GirthState& adjacentState) {
	std::array<eLandImageType, 4> most;
	most.fill(eLandImageType::SEA);

	//周囲の地形を確認
	most[0] = GetLandImageNoMost(adjacentState, eGirth::TOP		, eGirth::LEFT	);
	most[1] = GetLandImageNoMost(adjacentState, eGirth::TOP		, eGirth::RIGHT	);
	most[2] = GetLandImageNoMost(adjacentState, eGirth::BOTTOM	, eGirth::LEFT	);
	most[3] = GetLandImageNoMost(adjacentState, eGirth::BOTTOM	, eGirth::RIGHT	);

	//周囲の地形から現在地の地形を組み立て
	int no[4];
	for (int i = 0; i < 4; i++) {
		no[i] = CalcLandImageNo::GetLandImageNo(most[i], (ePlaceInMaptip)i);
	}

	return MapTip(
		SGLT_IMAGELOADER->GetMaptipImageHandle(no[0]),
		SGLT_IMAGELOADER->GetMaptipImageHandle(no[1]),
		SGLT_IMAGELOADER->GetMaptipImageHandle(no[2]),
		SGLT_IMAGELOADER->GetMaptipImageHandle(no[3])
	);
}

eLandImageType CalcLandImageNo::GetLandImageNoMost(const GirthState& adjacentState, eGirth vertical, eGirth horizontal) {
	//上下左右の位置から、斜めの位置を算出
	eGirth diagonal = eGirth((int)vertical + (int)horizontal - 4);

	return CalcLandImageNo::GetLandImageNoMost(
		adjacentState.GetAdjacentState(vertical),
		adjacentState.GetAdjacentState(horizontal),
		adjacentState.GetAdjacentState(diagonal)
	);
}

eLandImageType CalcLandImageNo::GetLandImageNoMost(bool isLandVerticalAdjacent, bool isLandhorizontalAdjacent, bool isLanddiagonalAdjacent) {
	eLandImageType resoult = eLandImageType::SEA;
	//垂直に陸があるなら垂直用地形
	if (isLandVerticalAdjacent) {
		resoult = eLandImageType::TOP_BOTTOM;
	}
	//水平に陸があるなら、包囲地形か水平地形化を算出
	if (isLandhorizontalAdjacent) {
		resoult = (resoult == eLandImageType::SEA) ? eLandImageType::LEFT_RIGHT : eLandImageType::CROSS;
	}
	//斜めに地形があり、かつ現在地が海ならば斜め地形を取得
	if (isLanddiagonalAdjacent) {
		resoult = (resoult == eLandImageType::SEA) ? eLandImageType::SALTIRE : resoult;
	}
	return resoult;
}

bool CalcLandImageNo::isInField(int x, int y) {
	return x >= 0 && x < FIELD_SIZE_X && y>=0 && y < FIELD_SIZE_Y;
}




