#pragma once
#include <vector>
class Vector
{
public:
	/*
	template <typename F, float... Fs>
	void Vector(F f) {
		if (f.getRows() == _rows) {
			matrix.push_back(std::move(f));
			_columns++;
		}
	}

	template <typename F, float... fs>
	void Vector(F f, float ... fs) {
		if (f.getRows() == _rows) {
			matrix.push_back(std::move(f));
			_columns++;
		}
		AddVector(std::forward<float>(fs)...);
	}*/

	
	Vector();



	~Vector();
	unsigned int getRows() const;
	
	void addNumber(float number);
	
	void normalize();
	float operator[](unsigned index) const;
	float& operator[](unsigned index);
	float operator*(const Vector &other) const;
	float getLength() const;
	Vector operator+(const Vector &other) const;
	Vector operator-(const Vector &other) const;
	Vector operator*(float number) const;
private:
	std::vector<float> vector;
};

