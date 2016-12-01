#include "MapTip.h"

int MapTip::GetImageHandle(ePlaceInMaptip adjacent) {
	switch (adjacent) {
	case ePlaceInMaptip::LEFT_TOP:
		return imageLT;
	case ePlaceInMaptip::RIGHT_TOP:
		return imageRT;
	case ePlaceInMaptip::LEFT_BOTTOM:
		return imageLB;
	case ePlaceInMaptip::RIGHT_BOTTOM:
		return imageRB;
	default:
		return -1;
	}
}
