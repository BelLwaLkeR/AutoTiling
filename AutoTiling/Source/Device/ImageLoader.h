#pragma once
#include <array>
#include <bitset>
#include <string>
#include <memory>



//�V���O���g���Ăяo���p
#define SGLT_IMAGELOADER ImageLoader::GetInstance().lock()

//�摜�ǂݍ��ݗp�V���O���g��
class ImageLoader {
public:
	~ImageLoader();

	//�V���O���g���C���X�^���X�擾�֐��B
	static std::weak_ptr<ImageLoader> GetInstance();

	//�}�b�v�`�b�v�摜�̃n���h�����擾
	int GetMaptipImageHandle(int no);


private:
	ImageLoader();
	ImageLoader(ImageLoader&);
	void Initialize();

	//�}�b�v�`�b�v�̉摜��ǂݍ���
	void SetupMapTipHandle();

	//�V���O���g���̃C���X�^���X
	static std::shared_ptr<ImageLoader> instance;

	//�}�b�v�`�b�v�摜�̃n���h���i�[�p
	std::array<int, 24> maptipImageHandle;
};

