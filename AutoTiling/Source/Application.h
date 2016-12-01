#pragma once
#include <Source/MapData/MapManager.h>

//�Q�[�����[�v
class Application{
public:
	Application();
	~Application();
	void Run();

private:
	void Initialize();
	void Update();
	void Draw();
	void Finalize();

	bool isEnd;
	MapManager mapManager;


};
