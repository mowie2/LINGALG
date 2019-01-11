#include <stdexcept>
#include "..\include\Vector3f.h"


Vector3f::Vector3f()
{
	vector_.addNumber(0.f,0.f,0.f);
}

Vector3f::Vector3f(const Vector & original)
{
	if(original.getRows() == 3)
	{
		vector_.addNumber(0.f, 0.f, 0.f);
		vector_ = Vector(original);
	}
	else{
		throw std::invalid_argument("rows must be 3");
	}
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

Vector3f & Vector3f::operator=(const Vector3f & other)
{
	if (other.vector_.getRows()) {
		vector_ = other.vector_;
	}
	return *this;
}

float & Vector3f::operator[](unsigned int index)
{
	return vector_[index];
}

float Vector3f::operator[](unsigned int index) const
{
	return vector_[index];
}

Vector3f Vector3f::operator+(const Vector3f & other) const
{
	return Vector3f(vector_[0] + other.vector_[0], vector_[1] + other.vector_[1], vector_[2] + other.vector_[2]);
}

Vector3f Vector3f::operator-(const Vector3f & other) const
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
