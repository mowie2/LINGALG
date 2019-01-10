#include "Vector3f.h"
#include <exception>
#include <stdexcept>


Vector3f::Vector3f()
{

}

Vector3f::Vector3f(float x, float y, float z)
{
	vector_ = Vector();
	vector_.addNumber(x);
	vector_.addNumber(y);
	vector_.addNumber(z);
}


Vector3f::~Vector3f()
{
}

float & Vector3f::operator[](unsigned int index)
{
	return vector_[index];
}

float Vector3f::operator[](unsigned int index) const
{
	return vector_[index];
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

Vector Vector3f::getVector() const
{
	return vector_;
}
