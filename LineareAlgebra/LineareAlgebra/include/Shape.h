#pragma once
#include <vector>
#include "../include/Vector.h"
#include "../include/Matrix.h"

class Shape
{
public:
	Shape() = default;
	Shape(std::vector<Matrix> m);
	~Shape() = default;
	void Translate(const Vector& vec);
	void Rotate();
	void Scale();
	std::vector<Matrix>& matrices();
	void addMatix(Matrix matrix);

	Vector position;
private:
	std::vector<Matrix> matrices_;
};
