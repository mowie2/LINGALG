#pragma once
#include <vector>
#include "../include/Vector.h"
#include "../include/Matrix.h"
#include "Matrix3f.h"
#include "Matrix4x4.h"

class Shape
{
public:
	Shape() = default;
	Shape(std::vector<Matrix> m);
	Shape(std::vector<Matrix3f> m,const Vector3f& position);
	~Shape() = default;
	void Translate(const Vector& vec);
	
	void translate(const Vector3f& vec);
	
	void Rotate(const Vector& vector);

	Matrix4x4f getToOrignMatrix() const;
	Matrix4x4f getToPositionMatrix() const;

	void rotate(const Vector3f& vec);
	void scale(const Vector3f& vec);

	void Scale();
	std::vector<Matrix>& matrices();
	std::vector<Matrix3f>& projections();
	void addMatix(Matrix matrix);
	void setPos(const Vector& pos);
	Vector position;
private:
	Vector3f position_;
	std::vector<Matrix> matrices_;
	std::vector<Matrix3f> matrices3D_;
	std::vector<Matrix3f> projections_;
	Matrix4x4f transformationMatrix_;
};
