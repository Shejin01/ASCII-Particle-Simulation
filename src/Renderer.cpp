#include "Renderer.h"

std::string Renderer::frame;
std::string Renderer::circle_sprite =
	" @@@ "
	"@   @"
	"@   @"
	" @@@ ";
int Renderer::frame_width;
int Renderer::frame_height;

void Renderer::SetFrameSize(int width, int height) {
	frame_width = width;
	frame_height = height;
	frame = std::string((width+1) * height, ' ');
	for (int i = 0; i < height; i++) {
		frame[i * (width + 1) + width] = '\n';
	}
}

void Renderer::DrawBoundingBox(char letter, int x, int y, int width, int height) {
	int limitedHeight = fmin(height, frame_height - y);
	for (int i = fmax(0, -y); i < limitedHeight; i++) {
		int startIndex = (y + i) * (frame_width + 1) + x;
		if (i == 0 || i == height - 1) {
			for (int j = 0; j < width; j++) frame[startIndex + j] = letter;
			continue;
		}
		frame[startIndex] = letter;
		frame[startIndex + width - 1] = letter;
	}
}

void Renderer::DrawCircle(int x, int y) {
	int limitedWidth = fmin(5, frame_width - x);
	int limitedHeight = fmin(4, frame_height - y);
	for (int i = fmax(0, -y); i < limitedHeight; i++) {
		int startIndex = (y + i) * (frame_width + 1) + x;
		for (int j = fmax(0, -x); j < limitedWidth; j++) {
			frame[startIndex + j] = circle_sprite[j + 5 * i];
		}
	}
}

void Renderer::ClearFrame() {
	frame = std::string((frame_width + 1) * frame_height, ' ');
	for (int i = 0; i < frame_height; i++) {
		frame[i * (frame_width + 1) + frame_width] = '\n';
	}
}

void Renderer::DisplayFrame() {
	std::cout << "\x1B[H" << frame;
}