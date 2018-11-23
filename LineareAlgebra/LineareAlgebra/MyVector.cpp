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

void MyVector::addNumber(float number)
{
	vector.push_back(number);
}

void MyVector::normalize()
{
	float length = getLength();
	if (length != 0) {
		for (auto &i : vector) {
			i = i / length;
		}
	}
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

float MyVector::getLength() const
{
	float f = 0;
	for (const auto &i : vector) {
		f += i * i;
	}
	return std::sqrt(f);
}

MyVector MyVector::operator+(const MyVector & other) const
{
	MyVector newVector;
	if (getRows() == other.getRows()) {
		for (int i = 0; i < getRows();i++) {
			newVector.addNumber(vector[i] + other.vector[i]);
		}
	}
	return newVector;
}

MyVector MyVector::operator-(const MyVector & other) const
{
	MyVector newVector;
	if (getRows() == other.getRows()) {
		for (int i = 0; i < getRows();i++) {
			newVector.addNumber(vector[i] - other.vector[i]);
		}
	}
	return newVector;
}

MyVector MyVector::operator*(float number) const
{
	MyVector newVector;
	for (int i = 0; i < getRows();i++) {
		newVector.addNumber(vector[i] * number);
	}
	return newVector;
}
