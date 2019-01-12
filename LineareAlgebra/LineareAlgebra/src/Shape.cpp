#include "../include/Shape.h"

#include <cmath>
#include <SDL_stdinc.h>
Shape::Shape()
{
	position_ = Vector3f();
}

Shape::Shape(std::vector<Matrix3f> m,const Vector3f& position, const Vector3f& heading)
{
	position_ = position;
	matrices_ = m;
	projections_ = m;
	transformationMatrix_ = Matrix4x4f::getIdentityMatrix();
	heading_ = heading;
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
	auto heading_2 = Vector3f(0,0,1);
	//auto heading_2 = position_;
	///step 1
	float zx = 90;
	if (heading_2[0] != 0) {
		zx = heading_2[2] / heading_2[0];
		zx = atan(zx) / M_PI * 180;
	}
	auto step1M = Matrix4x4f::getYRotationMatrix(zx);

	///step2
	float yx = 90;
	if (heading_2[0] != 0) {
		yx = heading_2[1] / heading_2[0];
		yx = atan(yx) / M_PI * 180;
	}
	if(heading_2[1] == 0)
	{
		yx = 0;
	}
	auto step2M = Matrix4x4f::getZRotationMatrix(yx);

	///step3
	///everything is now on axis x;
	auto step3M = Matrix4x4f::getZRotationMatrix(vec[0]);
	step3M = Matrix4x4f::getYRotationMatrix(vec[1]) * step3M;
	step3M = Matrix4x4f::getXRotationMatrix(vec[2]) * step3M;

	///step4
	auto step4M = step2M;
	step4M[1][0] = step2M[1][0] * -1;
	step4M[0][1] = step2M[0][1] * -1;

	///step5
	auto step5M = step1M;
	step5M[2][0] = step1M[2][0] * -1;
	step5M[0][2] = step1M[0][2] * -1;

	auto rotation = (step5M * step4M * step3M *step2M *step1M);
	transformationMatrix_ = getToPositionMatrix() * rotation * getToOrignMatrix() * transformationMatrix_;
	
	auto h2t = heading_2.getVector();
	h2t.addNumber(1);
	//heading_ = (step3M.getMatrix()*h2t).subset(0,3);
	//heading_.normalize();
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
		const auto k = (transformationMatrix_*matrices_[i].getTranslatable()).subSet(3, matrices_[i].getColumns());
		projections_[i] = k;
	}
}
