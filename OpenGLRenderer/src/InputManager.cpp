#include "InputManager.h"
#include <iostream>

glm::vec2 InputManager::m_lastOffset = {0, 0};

InputManager::InputManager() {

}

InputManager::InputManager(GLFWwindow* window) {
	m_window = window;
	glfwSetCursorPosCallback(m_window, defaultMouseCallback);
	
}

InputManager::~InputManager() {

}

bool InputManager::KeyDown(int glfwKey) {
	if (m_window != nullptr)
		if (glfwGetKey(m_window, glfwKey) == GLFW_PRESS)
			return true;
		else
			return false;
	else
		std::cerr << "[Error] InputManager has no Specified GL Context.\n";
	return false;

}

bool InputManager::KeyPressed(int glfwKey) {
	if (m_window != nullptr)
		if (glfwGetKey(m_window, glfwKey) == GLFW_REPEAT)
			return true;
		else
			return false;
	else
		std::cerr << "[Error] InputManager has no Specified GL Context.\n";
	return false;
}

bool InputManager::KeyUp(int glfwKey) {
	if (m_window != nullptr)
		if (glfwGetKey(m_window, glfwKey) == GLFW_RELEASE)
			return true;
		else
			return false;
	else
		std::cerr << "[Error] InputManager has no Specified GL Context.\n";
	return false;
}

glm::vec2 InputManager::getMouseOffset() {
	glm::vec2 res = m_lastOffset;
	m_lastOffset;
	return res;
}

void InputManager::setCursorVisible(bool visible) {
	if (m_window != nullptr)
		if(!visible)
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		else
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	else
		std::cerr << "[Error] InputManager has no Specified GL Context.\n";
}

void InputManager::setWindow(GLFWwindow* window) {
	m_window = window;
}
