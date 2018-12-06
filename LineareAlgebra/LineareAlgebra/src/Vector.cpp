#include "../include/Vector.h"
#include <cmath>


Vector::Vector()
{
}


Vector::~Vector()
{
}

unsigned int Vector::getRows() const
{
	return vector.size();
}

void Vector::addNumber(float number)
{
	vector.push_back(number);
}

void Vector::normalize()
{
	float length = getLength();
	if (length != 0) {
		for (auto &i : vector) {
			i = i / length;
		}
	}
}

float Vector::operator[](unsigned index) const
{
	if (index < vector.size() && index >= 0) {
		return vector[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

float & Vector::operator[](unsigned index)
{
	if (index < vector.size() && index >= 0) {
		return vector[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

float Vector::operator*(const Vector & other) const
{
	if (other.vector.size() == vector.size()) {
		float f = 0.0;
		for (int i = 0; i < vector.size();i++) {
			f += vector[i] * other.vector[i];
		}
		return f;
	}
	throw std::invalid_argument("invalid");
}

float Vector::getLength() const
{
	float f = 0;
	for (const auto &i : vector) {
		f += i * i;
	}
	return std::sqrt(f);
}

Vector Vector::operator+(const Vector & other) const
{
	Vector newVector;
	if (getRows() == other.getRows()) {
		for (int i = 0; i < getRows();i++) {
			newVector.addNumber(vector[i] + other.vector[i]);
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
			newVector.addNumber(vector[i] - other.vector[i]);
		}
		return newVector;
	}
	throw std::invalid_argument("invalid");
}

Vector Vector::operator*(float number) const
{
	Vector newVector;
	for (int i = 0; i < getRows();i++) {
		newVector.addNumber(vector[i] * number);
	}
	return newVector;
}
