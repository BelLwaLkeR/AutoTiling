#pragma once

class Vector2 {
public:
	Vector2() :X(0), Y(0) {}
	Vector2(int _X, int _Y) :X(_X), Y(_Y) {}
	~Vector2() {}
	int X;
	int Y;

	Vector2& operator/(const Vector2& other) {
		return Vector2(X/other.X, Y/other.Y);
	}

private:

};

