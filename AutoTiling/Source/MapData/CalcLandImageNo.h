#pragma once
#include <Source/Type/eLandImageType.h>
#include <Source/Type/ePlaceInMaptip.h>
#include <Source/Type/GirthState.h>
#include <bitset>
class MapTip;

//�}�b�v�`�b�v�ԍ��v�Z�p�N���X
class CalcLandImageNo {
public:
	CalcLandImageNo();
	~CalcLandImageNo();

	//���͂̒n�`�ɂ���Ďg���摜��ς���
	static MapTip& MakeImage(const GirthState& adjacentState);

	//�w�肳�ꂽ���W���A�Q�[���t�B�[���h�����ǂ���
	static bool isInField(int x, int y);
private:

	//�n�`�ƃ}�b�v�`�b�v���̈ʒu�ɂ��A�摜�ԍ����擾����B
	static int GetLandImageNo(eLandImageType type, ePlaceInMaptip pllace );

	//�C�}�b�v�`�b�v���擾
	static MapTip& MakeSea();

	//���}�b�v�`�b�v���擾
	static MapTip& MakeLand();

	//���͂̒n�`�̒[���f�荞��ł���}�b�v�`�b�v���쐬
	static MapTip& MakeMapImageEnd(const GirthState& adjacentState);

	//���͂̒n�`�Ɋ֌W�����A�P��̃}�b�v�`�b�v���擾
	static MapTip& MakeSimpleTip(eLandImageType imageNoMost);

	//�אڒn�`���擾���A�w�肳�ꂽ�}�b�v�`�b�v���摜��ނ��擾
	static eLandImageType GetLandImageNoMost(const GirthState& adjacentState, eGirth vertical, eGirth horizontal);

	//�אڒn�`�̏�Ԃɂ��A�w�肳�ꂽ�}�b�v�`�b�v���摜��ނ��擾
	static eLandImageType GetLandImageNoMost(bool isLandVerticalAdjacent, bool isLandhorizontalAdjacent, bool isLanddiagonalAdjacent);
};

