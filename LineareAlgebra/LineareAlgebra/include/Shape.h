#pragma once
#include <vector>
#include "Matrix3f.h"
#include "Matrix4x4.h"

class Shape
{
public:
	Shape();
	Shape(std::vector<Matrix3f> m,const Vector3f& position,const Vector3f& heading);
	~Shape() = default;
	void translate(const Vector3f& vec);
	
	Matrix4x4f getToOrignMatrix() const;
	Matrix4x4f getToPositionMatrix() const;
	Vector3f position() const { return position_; }
	void rotate(const Vector3f& vec);
	void scale(const Vector3f& vec);
	void rotateOrigin(const Vector3f& vec,const Vector3f& point);

	std::vector<Matrix3f>& projections();
	std::vector<Matrix3f> projections() const;
	
	void addMatix(Matrix3f matrix);
	void setPos(const Vector3f& pos);
	void transform();
	//std::vector<Matrix3f> getMatrix() const { return matrices_; }
private:
	Vector3f heading_;
	Vector3f position_;
	std::vector<Matrix3f> matrices_;
	std::vector<Matrix3f> projections_;
	Matrix4x4f transformationMatrix_;
};
