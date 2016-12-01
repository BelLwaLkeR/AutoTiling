#pragma once
#include <array>
#include <bitset>
#include <string>
#include <memory>



//シングルトン呼び出し用
#define SGLT_IMAGELOADER ImageLoader::GetInstance().lock()

//画像読み込み用シングルトン
class ImageLoader {
public:
	~ImageLoader();

	//シングルトンインスタンス取得関数。
	static std::weak_ptr<ImageLoader> GetInstance();

	//マップチップ画像のハンドルを取得
	int GetMaptipImageHandle(int no);


private:
	ImageLoader();
	ImageLoader(ImageLoader&);
	void Initialize();

	//マップチップの画像を読み込む
	void SetupMapTipHandle();

	//シングルトンのインスタンス
	static std::shared_ptr<ImageLoader> instance;

	//マップチップ画像のハンドル格納用
	std::array<int, 24> maptipImageHandle;
};

