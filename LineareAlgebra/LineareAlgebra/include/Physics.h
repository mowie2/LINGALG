#pragma once

#include "Vector3f.h"
#include "Shape.h"

class Physics
{
public:
	static float calculateAngle(Vector3f& vec1, Vector3f& vec2);
	static float convertToRadials(float degrees);
	static float convertToDegrees(float radials);
	static Vector3f calculateOutProduct(Vector3f& vec1, Vector3f& vec2);
	static Vector3f calculateDirectionVector(Vector3f& vec1, Vector3f& vec2);
	static bool calculateIntersection(Shape& shape1, Shape& shape2);
private:
};
