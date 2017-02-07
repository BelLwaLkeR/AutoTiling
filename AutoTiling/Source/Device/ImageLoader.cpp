#include "ImageLoader.h"
#include <Source/MapData/CalcLandImageNo.h>
#include <DxLib.h>

std::shared_ptr<ImageLoader> ImageLoader::instance = NULL;

ImageLoader::ImageLoader() {
	Initialize();
}

ImageLoader::~ImageLoader() {
}

void ImageLoader::Initialize() {
	SetupMapTipHandle();
}

std::weak_ptr<ImageLoader> ImageLoader::GetInstance() {
	if (instance == NULL) {
		//private�R���X�g���N�^�̃N���X��make_shared�ł��Ȃ��̂ŁA�ʍ\���̂��o�R������B
		struct SingletonCreator: ImageLoader{
			SingletonCreator() :ImageLoader() {}
			~SingletonCreator() {}
		};
		auto p = std::make_shared<SingletonCreator>();
		instance = std::move(p);
	}
	return instance;
}


int ImageLoader::GetMaptipImageHandle(int no) {
	return maptipImageHandle[no];
}

void ImageLoader::SetupMapTipHandle() {
	LoadDivGraph("./Resource/AutoTileSample_no.png", 24, 12, 2, 16, 16, &maptipImageHandle[0]);
}

