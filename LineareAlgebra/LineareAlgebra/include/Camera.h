#pragma once
#include "Vector3f.h"
#include "Matrix4x4.h"

class Camera
{
public:
	Camera(Vector3f position, Vector3f lookat ,float nearPlane, float farPlane,float fovy);
	Matrix4x4f getTranformationMatrix() const;
	Matrix4x4f getTranslationMatrix() const;
	Matrix4x4f getPerspectiveMatrix() const;
	void rotate(Vector3f vec);
	void rotate2(Vector3f vec);
	void move(Vector3f vec);
	~Camera() = default;
private:
	Vector3f right_;
	Vector3f up_;
	Vector3f position_;
	Vector3f lookat_;
	float nearPlane_;
	float farPlane_;
	float fovy_;
};
