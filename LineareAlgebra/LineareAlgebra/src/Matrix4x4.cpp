#include <SDL_stdinc.h>
#include "../include/Matrix4x4.h"

Matrix4x4f::Matrix4x4f(const Matrix & original)
{
	if(original.getRows() == 4 && original.getColumns() == 4)
	{
		matrix_ = original;
	}else
	{
		throw std::invalid_argument("original must be 4x4");
	}
}

Matrix4x4f::Matrix4x4f()
{
	matrix_ = Matrix(4, 4);
}


Vector & Matrix4x4f::operator[](unsigned int index)
{
	return matrix_[index];
}

Vector Matrix4x4f::operator[](unsigned int index) const
{
	return matrix_[index];
}

Matrix4x4f Matrix4x4f::operator+(const Matrix4x4f & other) const
{
	return matrix_+other.matrix_;
}

Matrix4x4f Matrix4x4f::operator-(const Matrix4x4f & other) const
{
	return matrix_-other.matrix_;
}

Matrix Matrix4x4f::operator*(const Matrix & other) const
{
	return matrix_*other;
}

Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f & other) const
{
	return Matrix4x4f(matrix_ * other.matrix_);
}

Matrix Matrix4x4f::getMatrix() const
{
	return matrix_;
}

Matrix4x4f Matrix4x4f::getIdentityMatrix()
{
	return Matrix4x4f(Matrix::getIdentityMatrix(4));
}

Matrix4x4f Matrix4x4f::getXRotationMatrix(float degrees)
{
	auto m = Matrix4x4f();
	m[0][0] = 1;
	m[1][1] = std::cos(degrees / 180 * M_PI);
	m[1][2] = std::sin(degrees / 180 * M_PI);
	m[2][1] = -1 * std::sin(degrees / 180 * M_PI);
	m[2][2] = std::cos(degrees / 180 * M_PI);
	m[3][3] = 1;
	return m;
}

Matrix4x4f Matrix4x4f::getYRotationMatrix(float degrees)
{
	auto m = Matrix4x4f();
	m[0][0] = std::cos(degrees / 180 * M_PI);
	m[1][1] = 1;
	m[2][0] = std::sin(degrees / 180 * M_PI);
	m[0][2] = -1 * std::sin(degrees / 180 * M_PI);
	m[2][2] = std::cos(degrees / 180 * M_PI);
	m[3][3] = 1;
	return m;
}

Matrix4x4f Matrix4x4f::getZRotationMatrix(float degrees)
{
	auto m = Matrix4x4f();
	m[0][0] = std::cos(degrees / 180 * M_PI);
	m[0][1] = -1 * std::sin(degrees / 180 * M_PI);
	m[1][0] = std::sin(degrees / 180 * M_PI);
	m[1][1] = std::cos(degrees / 180 * M_PI);
	m[2][2] = 1;
	m[3][3] = 1;
	return m;
}
