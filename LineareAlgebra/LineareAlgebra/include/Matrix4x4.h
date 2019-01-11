#pragma once
#pragma once
#include "Vector.h"
#include "Matrix.h"

class Matrix4x4f
{
public:
	Matrix4x4f(const Matrix& original);
	Matrix4x4f();
	~Matrix4x4f() = default;

	Vector& operator[](unsigned int index);
	Vector operator[](unsigned int index) const;
	Matrix4x4f operator+(const Matrix4x4f&other) const;
	Matrix4x4f operator-(const Matrix4x4f&other) const;
	Matrix operator*(const Matrix&other) const;
	Matrix4x4f operator*(const Matrix4x4f&other) const;
	Matrix getMatrix() const;
	static Matrix4x4f getIdentityMatrix();
	static Matrix4x4f getXRotationMatrix(float degrees);
	static Matrix4x4f getYRotationMatrix(float degrees);
	static Matrix4x4f getZRotationMatrix(float degrees);
private:
	Matrix matrix_;
};