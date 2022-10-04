#include "../Application.h"
#include "Input.h"

namespace ImApp 
{
	bool Input::IsKeyDown(GLuint keyCode)
	{
		GLFWwindow* windowHandle = Application::GetInstance().GetWindowHandle();
		int state = glfwGetKey(windowHandle, (int)keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseBttonDown(GLuint mButtonCode)
	{
		GLFWwindow* windowHandle = Application::GetInstance().GetWindowHandle();
		int state = glfwGetMouseButton(windowHandle, (int)mButtonCode);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePos()
	{
		GLFWwindow* windowHandle = Application::GetInstance().GetWindowHandle();

		double x, y;
		glfwGetCursorPos(windowHandle, &x, &y);
		return { (float)x, (float)y };
	}

	void Input::SetCursorMode(GLuint cursMode)
	{
		GLFWwindow* windowHandle = Application::GetInstance().GetWindowHandle();
		glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)cursMode);
	}
}