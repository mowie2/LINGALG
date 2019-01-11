#pragma once
#include "Vector3f.h"
#include "Matrix4x4.h"

class Camera
{
public:
	Camera(Vector3f position, Vector3f lookat ,float nearPlane, float farPlane,float fovy);
	Matrix4x4f getTranformationMAtrix() const;
	Matrix4x4f getTranslationMAtrix() const;
	Matrix4x4f getperspectiveMAtrix() const;
	~Camera() = default;
private:
	Vector3f position_;
	Vector3f lookat_;
	float nearPlane_;
	float farPlane_;
	float fovy_;
};
