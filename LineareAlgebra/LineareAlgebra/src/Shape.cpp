#include "../include/Shape.h"

#include <cmath>
#include <SDL_stdinc.h>
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
	auto heading_2 = Vector3f(1.f, 1.f, 0.f);
	//auto heading_2 = position_;
	///step 1
	auto zx = heading_2[2] / heading_2[0];
	zx = atan(zx) / M_PI*180;
	auto step1M = Matrix4x4f::getYRotationMatrix(zx);

	auto yx = heading_2[1] / heading_2[0];
	yx = atan(yx) / M_PI * 180;
	auto step2M = Matrix4x4f::getZRotationMatrix(yx);

	auto step3M = Matrix4x4f::getXRotationMatrix(.5*M_PI);

	auto step4M = step2M;
	step4M[1][0] = step2M[1][0] * -1;
	step4M[0][1] = step2M[0][1] * -1;

	auto step5M = step1M;
	step5M[2][0] = step1M[2][0] * -1;
	step5M[0][2] = step1M[0][2] * -1;


	transformationMatrix_ = getToPositionMatrix() * (step5M * step4M * step3M *step2M *step1M) * getToOrignMatrix() * transformationMatrix_;
	transform();



	/*
	///step 1 rotateY
	heading_ = Vector3f(0.f, 5.f, 0.f);
	float tanR1 = atan(heading_[2] - heading_[0]);
	auto test = Matrix4x4f::getYRotationMatrix(tanR1);

	///alternative rotateY
	float cos = heading_[0] / 
		(sqrt(pow(heading_[0], 2) + 
			pow(heading_[2], 2)));

	float sin = heading_[2]/ 
		(sqrt(pow(heading_[0] , 2) + 
			pow(heading_[2], 2)));
	Matrix4x4f step1Matrix;
	step1Matrix[0][0] = cos;
	step1Matrix[0][2] = sin;
	step1Matrix[1][1] = 1;
	step1Matrix[2][2] = cos;
	step1Matrix[2][0] = -sin;
	step1Matrix[3][3] = 1;

	float cos2 = sqrt(pow(heading_[0], 2) + 
		pow(heading_[2], 2)) / 
		sqrt(pow(heading_[0], 2) + 
			pow(heading_[1] , 2) + 
			pow(heading_[2] , 2));
	float sin2 = heading_[1]/ 
		sqrt(pow(heading_[0], 2) + 
			pow(heading_[1] , 2) + 
			pow(heading_[2] , 2));
	Matrix4x4f step2Matrix;
	step2Matrix[0][0] = cos2;
	step2Matrix[0][1] = sin2;
	step2Matrix[1][0] = -sin2;
	step2Matrix[1][1] = cos2;
	step2Matrix[2][2] = 1;
	step2Matrix[3][3] = 1;

	Matrix4x4f step3Matrix = Matrix4x4f::getXRotationMatrix(10.f);

	Matrix4x4f step4Matrix;
	step4Matrix[0][0] = cos2;
	step4Matrix[0][1] = -sin2;
	step4Matrix[1][0] = sin2;
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
	//auto pause = 0;
	transformationMatrix_ = total;
	transform();*/
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
