#pragma once
#include <vector>
class Vector
{
public:
	Vector();
	~Vector();
	unsigned int getRows() const;
	void addNumber(float number);
	void normalize();
	float operator[](unsigned index) const;
	float operator*(const Vector &other) const;
	float getLength() const;
	Vector operator+(const Vector &other) const;
	Vector operator-(const Vector &other) const;
	Vector operator*(float number) const;
private:
	std::vector<float> vector;
};

