#pragma once
#include <vector>
#include "Matrix3f.h"
/// <summary>
/// Contains Shapes
/// </summary>
class Objects
{
public:
	/// <summary>
	/// Returns a Matrix3f in the shape of a cube.
	/// </summary>
	static std::vector<Matrix3f> cube(const Vector3f& vec);
};

