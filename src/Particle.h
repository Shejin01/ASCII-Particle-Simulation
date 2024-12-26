#pragma once

#include "Vector2.h"
#include <string>

class Particle {
private:
	float Clamp(float value, float min, float max);
public:
	Vector2 position;
	Vector2 velocity;
	static Vector2 gravity;
	static float radius;
	static float mass;
	static float wall_friction;

	Particle(Vector2 position, Vector2 velocity = Vector2(0, 0));
	void Update(float dt);
	bool ResolveBoundaryCollision(int left, int top, int width, int height);
	bool ResolveCollision(Particle* other);
};