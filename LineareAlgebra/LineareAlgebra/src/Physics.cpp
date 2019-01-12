#include "../include/Physics.h"
#include <math.h>
#include <SDL_stdinc.h>


float Physics::calculateAngle(Vector3f& vec1, Vector3f& vec2)
{
	if (vec1.getVector().getLength() == 0 || vec2.getVector().getLength() == 0)
	{
		//TODO: niet zo een hele mooie oplossing. Iets anders bedenken misschien?
		return -1;
	}
	const float x = vec1 * vec2;
	float y =
		((vec1[0] * vec1[0]) +
		(vec1[1] * vec1[1]) +
			(vec1[2] * vec1[2]))*


			((vec2[0] * vec2[0]) +
		(vec2[1] * vec2[1]) +
				(vec2[2] * vec2[2]))
		;
	return convertToDegrees(acos((x / sqrt(y))));

}

float Physics::convertToRadials(float degrees)
{
	return degrees / 180 * M_PI;
}

float Physics::convertToDegrees(float radials)
{
	return radials / M_PI * 180;
}

Vector3f Physics::calculateOutProduct(Vector3f& vec1, Vector3f& vec2)
{
	Vector3f newVec = Vector3f();

	newVec[0] = (vec1[1] * vec2[2] - vec1[2] * vec2[1]);
	newVec[1] = (vec1[2] * vec2[0] - vec1[0] * vec2[2]);
	newVec[2] = (vec1[0] * vec2[1] - vec1[1] * vec2[0]);

	return newVec;
}

Vector3f Physics::calculateDirectionVector(Vector3f& vec1, Vector3f& vec2)
{
	Vector3f newVec;
	newVec = vec1 - vec2;
	return  newVec;
}

bool Physics::calculateIntersection(Shape& shape1, Shape& shape2)
{
	float minx = shape1.getMatrix()[0][0][0];
	float maxx = shape1.getMatrix()[0][0][0];

	float miny = shape1.getMatrix()[0][0][1];
	float maxy = shape1.getMatrix()[0][0][1];

	float minz = shape1.getMatrix()[0][0][2];
	float maxz = shape1.getMatrix()[0][0][2];

	bool x = false;
	bool y = false;
	bool z = false;
	for (auto& p1 : shape1.getMatrix())
	{
		for (unsigned int i = 0; i < p1.getColumns(); i++)
		{
			auto vec = p1[i];
			if (vec[0] < minx)
			{
				minx = vec[0];
			}
			if (vec[0] > maxx)
			{
				maxx = vec[0];
			}

			if (vec[1] < miny)
			{
				miny = vec[1];
			}
			if (vec[1] > maxy)
			{
				maxy = vec[1];
			}

			if (vec[2] < minz)
			{
				minz = vec[2];
			}
			if (vec[2] > maxz)
			{
				maxz = vec[2];
			}

		}
	}
	for (auto& p2 : shape2.getMatrix())
	{
		for (unsigned int i = 0; i < p2.getColumns(); i++)
		{
			auto vec = p2[i];

			if (vec[0] >= minx && vec[0] <= maxx)
			{
				x = true;
			}
			if (vec[1] >= miny && vec[1] <= maxy)
			{
				y = true;
			}
			if (vec[2] >= minz && vec[2] <= maxz)
			{
				z = true;
			}
		}
	}

	if (x && y && z)
	{
		return  true;
	}

	if(calculateIntersection(shape2, shape1))
	{
		return true;
	}
	return false;
}
