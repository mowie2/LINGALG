#include "../include/Shape.h"

#include <cmath>
#include <SDL_stdinc.h>
#include <iostream>

Shape::Shape()
{
	position_ = Vector3f();
	scaleVector_ = Vector3f(1, 1, 1);
}

Shape::Shape(std::vector<Matrix3f> m, const Vector3f& position)
{
	position_ = position;
	matrices_ = m;
	//projections_ = m;
	//transformationMatrix_ = Matrix4x4f::getIdentityMatrix();
	scaleVector_ = Vector3f(1, 1, 1);
}

Shape::Shape(std::vector<Matrix3f> m, const Vector3f& position, const Vector3f& heading)
{
	position_ = position;
	matrices_ = m;
	//projections_ = m;
	//transformationMatrix_ = Matrix4x4f::getIdentityMatrix();
	heading_ = heading;
	scaleVector_ = Vector3f(1, 1, 1);
}

void Shape::newScale(Vector3f vec)
{
	scaleVector_ = vec;
}

Matrix4x4f Shape::getTransformationMatrix() const
{
	auto scaler = Matrix4x4f::getIdentityMatrix();
	scaler[0][0] = scaleVector_[0];
	scaler[1][1] = scaleVector_[1];
	scaler[2][2] = scaleVector_[2];

	return getToPositionMatrix()*scaler*getToOrignMatrix();
}

void Shape::translate(const Vector3f & vec)
{
	//TODO: dit moet zo anders gescherven worden.
	position_ = position_ + vec;
	//heading_ = heading_ + vec;
	Matrix4x4f translateMatrix = Matrix4x4f::getIdentityMatrix();
	translateMatrix[3][0] = vec[0];
	translateMatrix[3][1] = vec[1];
	translateMatrix[3][2] = vec[2];
	//transformationMatrix_ = translateMatrix * transformationMatrix_;
	//transform();
}

Matrix4x4f Shape::getToOrignMatrix() const
{
	auto m = Matrix4x4f::getIdentityMatrix();
	m[3][0] = -1 * position_[0];
	m[3][1] = -1 * position_[1];
	m[3][2] = -1 * position_[2];
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
	auto v = heading_.getVector();
	v.addNumber(1);
	heading_ = ((x * y * z).getMatrix() * v).subset(0, 3);
	//transformationMatrix_ = getToPositionMatrix()*x*y*z*getToOrignMatrix()*transformationMatrix_;
	//transform();
}

void Shape::scale(const Vector3f & vec)
{
	auto scalar = Matrix4x4f::getIdentityMatrix();
	scalar[0][0] = vec[0];
	scalar[1][1] = vec[1];
	scalar[2][2] = vec[2];


	//transformationMatrix_ = getToPositionMatrix()*scalar*getToOrignMatrix()*transformationMatrix_;
	//transform();
}

void Shape::rotateAround(Shape const & object, Vector3f const & vec)
{
	//transformationMatrix_ = get7RotationMatrix(object, vec);
	//();
}

void Shape::barrelrol(float degrees)
{
	auto x = heading_[0];
	auto y = heading_[1];
	auto z = heading_[2];
	///step 1
	float zx = 90;
	if (x != 0) {
		zx = z / x;
		zx = atan(zx) / M_PI * 180;
	}
	auto step1M = Matrix4x4f::getYRotationMatrix(zx);

	///step2
	float yx = 0;
	auto a = std::sqrt(x * x + z * z);
	auto b = std::sqrt(x * x + y * y + z * z);
	if (b != 0) {
		yx = -1 * a / b;
		yx = acos(yx) / M_PI * 180;
	}
	auto step2M = Matrix4x4f::getZRotationMatrix(yx);

	///step3
	///everything is now on axis x;
	auto step3M = Matrix4x4f::getXRotationMatrix(degrees);

	///step4
	auto step4M = step2M;
	step4M[1][0] = step2M[1][0] * -1;
	step4M[0][1] = step2M[0][1] * -1;

	///step5
	auto step5M = step1M;
	step5M[2][0] = step1M[2][0] * -1;
	step5M[0][2] = step1M[0][2] * -1;

	auto rotation = (step5M*step4M*step3M*step2M*step1M);
	//TODO: 
	//transformationMatrix_ = this->getToPositionMatrix() * rotation * this->getToOrignMatrix() * transformationMatrix_;
	//transform();
}

Matrix4x4f const Shape::get7RotationMatrix(Shape const & object, Vector3f const & vec)
{
	//auto heading_2 = position_;
	auto heading_2 = heading_;
	auto x = heading_[0];
	auto y = heading_[1];
	auto z = heading_[2];
	///step 1
	float zx = 90;
	if (x != 0) {
		zx = z / x;
		zx = atan(zx) / M_PI * 180;
	}
	auto step1M = Matrix4x4f::getYRotationMatrix(zx);

	///step2
	float yx = 0;
	auto a = std::sqrt(x * x + z * z);
	auto b = std::sqrt(x * x + y * y + z * z);
	if (b != 0) {
		yx = -1 * a / b;
		yx = acos(yx) / M_PI * 180;
	}
	auto step2M = Matrix4x4f::getZRotationMatrix(yx);

	///step3
	///everything is now on axis x;
	//auto mX = Matrix4x4f::getXRotationMatrix(vec[0]);
	//auto mY = Matrix4x4f::getYRotationMatrix(vec[1]);
	//auto mZ = Matrix4x4f::getZRotationMatrix(vec[2]);
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

	auto rotation = (step5M*step4M*step3M*step2M*step1M);
	//transformationMatrix_ = getToPositionMatrix() * rotation * getToOrignMatrix() * transformationMatrix_;
	auto ht2 = heading_.getVector();
	ht2.addNumber(1);
	std::cout << "LOOK AT ME\n";
	std::cout << zx << " " << yx << '\n';
	//heading_ = ((getToPositionMatrix() * rotation * getToOrignMatrix()).getMatrix() * ht2).subset(0, 3);
	//heading_.normalize();


	auto returnMatrix = object.getToPositionMatrix() * rotation * object.getToOrignMatrix() /* *transformationMatrix_*/;
	return returnMatrix;
}

void Shape::rotateOrigin(const Vector3f & vec)
{
	//TODO:
	//transformationMatrix_ = get7RotationMatrix(*this, vec);
	//transform();
}

//std::vector<Matrix3f>& Shape::projections()
//{
//	transform();
//	return projections_;
//}

//std::vector<Matrix3f> Shape::projections() const
//{
//	return projections_;
//}

std::vector<Matrix3f> Shape::projections() const
{
	std::vector<Matrix3f> list;
	auto transformationMatrix = getTransformationMatrix();
	for (auto& m : matrices_)
	{
		list.emplace_back((transformationMatrix.getMatrix() * m.getTranslatable()).subSet(3,m.getColumns()));
	}
	return list;
}

void Shape::addMatix(Matrix3f matrix)
{
	matrices_.push_back(matrix);
	//TODO:
	//projections_.push_back(matrix);
}

void Shape::setPos(const Vector3f & pos)
{
	position_ = pos;
}

void Shape::pulseSize(float dt, float speed, float size)
{
	sinValue += dt * speed;

	Vector3f pulsVec = Vector3f(sin(sinValue) / (100 * size) + 1, sin(sinValue) / (100 * size) + 1, sin(sinValue) / (100 * size) + 1);
	this->scale(pulsVec);
}

void Shape::moveForward(float dt)
{
	if (heading_[0] == 0 && heading_[1] == 0 && heading_[2] == 0)
		return;
	translate(Vector3f(heading_[0] * dt, heading_[1] * dt, heading_[2] * dt));
}

//void Shape::transform()
//{
//	//auto v = heading_.getVector();
//	//v.addNumber(1);
//	//heading_ = (transformationMatrix_.getMatrix() * v).subset(0,3);
//	for (auto i = 0; i < projections_.size(); i++) {
//		const auto k = (transformationMatrix_*matrices_[i].getTranslatable()).subSet(3, matrices_[i].getColumns());
//		projections_[i] = k;
//	}
//}

Vector3f& Shape::heading()
{
	return heading_;
}

void Shape::heading(Vector3f newHeading)
{
	heading_ = newHeading;
}
