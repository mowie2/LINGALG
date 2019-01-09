#include "Vector3f.h"
#include <exception>
#include <stdexcept>


Vector3f::Vector3f()
{

}

Vector3f::Vector3f(float x, float y, float z)
{
	vector_[0] = x;
	vector_[1] = y;
	vector_[2] = z;
}


Vector3f::~Vector3f()
{
}

float & Vector3f::operator[](unsigned int index)
{
	if (index < vector_.size() && index >= 0) {
		return vector_[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

float Vector3f::operator[](unsigned int index) const
{
	if (index < vector_.size() && index >= 0) {
		return vector_[index];
	}
	throw std::out_of_range("Out of range fuckhead");
}

Vector3f Vector3f::operator+(const Vector3f & other)
{
	return Vector3f(vector_[0] + other.vector_[0], vector_[1] + other.vector_[1], vector_[2] + other.vector_[2]);
}

Vector3f Vector3f::operator-(const Vector3f & other)
{
	return Vector3f(vector_[0] - other.vector_[0], vector_[1] - other.vector_[1], vector_[2] - other.vector_[2]);
}

float Vector3f::operator*(const Vector3f & other)
{
	return vector_[0] * other.vector_[0] + vector_[1] * other.vector_[1] + vector_[2] * other.vector_[2];
}
