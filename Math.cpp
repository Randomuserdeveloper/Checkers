#include "Math.h"

using namespace std;

Vector2f::Vector2f(float x, float y) : x{ x }, y{ y } {
}

float Vector2f::getDistance(Vector2f& other) const {
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

float Vector2f::getX() const {
	return x;
}

float Vector2f::getY() const {
	return y;
}

ostream& operator<<(ostream& stream, Vector2f& vector) {
	stream << "(" << vector.getX() << ", " << vector.getY() << ")";
	return stream;
}