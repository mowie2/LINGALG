#pragma once
#include <vector>
#include "Matrix3f.h"
#include "Matrix4x4.h"

class Shape
{
public:
	Shape();
	Shape(std::vector<Matrix3f> m, const Vector3f& position);
	Shape(std::vector<Matrix3f> m,const Vector3f& position,const Vector3f& heading);
	void newScale(Vector3f vec);
	Matrix4x4f getTransformationMatrix();
	~Shape() = default;
	void translate(const Vector3f& vec);

	Matrix4x4f getToOrignMatrix() const;
	Matrix4x4f getToPositionMatrix() const;
	Vector3f position() const { return position_; }
	void rotate(const Vector3f& vec);
	void rotateAround(Shape const & object, Vector3f const & vec);
	void barrelrol(float degrees);
	void scale(const Vector3f& vec);
	void rotateOrigin(const Vector3f& vec);
	std::vector<Matrix3f> projections();
	//void transform();

	//std::vector<Matrix3f>& projections();
	//std::vector<Matrix3f> projections() const;
	std::vector<Matrix3f> newGetProjections() const;
	Vector3f heading() const { return heading_; }

	void addMatix(Matrix3f matrix);
	void setPos(const Vector3f& pos);
	std::vector<Matrix3f> getMatrix() const { return matrices_; }

	void pulseSize(float dt, float speed, float size);
	void moveForward(float dt);

	Vector3f& heading();
	void heading(Vector3f newHeading);
	Vector3f getPosition() const { return position_; }
private:
	Vector3f heading_;
	Vector3f position_;
	std::vector<Matrix3f> matrices_;
	//std::vector<Matrix3f> projections_;
	//Matrix4x4f transformationMatrix_;
	Vector3f translationVector_;


	Matrix4x4f const get7RotationMatrix(Shape const & object, Vector3f const & vec);
	float sinValue = 0;
	Vector3f scaleVector_;
};
