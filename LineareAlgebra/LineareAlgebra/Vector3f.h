#pragma once
#include <vector>
#include "include/Vector.h"

class Vector3f
{
public:
	Vector3f();
	Vector3f(float x,float y, float z);
	~Vector3f();

	float& operator[](unsigned int index);
	float operator[](unsigned int index) const;
	Vector3f operator+(const Vector3f& other);
	Vector3f operator-(const Vector3f& other);
	float operator*(const Vector3f& other);
	Vector getVector() const;

private:
	Vector vector_;
};

