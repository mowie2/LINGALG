#include "..\include\Camera.h"
#include "../include/Physics.h"
#include <SDL_stdinc.h>

Camera::Camera(Vector3f position, Vector3f lookat, float nearPlane, float farPlane, float fovy)
{
	position_ = position;
	lookat_ = lookat;
	nearPlane_ = nearPlane;
	farPlane_ = farPlane;
	fovy_ = fovy;
}

Matrix4x4f Camera::getTranformationMatrix() const
{
	auto k = getPerspectiveMatrix();
	auto k1 = getTranslationMatrix();
	auto k3 = k * k1;
	return k3;
}

Matrix4x4f Camera::getTranslationMatrix() const
{
	auto direction = position_ - lookat_;
	direction.normalize();

	Physics p;
	auto up = Vector3f(0, 1, 0);
	auto right = p.calculateOutProduct(direction,up);
	right.normalize();
	up = p.calculateOutProduct(right, direction);
	up.normalize();
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

	auto m1 = Matrix4x4f::getIdentityMatrix();
	m1[3][0] = position_[0];
	m1[3][1] = position_[1];
	m1[3][2] = position_[2];
	return m * m1;
}

Matrix4x4f Camera::getPerspectiveMatrix() const
{
	auto k1 = fovy_ / 180 * M_PI;
	auto k2 = k1 *.5f;
	auto k3 = std::tan(k2);
	auto k4 = nearPlane_ * k3;
	auto scale = k4;
	//auto scale = nearPlane_ * std::tan ((fovy_ / 180 * M_PI)/.5f);
	auto m = Matrix4x4f();

	auto a1 = (-1 * farPlane_) / (farPlane_ - nearPlane_);
	auto a2 = ((-1 * farPlane_)*nearPlane_) / (farPlane_ - nearPlane_);

	m[0][0] = scale;
	m[1][1] = scale;
	m[2][2] = (-1 * farPlane_) / (farPlane_ - nearPlane_);
	m[2][3] = ((-1 * farPlane_)*nearPlane_) / (farPlane_ - nearPlane_);
	m[3][2] = -1;

	return m;
}
