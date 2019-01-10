#include "Matrix3f.h"


Matrix3f::Matrix3f(const Matrix & original)
{
	if(original.getRows() == 3)
	{
		matrix_ = original;
	}
}

Matrix3f::Matrix3f(unsigned int columns)
{
	matrix_ = Matrix(3,columns,false);
}

Vector Matrix3f::get_row(unsigned int row) const
{
	Vector rowVector;
	for(unsigned int i = 0;i<matrix_.getColumns();i++)
	{
		rowVector.addNumber(matrix_[i][row]);
	}
	return rowVector;
}

Vector Matrix3f::get_column(unsigned int column) const
{
	return matrix_[column];
}

Vector & Matrix3f::operator[](unsigned int index)
{
	return matrix_[index];
}

Matrix3f Matrix3f::operator+(const Matrix3f & other) const
{
	if(matrix_.getColumns() == other.matrix_.getColumns())
	{
		Matrix3f m(matrix_.getColumns());
		for(int i = 0; i< matrix_.getColumns();i++)
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
		for (int i = 0; i < matrix_.getColumns();i++)
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
	return matrix_*other;
}

Matrix3f Matrix3f::translate(const Vector3f& vec) const
{
	return matrix_.translate(vec.getVector());
}

Matrix3f Matrix3f::get_identity_matrix()
{
	auto m = Matrix3f(3);
	for(auto i = 0;i<3;i++)
	{
		//m[i][i] = 1;
	}
	return m;

}
