#pragma once
#include <Source/Type/eLandImageType.h>
#include <Source/Type/ePlaceInMaptip.h>
#include <Source/Type/GirthState.h>
#include <bitset>
class MapTip;

//マップチップ番号計算用クラス
class CalcLandImageNo {
public:
	CalcLandImageNo();
	~CalcLandImageNo();

	//周囲の地形によって使う画像を変える
	static MapTip& MakeImage(const GirthState& adjacentState);

	//指定された座標が、ゲームフィールド内かどうか
	static bool isInField(int x, int y);
private:

	//地形とマップチップ内の位置により、画像番号を取得する。
	static int GetLandImageNo(eLandImageType type, ePlaceInMaptip pllace );

	//海マップチップを取得
	static MapTip& MakeSea();

	//陸マップチップを取得
	static MapTip& MakeLand();

	//周囲の地形の端が映り込んでいるマップチップを作成
	static MapTip& MakeMapImageEnd(const GirthState& adjacentState);

	//周囲の地形に関係せず、単一のマップチップを取得
	static MapTip& MakeSimpleTip(eLandImageType imageNoMost);

	//隣接地形を取得し、指定されたマップチップ内画像種類を取得
	static eLandImageType GetLandImageNoMost(const GirthState& adjacentState, eGirth vertical, eGirth horizontal);

	//隣接地形の状態により、指定されたマップチップ内画像種類を取得
	static eLandImageType GetLandImageNoMost(bool isLandVerticalAdjacent, bool isLandhorizontalAdjacent, bool isLanddiagonalAdjacent);
};

