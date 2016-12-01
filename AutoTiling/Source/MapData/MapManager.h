#pragma once
#include <array>
#include <Source/Type/MapTip.h>
#include <Source/Type/Vector2.h>
class GirthState;

//�c���̃t�B�[���h�T�C�Y�ݒ�
static const int FIELD_SIZE_X = 35;
static const int FIELD_SIZE_Y = 20;

//�c���̃}�b�v�`�b�v�T�C�Y��ݒ�
static const int MAPTIP_SIZE_X = 32;
static const int MAPTIP_SIZE_Y = 32;


//�n�`���Ǘ�����N���X
class MapManager {
public:
	MapManager();
	~MapManager();
	void Initialize();
	void Update();
	void DrawMap();


private:
	//���W�ƒn�`�����擾���Ēn�`��`�悷��
	void DrawMaptip(const Vector2& position, const Vector2& mapNo);

	//�n�`��񏉊���
	void SetupLandMap();

	//�n�`�摜������
	void SetupMaptips();

	//�n�`�`�揈��
	void WriteTerrain();

	//�n�`���ɗ��n����������
	void WriteLand(const Vector2& coord);

	//�n�`���ɊC����������
	void WriteSea(const Vector2& coord);

	//�w�肳�ꂽ���W�̎��͂̒n�`���擾
	GirthState GetGirthState(int x, int y);

	//�����ǂ����̒n�`���
	std::array<std::array<bool, FIELD_SIZE_Y>, FIELD_SIZE_X> landMap;

	//landMap����Z�o�����}�b�v�`�b�v�摜���(�T���Ă������ƂŖ��t���[���Čv�Z�����ɍς܂���B)
	std::array<std::array<MapTip, FIELD_SIZE_Y>, FIELD_SIZE_X> maptips;
};


