#include "Matrix.h"
#include <map>



Matrix::Matrix(unsigned int rows) : _rows(rows){}

/*
void Matrix::AddVector(const Vector & vector)
{
	if (vector.getRows() == _rows) {
		matrix.push_back(std::move(vector));
		_columns++;
	}
}*/

Matrix Matrix::operator+(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	if (other._columns == this->_columns && other._rows == this->_rows) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(matrix[i] + other.matrix[i]);
		}
	}
	return m;
}

Matrix Matrix::operator-(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	if (other._columns == this->_columns && other._rows == this->_rows) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(this->matrix[i] + other.matrix[i]);
		}
	}
	return m;
}
/*
Matrix Matrix::operator*(const Vector & other) const
{
	if (this->_rows == other.getSize()) {
		
	}
}*/

Matrix Matrix::operator*(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	
	if (other._rows == this->_columns) {
		for (int c1 = 0;c1 < other._columns;c1++) {
			Vector v1;
			for (int r = 0;r < other._rows;r++) {
				Vector v2;
				for (int c2 = 0;c2 < _columns;c2++) {
					v2.addNumber(this->matrix[c2][r]);
				}
				v1.addNumber(v2*other.matrix[c1]);
			}
			m.AddVector(v1);
		}
	}
	return m;
}



Matrix::~Matrix()
{
}
