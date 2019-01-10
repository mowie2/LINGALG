#include "../include/Shape.h"



Shape::Shape(std::vector<Matrix> m)
{
	matrices_ = m;
}

Shape::Shape(std::vector<Matrix3f> m,const Vector3f& position)
{
	position_ = position;
	matrices3D_ = m;
	projections_ = m;
	transformationMatrix_ = Matrix4x4f::getIdentityMatrix();
	translate(position);
}

void Shape::Translate(const Vector& vec)
{
	auto matrices = matrices_;
	for (auto it = matrices_.begin(); it != matrices_.end(); it++)
	{
		it->translateThis(vec);
	}
}

void Shape::translate(const Vector3f & vec)
{
	position_ = position_ + vec;
	Matrix4x4f translateMatrix = Matrix4x4f::getIdentityMatrix();
	translateMatrix[3][0] = vec[0];
	translateMatrix[3][1] = vec[1];
	translateMatrix[3][2] = vec[2];
	transformationMatrix_ = translateMatrix * transformationMatrix_;
	
	for (unsigned int i = 0;i < projections_.size();i++) {
		projections_[i] = (transformationMatrix_*matrices3D_[i].getTranslatable()).getMatrix().subSet(3,matrices3D_[i].getColumns());
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

Matrix4x4f Shape::getToOrignMatrix() const
{
	auto m = Matrix4x4f::getIdentityMatrix();
	m[3][0] = -1*position_[0];
	m[3][1] = -1*position_[1];
	m[3][2] = -1*position_[2];
	return m;
}

Matrix4x4f Shape::getToPositionMatrix() const
{
	auto m = Matrix4x4f::getIdentityMatrix();
	m[3][0] = position_[0];
	m[3][1] = position_[1];
	m[3][2] = position_[2];
	return m;
}

void Shape::rotate(const Vector3f & vec)
{
	const auto x = Matrix4x4f::getXRotationMatrix(vec[0]);
	const auto y = Matrix4x4f::getYRotationMatrix(vec[1]);
	const auto z = Matrix4x4f::getZRotationMatrix(vec[2]);
	transformationMatrix_ = getToPositionMatrix()*x*y*z*getToOrignMatrix()*transformationMatrix_;

	for (unsigned int i = 0;i < projections_.size();i++) {
		projections_[i] = (transformationMatrix_*matrices3D_[i].getTranslatable()).getMatrix().subSet(3, matrices3D_[i].getColumns());
	}
}

void Shape::Scale()
{
}

std::vector<Matrix>& Shape::matrices()
{
	return matrices_;
}

std::vector<Matrix3f>& Shape::projections()
{
	return projections_;
}

void Shape::addMatix(Matrix matrix)
{
	matrices_.push_back(matrix);
}

void Shape::setPos(const Vector & pos)
{
	position = pos;
}
