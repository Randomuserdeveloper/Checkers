#pragma once
#include <iostream>

using namespace std;

class Vector2f {
public:
	Vector2f() = default;
	Vector2f(float x, float y);

	float getDistance(Vector2f& other) const;
	float getX() const;
	float getY() const;
private:
	float x;
	float y;
};

ostream& operator<<(ostream& stream, const Vector2f& vector);