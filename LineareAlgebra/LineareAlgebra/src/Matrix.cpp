#include "../include/Matrix.h"
#include <map>



Matrix::Matrix(unsigned int rows) : _rows(rows){}

Matrix Matrix::operator+(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	if (other._columns == this->_columns && other._rows == this->_rows) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(matrix[i] + other.matrix[i]);
		}
		return m;
	}
	throw std::invalid_argument("invalid");
}

Matrix Matrix::operator-(const Matrix & other) const
{
	Matrix m = Matrix(this->_rows);
	if (other._columns == this->_columns && other._rows == this->_rows) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(this->matrix[i] + other.matrix[i]);
		}
		return m;
	}
	throw std::invalid_argument("invalid");
}


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
		return m;
	}
	throw std::invalid_argument("invalid");
}

Matrix Matrix::operator*(float scalar) const
{
	Matrix m = Matrix(this->_rows);
	for (int c = 0;c < _columns;c++) {
		Vector v;
		for (int r = 0;r < _rows;r++) {
			v.addNumber(matrix[c][r] * scalar);
		}
		m.AddVector(v);
	}
	return m;
}

Vector Matrix::operator[](unsigned int index) const
{
	if (index >= 0 && index < _columns) {
		return matrix[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

unsigned int Matrix::getRows() const
{
	return _rows;
}

unsigned int Matrix::getColumns() const
{
	return _columns;
}



Matrix::~Matrix()
{
}
