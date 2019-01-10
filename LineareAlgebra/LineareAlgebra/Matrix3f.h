#pragma once
#include <vector>
#include "include/Vector.h"
#include "include/Matrix.h"
#include "Vector3f.h"

class Matrix3f
{
public:

	Matrix3f(const Matrix& original);
	Matrix3f(unsigned int columns);
	~Matrix3f() = default;
	
	Vector get_row(unsigned int row) const;
	Vector get_column(unsigned int column) const;
	Vector& operator[](unsigned int index);
	Matrix3f operator+(const Matrix3f&other) const;
	Matrix3f operator-(const Matrix3f&other) const;
	Matrix operator*(const Matrix&other) const;
	Matrix3f translate(const Vector3f& vec) const;
	Matrix3f scale();

	static Matrix3f get_identity_matrix();
private:
	Matrix matrix_;
};

