#pragma once
#include <vector>
#include "Matrix3f.h"
#include "Matrix4x4.h"

class Shape
{
public:
	Shape();
	Shape(std::vector<Matrix3f> m,const Vector3f& position);
	~Shape() = default;
	void translate(const Vector3f& vec);
	
	Matrix4x4f getToOrignMatrix() const;
	Matrix4x4f getToPositionMatrix() const;

	void rotate(const Vector3f& vec);
	void scale(const Vector3f& vec);

	std::vector<Matrix3f>& projections();
	std::vector<Matrix3f> projections() const;
	
	void addMatix(Matrix3f matrix);
	void setPos(const Vector3f& pos);
	void transform();
private:
	Vector3f position_;
	std::vector<Matrix3f> matrices_;
	std::vector<Matrix3f> projections_;
	Matrix4x4f transformationMatrix_;
};
