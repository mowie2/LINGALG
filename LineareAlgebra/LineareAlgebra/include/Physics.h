#pragma once

#include "Vector3f.h"
#include "Shape.h"

class Physics
{
public:
	float calculateAngle(Vector3f& vec1, Vector3f& vec2);
	float convertToRadials(float degrees);
	float convertToDegrees(float radials);
	Vector3f calculateOutProduct(Vector3f& vec1, Vector3f& vec2);
	Vector3f calculateDirectionVector(Vector3f& vec1, Vector3f& vec2);
	bool calculateIntersection(Shape& shape1, Shape& shape2);
private:
};
