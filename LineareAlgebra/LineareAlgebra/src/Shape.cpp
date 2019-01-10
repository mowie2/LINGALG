#include "../include/Shape.h"
Shape::Shape()
#include <cmath>
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
	transformationMatrix_ = getToPositionMatrix()*x*y*z*getToOrignMatrix()*transformationMatrix_;
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

void Shape::rotateOrigin(const Vector3f & vec)
{
	///step 1 rotateY
	heading_ = Vector3f(5.f, 5.f, 5.f);
	float tanR1 = atan(heading_[2] - position_[2]);
	Matrix4x4f::getYRotationMatrix(tanR1);

	///alternative rotateY
	float cos = position_[0] / (sqrt(pow(heading_[0] - position_[0], 2) + pow(heading_[2] - position_[2], 2)));
	float sin = position_[2] / (sqrt(pow(heading_[0] - position_[0], 2) + pow(heading_[2] - position_[2], 2)));
	Matrix4x4f step1Matrix;
	step1Matrix[0][0] = cos;
	step1Matrix[0][2] = sin;
	step1Matrix[1][1] = 1;
	step1Matrix[2][2] = cos;
	step1Matrix[2][0] = -sin;
	step1Matrix[3][3] = 1;

	float cos2 = sqrt(pow(heading_[0] - position_[0], 2) + pow(heading_[2] - position_[2], 2)) / sqrt(pow(heading_[0] - position_[0], 2) + pow(heading_[1] - position_[1], 2) + pow(heading_[2] - position_[2], 2));
	float sin2 = heading_[1]-position_[1] / sqrt(pow(heading_[0] - position_[0], 2) + pow(heading_[1] - position_[1], 2) + pow(heading_[2] - position_[2], 2));
	Matrix4x4f step2Matrix;
	step2Matrix[0][0] = cos2;
	step2Matrix[0][1] = -sin2;
	step2Matrix[1][0] = sin2;
	step2Matrix[1][1] = cos2;
	step2Matrix[2][2] = 1;
	step2Matrix[3][3] = 1;

	Matrix4x4f step3Matrix = Matrix4x4f::getXRotationMatrix(10);

	Matrix4x4f step4Matrix;
	step4Matrix[0][0] = cos2;
	step4Matrix[0][1] = sin2;
	step4Matrix[1][0] = -sin2;
	step4Matrix[1][1] = cos2;
	step4Matrix[2][2] = 1;
	step4Matrix[3][3] = 1;


	Matrix4x4f step5Matrix;
	step5Matrix[0][0] = cos;
	step5Matrix[0][2] = -sin;
	step5Matrix[1][1] = 1;
	step5Matrix[2][2] = cos;
	step5Matrix[2][0] = sin;
	step5Matrix[3][3] = 1;

	Matrix4x4f total = (step5Matrix * step4Matrix*step3Matrix*step2Matrix*step1Matrix)*transformationMatrix_;
	auto pause = 0;
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
