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

	//4�������ꂽ�}�b�v�`�b�v�̍��W���v�Z
	//(��6�n�`�ȊO�͑z�肵�Ă��Ȃ�)
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

	//���͂̒n�`���m�F
	most[0] = GetLandImageNoMost(adjacentState, eGirth::TOP		, eGirth::LEFT	);
	most[1] = GetLandImageNoMost(adjacentState, eGirth::TOP		, eGirth::RIGHT	);
	most[2] = GetLandImageNoMost(adjacentState, eGirth::BOTTOM	, eGirth::LEFT	);
	most[3] = GetLandImageNoMost(adjacentState, eGirth::BOTTOM	, eGirth::RIGHT	);

	//���͂̒n�`���猻�ݒn�̒n�`��g�ݗ���
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
	//�㉺���E�̈ʒu����A�΂߂̈ʒu���Z�o
	eGirth diagonal = eGirth((int)vertical + (int)horizontal - 4);

	return CalcLandImageNo::GetLandImageNoMost(
		adjacentState.GetAdjacentState(vertical),
		adjacentState.GetAdjacentState(horizontal),
		adjacentState.GetAdjacentState(diagonal)
	);
}

eLandImageType CalcLandImageNo::GetLandImageNoMost(bool isLandVerticalAdjacent, bool isLandhorizontalAdjacent, bool isLanddiagonalAdjacent) {
	eLandImageType resoult = eLandImageType::SEA;
	//�����ɗ�������Ȃ琂���p�n�`
	if (isLandVerticalAdjacent) {
		resoult = eLandImageType::TOP_BOTTOM;
	}
	//�����ɗ�������Ȃ�A��͒n�`�������n�`�����Z�o
	if (isLandhorizontalAdjacent) {
		resoult = (resoult == eLandImageType::SEA) ? eLandImageType::LEFT_RIGHT : eLandImageType::CROSS;
	}
	//�΂߂ɒn�`������A�����ݒn���C�Ȃ�Ύ΂ߒn�`���擾
	if (isLanddiagonalAdjacent) {
		resoult = (resoult == eLandImageType::SEA) ? eLandImageType::SALTIRE : resoult;
	}
	return resoult;
}

bool CalcLandImageNo::isInField(int x, int y) {
	return x >= 0 && x < FIELD_SIZE_X && y>=0 && y < FIELD_SIZE_Y;
}




