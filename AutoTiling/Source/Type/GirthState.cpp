#include "GirthState.h"


GirthState::GirthState() {
	GirthState(	0, 0, 0,
				0, 0, 0,
				0, 0, 0 );
}

GirthState::GirthState(bool isLandLT, bool isLandT, bool isLandRT, bool isLandL, bool isLandC, bool isLandR, bool isLandLB, bool isLandB, bool isLandRB) {
	girth.reset();
	if (isLandLT) { girth.set(0); }
	if (isLandT ) { girth.set(1); }
	if (isLandRT) { girth.set(2); }

	if (isLandL ) { girth.set(3); }
	if (isLandC ) { girth.set(4); }
	if (isLandR ) { girth.set(5); }

	if (isLandLB) { girth.set(6); }
	if (isLandB ) { girth.set(7); }
	if (isLandLB) { girth.set(8); }
}

GirthState::~GirthState() {
}

//���ݒn�����Ȃ�Η�
bool GirthState::IsLand() const {
	return girth.test(4);
}

//���͂ɗ����Ȃ���ΊC
bool GirthState::IsSea() const {
	return girth.none();
}

//�w�肳�ꂽ���W�ɗ������邩�ǂ���
bool GirthState::GetAdjacentState(eGirth girthState) const {
	return girth.test((int)girthState);
}
