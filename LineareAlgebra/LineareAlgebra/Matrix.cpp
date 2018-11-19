#include "Matrix.h"

Matrix::Matrix(unsigned int rows) : _rows(rows){}

void Matrix::AddVector(Vector && vector)
{
	if (vector.getSize() == _rows) {
		matrix.push_back(std::move(vector));
		_columns++;
	}
}

Matrix Matrix::operator+(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	if (other._columns == this->_columns && other._rows == this->_rows) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(this->matrix[i] + other.matrix[i]);
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
		for (int c = 0;c < other._columns;c++) {
			Vector v;
			for (int r = 0;r < _rows;r++) {
				
				//TODO grotere vectoren

			}
		}
	}
	return m;
}



Matrix::~Matrix()
{
}
