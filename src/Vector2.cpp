#include "Vector2.h"

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float n = 0) : x(n), y(n) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(Vector2 other) {
	return Vector2(x + other.x, y + other.y);
}
Vector2 Vector2::operator-(Vector2 other) {
	return Vector2(x - other.x, y - other.y);
}
Vector2 Vector2::operator*(float other) {
	return Vector2(x * other, y * other);
}
Vector2 Vector2::operator/(float other) {
	return Vector2(x / other, y / other);
}

void Vector2::operator+=(Vector2 other) {
	this->x += other.x;
	this->y += other.y;
}
void Vector2::operator-=(Vector2 other) {
	this->x -= other.x;
	this->y -= other.y;
}
void Vector2::operator*=(float other) {
	this->x *= other;
	this->y *= other;
}
void Vector2::operator/=(float other) {
	this->x /= other;
	this->y /= other;
}

float Vector2::Magnitude() {
	return sqrt(MagnitudeSqr());
}
float Vector2::MagnitudeSqr() {
	return x * x + y * y;
}
float Vector2::Dot(Vector2 other) {
	return x * other.x + y * other.y;
}