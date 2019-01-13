#include "../include/Vector.h"
#include <cmath>

Vector::Vector(unsigned int rows)
{
	for (unsigned int i = 0;i < rows;i++) {
		vector_.push_back(0);
	}
}

Vector::~Vector()
{
}

unsigned int Vector::getRows() const
{
	return vector_.size();
}

//void Vector::addNumber(float number)
//{
//	vector.push_back(number);
//}

void Vector::normalize()
{
	const float length = getLength();
	if (length != 0) {
		for (auto &i : vector_) {
			i = i / length;
		}
	}
}

float Vector::operator[](unsigned index) const
{
	if (index < vector_.size() && index >= 0) {
		return vector_[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

float & Vector::operator[](unsigned index)
{
	if (index < vector_.size() && index >= 0) {
		return vector_[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

Vector & Vector::operator=(const Vector & other)
{
	if(other.getRows() == getRows())
	{
		vector_ = other.vector_;
		return *this;
	}
	throw std::invalid_argument("the vector is not of the same size");
}

float Vector::operator*(const Vector & other) const
{
	if (other.vector_.size() == vector_.size()) {
		float f = 0.0;
		for (int i = 0; i < vector_.size();i++) {
			f += vector_[i] * other.vector_[i];
		}
		return f;
	}
	throw std::invalid_argument("invalid");
}

float Vector::getLength() const
{
	float f = 0;
	for (const auto &i : vector_) {
		f += i * i;
	}
	return std::sqrt(f);
}

Vector Vector::operator+(const Vector & other) const
{
	Vector newVector;
	if (getRows() == other.getRows()) {
		for (int i = 0; i < getRows();i++) {
			newVector.addNumber(vector_[i] + other.vector_[i]);
		}
		return newVector;
	}
	throw std::invalid_argument("invalid");
}

Vector Vector::operator-(const Vector & other) const
{
	Vector newVector;
	if (getRows() == other.getRows()) {
		for (int i = 0; i < getRows();i++) {
			newVector.addNumber(vector_[i] - other.vector_[i]);
		}
		return newVector;
	}
	throw std::invalid_argument("invalid");
}

Vector Vector::operator*(float number) const
{
	Vector newVector;
	for (int i = 0; i < getRows();i++) {
		newVector.addNumber(vector_[i] * number);
	}
	return newVector;
}

Vector Vector::subset(unsigned int from, unsigned int to) const
{
	if (from >= 0 && from <= getRows() && to >= 0 && to <= getRows()) {
		Vector v;
		for (unsigned int r = 0; r < to; r++) {
			v.addNumber(vector_[r]);
		}
		return v;
	}
	throw std::out_of_range("Out of range fuckhead");
}
