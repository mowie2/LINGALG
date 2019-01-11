#include "..\include\Camera.h"
#include "../include/Physics.h"

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
	auto direction = (position_ - lookat_);
	direction.normalize();

	Physics p;
	auto up = Vector3f(0, 1, 0);
	auto right = p.calculateOutProduct(up, direction);
	up = p.calculateOutProduct(direction, right);
	auto m = Matrix4x4f::getIdentityMatrix();
	m[0][0] = right[0];
	m[1][0] = right[1];
	m[2][0] = right[2];

	m[0][1] = up[0];
	m[1][1] = up[1];
	m[2][1] = up[2];

	m[0][2] = direction[0];
	m[1][2] = direction[1];
	m[2][2] = direction[2];

	return m;
}
