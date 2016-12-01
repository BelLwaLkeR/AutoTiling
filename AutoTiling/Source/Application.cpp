#include <DxLib.h>
#include "Application.h"
#include <Source/Device/ImageLoader.h>

Application::Application() :isEnd(false) {
}

Application::~Application(){
}

void Application::Run(){
	Initialize();
	while (!isEnd && ProcessMessage() == 0) {
		Update();
		Draw();
		isEnd |= CheckHitKey(KEY_INPUT_ESCAPE);
	}
	Finalize();
}

void Application::Initialize(){
	ChangeWindowMode(TRUE);
	SetMainWindowText("AutoTilingTest");
	SetGraphMode(1280, 720, 32);
	DxLib_Init();
	mapManager.Initialize();

}

void Application::Update(){
	mapManager.Update();
}

void Application::Draw(){
	mapManager.DrawMap();
}

void Application::Finalize(){
	DxLib_End();
}
