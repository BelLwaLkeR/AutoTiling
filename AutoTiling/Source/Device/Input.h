#pragma once
class Vector2;

//���̓N���X
class Input {
public:
	Input();
	~Input();

	//�}�E�X�|�C���^�̈ʒu���擾
	static Vector2 GetMousePosition();

	//���N���b�N�����m
	static bool isLeftClick();

	//�E�N���b�N�����m
	static bool isRightClick();

private:

};
