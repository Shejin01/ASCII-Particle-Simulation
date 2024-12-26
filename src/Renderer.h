#pragma once

#include <iostream>
#include <string>

class Renderer {
private:
	static std::string frame;
	static std::string circle_sprite;
	static int frame_width;
	static int frame_height;
public:
	static void SetFrameSize(int width, int height);
	static void DrawBoundingBox(char letter, int x, int y, int width, int height);
	static void DrawCircle(int x ,int y);
	static void ClearFrame();
	static void DisplayFrame();
};