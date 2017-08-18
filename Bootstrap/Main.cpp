#include "Gizmos.h"
#include <GLFW\glfw3.h>>
#include <stdio.h>
#include <assert.h>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include "gl_core_4_4.h"
#include <iostream>
#include "IntroductionApp.h"
using glm::vec2;
using glm::vec3;
using glm::mat4;

int main()
{
	auto app = new IntroductionApp();

	glm::vec3 v = glm::vec3(1, 1, 1);

	if (!glfwInit())
	{
		printf("no glfw");
	}

	GLFWwindow* window = glfwCreateWindow(800, 800, "regi is da best", nullptr, nullptr);

	Gizmos::create();

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	assert(window != nullptr);
	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();

	printf("GL: %i.%i\n", major, minor);
	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	glm::vec4 clearcolor = glm::vec4(0.5f, 0.5f, 1.0f, 1.0f);
	while (true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		if (glfwWindowShouldClose(window))
		{
			break;
		}
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			Gizmos::destroy();
			glfwSetWindowShouldClose(window, true);
		}
		if (glfwGetKey(window, GLFW_KEY_F))
		{
			clearcolor.r -= .1f;
			clearcolor.g -= 1.f;
			clearcolor.b -= 1.f;
			printf("clearcolor r => %f\n", clearcolor.r);
		}
		glClearColor(clearcolor.r, clearcolor.g, clearcolor.b, clearcolor.a);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}