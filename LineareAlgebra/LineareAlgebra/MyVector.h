#pragma once
#include <vector>
class MyVector
{
public:
	MyVector();
	~MyVector();
	unsigned int getRows() const;
	void addNumber(float number);
	void normalize();
	float operator[](unsigned index) const;
	float operator*(const MyVector &other) const;
	float getLength() const;
	MyVector operator+(const MyVector &other) const;
	MyVector operator-(const MyVector &other) const;
	MyVector operator*(float number) const;
private:
	std::vector<float> vector;
};

