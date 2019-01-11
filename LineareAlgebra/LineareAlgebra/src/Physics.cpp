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
