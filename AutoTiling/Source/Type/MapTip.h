#pragma once
#include <array>
#include <Source/Type/ePlaceInMaptip.h>

//�}�b�v�`�b�v�̉摜���i�[
class MapTip {
public:
	MapTip() {}
	MapTip(int lt, int rt, int lb, int rb):
		imageLT(lt),
		imageRT(rt),
		imageLB(lb),
		imageRB(rb)	{}
	~MapTip() {}

	//�}�b�v�`�b�v���ʒu���w�肵�ĉ摜�n���h�����擾
	int GetImageHandle(ePlaceInMaptip adjacent);

	//���㕔�̉摜�n���h��
	int imageLT;

	//�E�㕔�̉摜�n���h��
	int imageRT;

	//�������̉摜�n���h��
	int imageLB;

	//�E�����̉摜�n���h��
	int imageRB;

private:
	
};