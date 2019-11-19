#pragma once
#include <stdlib.h>

extern "C" class Vector2 {
public:
	
	Vector2() {}
	Vector2(int _x, int _y) : x(_x), y(_y) {}
	void Reasign(int val);
	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }

	int x = 1;
	int y = 2;
};