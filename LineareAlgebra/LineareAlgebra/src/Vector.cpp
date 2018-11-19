#include "../include/Vector.h"
#include <cmath>



Vector::Vector()
{
}

Vector::Vector(const float xCor, const float yCor)
	: xCor(xCor), yCor(yCor)
{
}

void Vector::setXCor(const float xCor)
{
	this->xCor = xCor;
}

void Vector::setYCor(const float yCor)
{
	this->yCor = yCor;
}

float Vector::getXCor() const
{
	return xCor;
}

float Vector::getYCor() const
{
	return yCor;
}

float Vector::getLength() const
{
	return sqrt(pow(this->xCor, 2) + pow(this->yCor, 2));
}

Vector Vector::normalize() const
{
	return Vector(this->xCor/this->getLength(), this->yCor/this->getLength());
}

Vector Vector::operator+(Vector const &obj) const
{
	return Vector(this->xCor + obj.getXCor(), this->yCor + obj.getYCor());
}

Vector Vector::operator-(Vector const &obj) const
{
	return Vector(this->xCor - obj.getXCor(), this->yCor - obj.getYCor());
}

Vector Vector::operator*(const int &multiplier) const
{
	return Vector(this->xCor*multiplier, this->yCor*multiplier);
}

float Vector::operator*(const Vector & otherVector) const
{
	return this->xCor*otherVector.xCor + this->yCor*otherVector.yCor;
}


Vector::~Vector()
{
}
