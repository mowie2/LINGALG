#include "Vector.h"
#include <cmath>



Vector::Vector()
{
}

Vector::Vector(const int xCor, const int yCor)
	: xCor(xCor), yCor(yCor)
{
}

void Vector::setXCor(const int xCor)
{
	this->xCor = xCor;
}

void Vector::setYCor(const int yCor)
{
	this->yCor = yCor;
}

int Vector::getXCor() const
{
	return xCor;
}

int Vector::getYCor() const
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


Vector::~Vector()
{
}
