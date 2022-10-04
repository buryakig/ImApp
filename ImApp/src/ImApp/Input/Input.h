#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace ImApp 
{
	class Input
	{
	public:
		static bool IsKeyDown(GLuint keyCode);
		static bool IsMouseButtonDown(GLuint mButtonCode);
		static glm::vec2 GetMousePos();
		static void SetCursorMode(GLuint cursMode);
	};
}