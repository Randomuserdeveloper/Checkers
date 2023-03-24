#pragma once
#include <iostream>

using namespace std;

class Vector2f {
public:
	Vector2f() = default;
	Vector2f(float x, float y);

	float getX();
	float getY();
private:
	float x;
	float y;
};

ostream& operator<<(ostream& stream, const Vector2f& vector);