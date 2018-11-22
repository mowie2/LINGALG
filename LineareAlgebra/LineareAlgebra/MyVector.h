#pragma once
#include <vector>
class MyVector
{
public:
	MyVector();
	~MyVector();
	unsigned int getRows() const;
	void addNumber(float)
	float operator[](unsigned index) const;
	float operator*(const MyVector &other) const;
	MyVector operator+(const MyVector &other) const;
	MyVector operator-(const MyVector &other) const;
private:
	std::vector<float> vector;
};

