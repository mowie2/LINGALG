#include "../include/Shape.h"



Shape::Shape(std::vector<Matrix> m)
{
	matrices_ = m;
}

void Shape::Translate(const Vector& vec)
{

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
