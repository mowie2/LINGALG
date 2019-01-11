#pragma once
class Camera
{
public:
	Camera(float nearPlane, float farPlane);
	~Camera() = default;
private:
	float nearPlane_;
	float farPlane_;

};