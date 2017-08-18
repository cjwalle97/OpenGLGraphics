#include "Application.h"
#include <GLFW\glfw3.h>


Application::Application()
{
}


Application::~Application()
{
}

void run(const char* title, unsigned int width, unsigned int height, bool fullscreen)
{
	startup();
	if (glfwInit() == GL_FALSE)
	{
		GLFWmonitor* monitor = (fullscreen) ? glfwGetPrimaryMonitor() : nullptr;

		m_window = glfwCreateWindow(width, height, title, moniter, nullptr);

		double prevTime = glfwGetTime();
		double currTime = 0;
		double deltaTime = 0;
		while (!m_gameover)
		{
			currTime = glfwGetTime();
			deltaTime - currTime - prevTime;
			prevTime = currTime;
			glfwPollEvents();
			update(deltaTime);
			draw();
			glfwSwapBuffers(m_window);
			m_gameover = (glfwWindowShouldClose(m_window) == GLFW_TRUE);
		}
	}
}
