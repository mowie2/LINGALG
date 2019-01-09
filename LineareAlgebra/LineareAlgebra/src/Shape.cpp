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

void Shape::Rotate(const Vector& vector)
{
	/*Vector toOrigin;
	toOrigin.addNumber(0.f, 0.f, 0.f);
	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		toOrigin = toOrigin + it->getToOrginVector();
	}
	toOrigin * (1 / matrices_.size());
	auto returnV = toOrigin * -1;*/

	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		*it = (Matrix::getRotateXMatrix3d(vector[0])* it->translate(position).getTranslatable()).subSet(it->getRows(), it->getColumns()).translate(position*-1);
	}
	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		*it = (Matrix::getRotateYMatrix3d(vector[1])* it->translate(position).getTranslatable()).subSet(it->getRows(), it->getColumns()).translate(position*-1);
	}
	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		*it = (Matrix::getRotateZMatrix3d(vector[2])* it->translate(position).getTranslatable()).subSet(it->getRows(), it->getColumns()).translate(position*-1);
	}

	//auto toOrgin = (m1.getToOrginVector() + m2.getToOrginVector()) * .5f;
	//auto returnV = toOrgin * -1;
	//
	//m1 = (Matrix::getRotateYMatrix3d(45)* m1.translate(toOrgin).getTranslatable()).subSet(m1.getRows(), m1.getColumns()).translate(returnV);
	//m2 = (Matrix::getRotateYMatrix3d(45)* m2.translate(toOrgin).getTranslatable()).subSet(m2.getRows(), m2.getColumns()).translate(returnV);
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

void Shape::setPos(const Vector & pos)
{
	position = pos;
}
