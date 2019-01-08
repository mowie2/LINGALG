#include "../include/Shape.h"



Shape::Shape(std::vector<Matrix> m)
{
	matrices_ = m;
}

void Shape::Translate(const Vector& vec)
{
	auto matrices = matrices_;
	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		it->translateThis(vec);
	}
}

void Shape::Rotate()
{
}

void Shape::Scale()
{
}

std::vector<Matrix>& Shape::matrices()
{
	return matrices_;
}

void Shape::addMatix(Matrix matrix)
{
	matrices_.push_back(matrix);
}
