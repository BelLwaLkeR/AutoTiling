#pragma once
#include <array>
#include <Source/Type/MapTip.h>
#include <Source/Type/Vector2.h>
class GirthState;

//縦横のフィールドサイズ設定
static const int FIELD_SIZE_X = 35;
static const int FIELD_SIZE_Y = 20;

//縦横のマップチップサイズを設定
static const int MAPTIP_SIZE_X = 32;
static const int MAPTIP_SIZE_Y = 32;


//地形を管理するクラス
class MapManager {
public:
	MapManager();
	~MapManager();
	void Initialize();
	void Update();
	void DrawMap();


private:
	//座標と地形情報を取得して地形を描画する
	void DrawMaptip(const Vector2& position, const Vector2& mapNo);

	//地形情報初期化
	void SetupLandMap();

	//地形画像初期化
	void SetupMaptips();

	//地形描画処理
	void WriteTerrain();

	//地形情報に陸地を書き込む
	void WriteLand(const Vector2& coord);

	//地形情報に海を書き込む
	void WriteSea(const Vector2& coord);

	//指定された座標の周囲の地形を取得
	GirthState GetGirthState(int x, int y);

	//陸かどうかの地形情報
	std::array<std::array<bool, FIELD_SIZE_Y>, FIELD_SIZE_X> landMap;

	//landMapから算出したマップチップ画像情報(控えておくことで毎フレーム再計算せずに済ませる。)
	std::array<std::array<MapTip, FIELD_SIZE_Y>, FIELD_SIZE_X> maptips;
};


