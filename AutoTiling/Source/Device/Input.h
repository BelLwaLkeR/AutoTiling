#pragma once
class Vector2;

//入力クラス
class Input {
public:
	Input();
	~Input();

	//マウスポインタの位置を取得
	static Vector2 GetMousePosition();

	//左クリックを検知
	static bool isLeftClick();

	//右クリックを検知
	static bool isRightClick();

private:

};
