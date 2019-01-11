#include "../include/Shape.h"
Shape::Shape()
{
	position_ = Vector3f();
}

Shape::Shape(std::vector<Matrix3f> m,const Vector3f& position)
{
	position_ = position;
	matrices_ = m;
	projections_ = m;
	transformationMatrix_ = Matrix4x4f::getIdentityMatrix();
}

void Shape::translate(const Vector3f & vec)
{
	position_ = position_ + vec;
	Matrix4x4f translateMatrix = Matrix4x4f::getIdentityMatrix();
	translateMatrix[3][0] = vec[0];
	translateMatrix[3][1] = vec[1];
	translateMatrix[3][2] = vec[2];
	transformationMatrix_ = translateMatrix * transformationMatrix_;
	transform();
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
	transformationMatrix_ = getToPositionMatrix()*x*getToOrignMatrix()*transformationMatrix_;
	transformationMatrix_ = getToPositionMatrix()*y*getToOrignMatrix()*transformationMatrix_;
	transformationMatrix_ = getToPositionMatrix()*z*getToOrignMatrix()*transformationMatrix_;
	transform();
}

void Shape::scale(const Vector3f & vec)
{
	auto scalar = Matrix4x4f::getIdentityMatrix();
	scalar[0][0] = vec[0];
	scalar[1][1] = vec[1];
	scalar[2][2] = vec[2];
	transformationMatrix_ = getToPositionMatrix()*scalar*getToOrignMatrix()*transformationMatrix_;
	transform();
}

std::vector<Matrix3f>& Shape::projections()
{
	return projections_;
}

std::vector<Matrix3f> Shape::projections() const
{
	return projections_;
}

void Shape::addMatix(Matrix3f matrix)
{
	matrices_.push_back(matrix);
}

void Shape::setPos(const Vector3f & pos)
{
	position_ = pos;
}

void Shape::transform()
{
	for (auto i = 0;i < projections_.size();i++) {
		const auto k = (transformationMatrix_*matrices_[i].getTranslatable()).getMatrix().subSet(3, matrices_[i].getColumns());
		projections_[i] = k;
	}
}
