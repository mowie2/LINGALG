#pragma once
#include <vector>
#include "include/Vector.h"

class Matrix3f
{
public:
	Matrix3f(unsigned int rows);
	~Matrix3f() = default;

	Vector get_row(unsigned int row) const;
	//Vector get_column(unsigned int column) const;
	//Vector& operator[](unsigned int index);
	//Matrix3f operator+(const Matrix3f&other) const;
	//Matrix3f operator-(const Matrix3f&other) const;
	//Matrix3f operator*(const Matrix3f&other) const;
	
	static Matrix3f get_identity_matrix();
private:
	std::vector<Vector> matrix_;
	unsigned int columns_;
};

