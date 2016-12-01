#pragma once
#include <bitset>
#include <Source/Type/eGirth.h>

//周囲9マスの情報を格納する
class GirthState {
public:
	GirthState();
	GirthState(
		bool isLandLT, bool isLandT, bool isLandRT,
		bool isLandL , bool isLandC, bool isLandR ,
		bool isLandLB, bool isLandB, bool isLandRB
	);
	~GirthState();

	//現在地が陸かどうか
	bool IsLand()				const;

	//現在地が海かどうか
	bool IsSea()				const;

	//指定された方向に陸があるかどうか
	bool GetAdjacentState(eGirth girthState)	const;

	//周囲9マスの地形情報を格納
	std::bitset<9> girth;
	
	
private:

};



