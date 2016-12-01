#include <DxLib.h>
#include <Source/Type/Vector2.h>
#include "Input.h"

Input::Input() {
}

Input::~Input() {
}

Vector2 Input::GetMousePosition() {
	int X, Y;
	GetMousePoint(&X, &Y);
	return Vector2(X, Y);
}

bool Input::isLeftClick() {
	return GetMouseInput() & MOUSE_INPUT_LEFT;
}

bool Input::isRightClick() {
	return GetMouseInput() & MOUSE_INPUT_RIGHT;
}
