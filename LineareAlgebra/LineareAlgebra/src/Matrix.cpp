#include "../include/Matrix.h"
#include <map>
#include <algorithm>



Matrix::Matrix()
= default;

Matrix::Matrix(unsigned int rows, unsigned int columns, bool eenheidsMatrix)
{
	this->rows = rows;
	this->columns = columns;
	for (int c = 0; c < this->columns;c++) {
		Vector v;
		for (int r = 0; r < rows;r++) {
			if (eenheidsMatrix && c == r) {
				v.addNumber(1);
				continue;
			}
			v.addNumber(0);
		}
		matrix.push_back(v);
	}
}

Matrix Matrix::operator+(const Matrix & other) const
{
	Matrix m;
	if (other.columns == this->columns && other.getRows() == this->getRows()) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(matrix[i] + other.matrix[i]);
		}
		return m;
	}
	throw std::invalid_argument("invalid");
}

Matrix Matrix::operator-(const Matrix & other) const
{
	Matrix m;
	if (other.columns == this->columns && other.getRows() == this->getRows()) {
		for (int i = 0;i < matrix.size();i++) {
			m.AddVector(this->matrix[i] + other.matrix[i]);
		}
		return m;
	}
	throw std::invalid_argument("invalid");
}


Matrix Matrix::operator*(const Matrix & other) const
{
	if (other.getRows() == this->columns) {
		Matrix m;
		for (int c1 = 0;c1 < other.columns;c1++) {
			Vector v1;
			for (int r = 0;r < getRows();r++) {
				Vector v2;
				for (int c2 = 0;c2 < columns;c2++) {
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
	Matrix m;
	for (int c = 0;c < columns;c++) {
		Vector v;
		for (int r = 0;r < getRows();r++) {
			v.addNumber(matrix[c][r] * scalar);
		}
		m.AddVector(v);
	}
	return m;
}

Vector Matrix::operator[](unsigned int index) const
{
	if (index >= 0 && index < columns) {
		return matrix[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

Vector & Matrix::operator[](unsigned int index)
{
	if (index >= 0 && index < columns) {
		return matrix[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

unsigned int Matrix::getRows() const
{
	return rows;
}

unsigned int Matrix::getColumns() const
{
	return columns;
}

Matrix Matrix::translate(const Vector& translation) const
{
	if (translation.getRows() == getRows()) {
		Matrix currentMatrix;
		for (auto copyVector : matrix) {
			copyVector.addNumber(1);
			currentMatrix.AddVector(copyVector);
		}

		Matrix translationMatrix(getRows() + 1, getRows(), true);
		auto translationCopy = translation;
		translationCopy.addNumber(1);
		translationMatrix.AddVector(translationCopy);

		auto translatedMatrix = translationMatrix * currentMatrix;
		


		return translationMatrix * currentMatrix;
	}
	throw std::out_of_range("Invalid");
}

Matrix Matrix::translateToOrgin() const
{
	Vector translation;
	for (int r = 0; r < getRows(); r++) {
		float avg = 0.0;
		for (int c = 0; c < columns; c++) {
			avg+=matrix[c][r];
		}
		avg /= columns;
		translation.addNumber(-1*avg);
	}
	return translate(translation);
}



Matrix::~Matrix()
{
}
