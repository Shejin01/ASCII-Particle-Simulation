#include "Renderer.h"
#include "Particle.h"
#include <Windows.h>
#include <vector>

const int FRAME_WIDTH = 75, FRAME_HEIGHT = 25;
const int FPS = 30;
const float DT = 1.0f / (float)FPS;

int main() {
	Renderer::SetFrameSize(FRAME_WIDTH, FRAME_HEIGHT);

	/*std::vector<Particle> particles = {
		{ Vector2(15, 4), Vector2(-10, 5) },
		{ Vector2(40, 4) },
		{ Vector2(65, 4), Vector2(10, 0) }
	};*/

	std::vector<Particle> particles;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			particles.push_back({ Vector2(8 + i + 15 * j, 5 + 6 * i) });
		}
	}

	while (true) {
		for (auto& particle : particles) {
			particle.Update(DT);
			particle.ResolveBoundaryCollision(1, 1, FRAME_WIDTH-1, FRAME_HEIGHT);
		}
		for (int i = 0; i < particles.size(); i++) {
			for (int j = i+1; j < particles.size(); j++) {
				particles[i].ResolveCollision(&particles[j]);
			}
		}

		Renderer::ClearFrame();
		for (auto& particle : particles)
			Renderer::DrawCircle(particle.position.x - Particle::radius, particle.position.y - Particle::radius);
		Renderer::DrawBoundingBox('#', 0, 0, FRAME_WIDTH, FRAME_HEIGHT);
		Renderer::DisplayFrame();
		Sleep(30);
	}

	return 0;
}