#include "..\include\Camera.h"
#include "../include/Physics.h"
#include <SDL_stdinc.h>
#include "../include/Matrix3f.h"
#include <iostream>

Camera::Camera(Vector3f position, Vector3f lookat, float nearPlane, float farPlane, float fovy)
{
	position_ = position;
	lookat_ = lookat;
	nearPlane_ = nearPlane;
	farPlane_ = farPlane;
	fovy_ = fovy;

	auto direction = position_ - lookat_;
	Physics p;
	auto up = Vector3f(0, 1, 0);
	right_ = p.calculateOutProduct(direction, up);
	up_ = p.calculateOutProduct(right_, direction);

	right_.normalize();
	up_.normalize();
}

Matrix4x4f Camera::getTranformationMatrix() const
{
	auto k = getPerspectiveMatrix();
	auto k1 = getTranslationMatrix();
	//auto k3 = k * k1;
	auto k3 = k;
	return k3;
}

Matrix4x4f Camera::getTranslationMatrix() const
{
	auto direction = position_ - lookat_;
	direction.normalize();

	//Physics p;
	//auto up = Vector3f(0, 1, 0);

	//auto right = p.calculateOutProduct(direction,up);
	//right.normalize();
	//up = p.calculateOutProduct(right, direction);
	//up.normalize();
	auto m = Matrix4x4f::getIdentityMatrix();
	m[0][0] = right_[0];
	m[1][0] = right_[1];
	m[2][0] = right_[2];

	m[0][1] = up_[0];
	m[1][1] = up_[1];
	m[2][1] = up_[2];

	m[0][2] = direction[0];
	m[1][2] = direction[1];
	m[2][2] = direction[2];

	auto m1 = Matrix4x4f::getIdentityMatrix();
	m1[3][0] = -1*position_[0];
	m1[3][1] = -1*position_[1];
	m1[3][2] = -1*position_[2];
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

void Camera::rotate(Vector3f vec)
{
	Matrix3f m;
	m.AddVector(position_,right_,up_);
	auto x = Matrix4x4f::getXRotationMatrix(vec[0]).getMatrix();
	auto y = Matrix4x4f::getYRotationMatrix(vec[1]).getMatrix();
	auto z = Matrix4x4f::getZRotationMatrix(vec[2]).getMatrix();
	auto k = (x*y*z*m.getTranslatable()).subSet(3,3);
	position_ = k[0];
	right_ = k[1];
	right_.normalize();
	up_ = k[2];
	up_.normalize();
}

void Camera::rotate2(Vector3f vec)
{

	auto heading_2 = position_ - lookat_;
	Matrix3f m2;
	m2.AddVector(position_, right_, up_);
	auto m = m2.getTranslatable();
	///step 1
	float zx = 90;
	if (heading_2[0] != 0) {
		zx = heading_2[2] / heading_2[0];

		std::cout << zx<<"\n";
		zx = atanf(zx) / M_PI * 180;
	}
	auto step1M = Matrix4x4f::getYRotationMatrix(zx);

	///step3
	auto step3M = Matrix4x4f::getXRotationMatrix(vec[2]);
	step3M = Matrix4x4f::getYRotationMatrix(vec[1]) * step3M;
	step3M = Matrix4x4f::getZRotationMatrix(vec[0]) * step3M;

	///step5
	auto step5M = step1M;
	step5M[2][0] = step1M[2][0] * -1;
	step5M[0][2] = step1M[0][2] * -1;

	auto lookatToOrigin = Matrix4x4f::getIdentityMatrix();
	lookatToOrigin[3][0] = -1 * lookat_[0];
	lookatToOrigin[3][1] = -1 * lookat_[1];
	lookatToOrigin[3][2] = -1 * lookat_[2];

	auto returnMatrix = Matrix4x4f::getIdentityMatrix();
	returnMatrix[3][0] = lookat_[0];
	returnMatrix[3][1] = lookat_[1];
	returnMatrix[3][2] = lookat_[2];


//	auto rotation = step5M * step3M *step1M;
	auto rotation = step5M * step3M *step1M;

	for(int i = 0 ; i<4;i++)
	{
		for (int j = 0; j < 4;j++)
		{
			std::cout << step1M[j][i] << "           ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	auto k = rotation.getMatrix()*m[0];
	position_ = ((returnMatrix * rotation * lookatToOrigin).getMatrix()*m[0]).subset(0, 3);//((returnMatrix *rotation*lookatToOrigin).getMatrix()*m[0]).subset(0,3);
	right_ = (rotation.getMatrix()*m[1]).subset(0, 3);
	up_ = (rotation.getMatrix()*m[2]).subset(0, 3);

	/*
	position_ = (rotation.getMatrix()*m[0]).subset(0, 3);//((returnMatrix *rotation*lookatToOrigin).getMatrix()*m[0]).subset(0,3);
	right_ = (rotation.getMatrix()*m[1]).subset(0, 3);
	up_ = (rotation.getMatrix()*m[2]).subset(0, 3);
	*/
}

void Camera::move(Vector3f vec)
{
	position_ = position_ + vec;
	lookat_ = lookat_ + vec;
}
