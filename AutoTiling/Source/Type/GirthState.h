#pragma once
#include <bitset>
#include <Source/Type/eGirth.h>

//����9�}�X�̏����i�[����
class GirthState {
public:
	GirthState();
	GirthState(
		bool isLandLT, bool isLandT, bool isLandRT,
		bool isLandL , bool isLandC, bool isLandR ,
		bool isLandLB, bool isLandB, bool isLandRB
	);
	~GirthState();

	//���ݒn�������ǂ���
	bool IsLand()				const;

	//���ݒn���C���ǂ���
	bool IsSea()				const;

	//�w�肳�ꂽ�����ɗ������邩�ǂ���
	bool GetAdjacentState(eGirth girthState)	const;

	//����9�}�X�̒n�`�����i�[
	std::bitset<9> girth;
	
	
private:

};



