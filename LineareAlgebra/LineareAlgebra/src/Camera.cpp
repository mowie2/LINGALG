#include "..\include\Camera.h"

Camera::Camera(Vector3f position, Vector3f lookat, float nearPlane, float farPlane, float fovy)
{
	position_ = position;
	lookat_ = lookat;
	nearPlane_ = nearPlane;
	farPlane_ = farPlane;
	fovy_ = fovy;
}

Matrix4x4f Camera::getTranformationMAtrix() const
{

	return Matrix4x4f();
}

Matrix4x4f Camera::getTranslationMAtrix() const
{
	return Matrix4x4f();
}

Matrix4x4f Camera::getperspectiveMAtrix() const
{
	auto direction = position_ - lookat_;
	return Matrix4x4f();
}
