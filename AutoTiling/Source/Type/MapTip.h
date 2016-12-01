#pragma once
#include <array>
#include <Source/Type/ePlaceInMaptip.h>

//マップチップの画像を格納
class MapTip {
public:
	MapTip() {}
	MapTip(int lt, int rt, int lb, int rb):
		imageLT(lt),
		imageRT(rt),
		imageLB(lb),
		imageRB(rb)	{}
	~MapTip() {}

	//マップチップ内位置を指定して画像ハンドルを取得
	int GetImageHandle(ePlaceInMaptip adjacent);

	//左上部の画像ハンドル
	int imageLT;

	//右上部の画像ハンドル
	int imageRT;

	//左下部の画像ハンドル
	int imageLB;

	//右下部の画像ハンドル
	int imageRB;

private:
	
};