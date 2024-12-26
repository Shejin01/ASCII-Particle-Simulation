#include "Particle.h"

Vector2 Particle::gravity(0, 10.0f);
float Particle::radius = 2.5f;
float Particle::mass = 1.0f;
float Particle::wall_friction = 0.0f;

Particle::Particle(Vector2 position, Vector2 velocity)
	: position(position), velocity(velocity) {}

void Particle::Update(float dt) {
	velocity += gravity * dt;
	position += velocity * dt;
}

bool Particle::ResolveCollision(Particle* other) {
	Vector2 dir = position - other->position;
	float distanceSqr = dir.MagnitudeSqr();
	if (distanceSqr > 4*radius*radius) return false;

	Vector2 newV1 = velocity - (position - other->position) * ((velocity - other->velocity).Dot(position - other->position) / (position - other->position).MagnitudeSqr());
	Vector2 newV2 = other->velocity - (other->position - position) * ((other->velocity - velocity).Dot(other->position - position) / (other->position - position).MagnitudeSqr());
	
	position += dir * 0.5;
	other->position -= dir * 0.5;

	velocity = newV1;
	other->velocity = newV2;
	
	return true;
}

bool Particle::ResolveBoundaryCollision(int left, int top, int width, int height) {
	bool collide = false;
	if (position.x - radius <= left) { // Left
		position.x = 2 * radius - position.x;
		velocity.x *= -(1 - wall_friction);
		collide = true;
	}
	else if (position.x + radius >= left + width) { // Right
		position.x = 2 * (left + width) - 2 * radius - position.x;
		velocity.x *= -(1 - wall_friction);
		collide = true;
	}
	if (position.y - radius <= top) { // Top
		position.y = 2 * radius - position.y;
		velocity.y *= -(1 - wall_friction);
		collide = true;
	}
	else if (position.y + radius >= top + height) { // Bottom
		position.y = 2 * (top + height) - 2 * radius - position.y;
		velocity.y *= -(1 - wall_friction);
		collide = true;
	}
	return collide;
}

float Particle::Clamp(float value, float min, float max) {
	return fmin(fmax(value, min), max);
}