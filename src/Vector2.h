#pragma once

#include <math.h>

class Vector2 {
public:
	float x, y;

	Vector2();
	Vector2(float n);
	Vector2(float x, float y);

	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(float other);
	Vector2 operator/(float other);

	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(float other);
	void operator/=(float other);

	float Magnitude();
	float MagnitudeSqr();
	float Dot(Vector2 other);
};