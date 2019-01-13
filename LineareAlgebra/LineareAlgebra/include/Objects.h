#pragma once
#include <vector>
#include "Matrix3f.h"

class Objects
{
public:
	static std::vector<Matrix3f> cube(const Vector3f& vec);
	static std::vector<Matrix3f> cuboid(const Vector3f& vec);
	static std::vector<Matrix3f> pentagon(const Vector3f& vec);
};

