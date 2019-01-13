#pragma once

#include "Vector3f.h"
#include "Shape.h"

class Physics
{
public:
	/// <summary>
	/// Calculates the angle between 2 Vector3f's.
	/// </summary>
	static float calculateAngle(Vector3f& vec1, Vector3f& vec2);
	/// <summary>
	/// Returns a float wich has been converted to radials.
	/// </summary>
	static float convertToRadials(float degrees);
	/// <summary>
	/// Returns a float wich has been converted to degrees.
	/// </summary>
	static float convertToDegrees(float radials);
	/// <summary>
	/// Returns the crossProduct. 
	/// </summary>
	static Vector3f calculateOutProduct(Vector3f& vec1, Vector3f& vec2);
	/// <summary>
	/// Returns a direction Vector3f between two Vector3f's. 
	/// </summary>
	static Vector3f calculateDirectionVector(Vector3f& vec1, Vector3f& vec2);
	/// <summary>
	/// Checks if a collision has happend between two Shapes. 
	/// </summary>
	static bool calculateIntersection(Shape& shape1, Shape& shape2);
private:
};
