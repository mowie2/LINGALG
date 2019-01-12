#include "../include/Matrix3f.h"


Matrix3f::Matrix3f(const Matrix & original)
{
	if (original.getRows() == 3)
	{
		matrix_ = original;
	}
	else
	{
		throw std::invalid_argument("rows must be 3");
	}
}

Matrix3f::Matrix3f(unsigned int columns)
{
	matrix_ = Matrix(3, columns);
}

Vector Matrix3f::get_row(unsigned int row) const
{
	Vector rowVector;
	for (unsigned int i = 0; i < matrix_.getColumns(); i++)
	{
		rowVector.addNumber(matrix_[i][row]);
	}
	return rowVector;
}

Vector3f Matrix3f::get_column(unsigned int column) const
{
	return Vector3f(matrix_[column]);
}

unsigned int Matrix3f::getColumns() const
{
	return matrix_.getColumns();
}

Vector & Matrix3f::operator[](unsigned int index)
{
	return matrix_[index];
}

Matrix3f Matrix3f::operator+(const Matrix3f & other) const
{
	if (matrix_.getColumns() == other.matrix_.getColumns())
	{
		Matrix3f m(matrix_.getColumns());
		for (int i = 0; i < matrix_.getColumns(); i++)
		{
			m[i][0] = matrix_[i][0] + other.matrix_[i][0];
			m[i][1] = matrix_[i][1] + other.matrix_[i][1];
			m[i][2] = matrix_[i][2] + other.matrix_[i][2];
		}
		return m;
	}
	throw std::invalid_argument("columns are not the same");
}

Matrix3f Matrix3f::operator-(const Matrix3f & other) const
{
	if (matrix_.getColumns() == other.matrix_.getColumns())
	{
		Matrix3f m(matrix_.getColumns());
		for (int i = 0; i < matrix_.getColumns(); i++)
		{
			m[i][0] = matrix_[i][0] - other.matrix_[i][0];
			m[i][1] = matrix_[i][1] - other.matrix_[i][1];
			m[i][2] = matrix_[i][2] - other.matrix_[i][2];
		}
		return m;
	}
	throw std::invalid_argument("columns are not the same");
}

Matrix Matrix3f::operator*(const Matrix & other) const
{
	return matrix_ * other;
}

Matrix4x4f Matrix3f::getTranslatable() const
{
	return Matrix4x4f(matrix_.getTranslatable());
}


Matrix Matrix3f::getMatrix() const
{
	return matrix_;
}



Matrix3f Matrix3f::getIdentityMatrix()
{
	return Matrix3f(Matrix::getIdentityMatrix(3));
}

