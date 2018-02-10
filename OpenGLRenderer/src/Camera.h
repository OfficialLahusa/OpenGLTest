#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVTY = 0.1f;
const float ZOOM = 45.0f;

class Camera {

private:
	glm::mat4 m_ViewMatrix;

public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float fov;
	float aspectRatio;
	float near;
	float far;

	

	float Yaw;
	float Pitch;

	float pMovementSpeed;
	float pMouseSensitivity;
	float pZoom;


	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH)
		: Front(glm::vec3(0.0f, 0.0f, -1.0f))
		, pMovementSpeed(SPEED)
		, pMouseSensitivity(SENSITIVTY)
		, pZoom(ZOOM) {
		Position = position;
		WorldUp = up;
		Yaw = yaw;
		Pitch = pitch;
		updateCameraVectors();
	}

	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
		: Front(glm::vec3(0.0f, 0.0f, -1.0f))
		, pMovementSpeed(SPEED)
		, pMouseSensitivity(SENSITIVTY)
		, pZoom(ZOOM) {
		Position = glm::vec3(posX, posY, posZ);
		WorldUp = glm::vec3(upX, upY, upZ);
		Yaw = yaw;
		Pitch = pitch;
		updateCameraVectors();
	}


	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	void Translate(Camera_Movement direction, float deltaTime);
	void MouseRotate(float xoffset, float yoffset, GLboolean constrainPitch = true);
	void Zoom(float yoffset);

	//void lookAt(glm::vec3 pos);

	private:
	void updateCameraVectors();
};