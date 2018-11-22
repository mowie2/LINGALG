#include "MyVector.h"



MyVector::MyVector()
{
}


MyVector::~MyVector()
{
}

unsigned int MyVector::getRows() const
{
	return vector.size();
}

float MyVector::operator[](unsigned index) const
{
	if (index < vector.size() && index >= 0) {
		return vector[index];
	}
	return NULL;
}

float MyVector::operator*(const MyVector & other) const
{
	if (other.vector.size() == vector.size()) {
		float f = 0.0;
		for (int i = 0; i < vector.size();i++) {
			f += vector[i] * other.vector[i];
		}
		return f;
	}
	return NULL;
}
