#include "Gizmos.h"
#include <GLFW\glfw3.h>>
#include <stdio.h>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>
using glm::vec2;
using glm::vec3;
using glm::mat4;

int main()
{
	glm::vec3 v = glm::vec3(1, 1, 1);

	if (!glfwInit())
	{
		printf("no glfw");
	}

	GLFWwindow* window = glfwCreateWindow(800, 800, "regi is da best", nullptr, nullptr);

	Gizmos::create();

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));

	while (true)
	{
		glfwPollEvents();
		if (glfwWindowShouldClose(window))
		{
			break;
		}
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, true);
		}
	}

	return 0;
}