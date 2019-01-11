#include "../include/Objects.h"

std::vector<Matrix3f> Objects::cube()
{
	Matrix3f square;
	square.AddVector(
		Vector3f(-0.5, -0.5, 0.5),
		Vector3f(0.5, -0.5, 0.5),
		Vector3f(0.5, 0.5, 0.5),
		Vector3f(-0.5, 0.5, 0.5));
	Matrix3f square2;
	square2.AddVector(
		Vector3f(0.5, -0.5, -0.5),
		Vector3f(-0.5, -0.5, -0.5),
		Vector3f(-0.5, 0.5, -0.5),
		Vector3f(0.5, 0.5, -0.5));
	Matrix3f square3;
	square3.AddVector(
		Vector3f(0.5, -0.5, 0.5),
		Vector3f(-0.5, -0.5, 0.5),
		Vector3f(-0.5, -0.5, -0.5),
		Vector3f(0.5, -0.5, -0.5));
	Matrix3f square4;
	square4.AddVector(
		Vector3f(0.5, 0.5, 0.5),
		Vector3f(0.5, 0.5, -0.5),
		Vector3f(-0.5, 0.5, -0.5),
		Vector3f(-0.5, 0.5, 0.5));
	Matrix3f square5;
	square5.AddVector(
		Vector3f(-0.5, -0.5, 0.5),
		Vector3f(-0.5, 0.5, 0.5),
		Vector3f(-0.5, 0.5, -0.5),
		Vector3f(-0.5, -0.5, -0.5));
	Matrix3f square6;
	square6.AddVector(
		Vector3f(0.5, -0.5, -0.5),
		Vector3f(0.5, 0.5, -0.5),
		Vector3f(0.5, 0.5, 0.5),
		Vector3f(0.5, -0.5, 0.5));

	std::vector<Matrix3f> matrices;
	matrices.push_back(square);
	matrices.push_back(square2);
	matrices.push_back(square3);
	matrices.push_back(square4);
	matrices.push_back(square5);
	matrices.push_back(square6);
	return matrices;
}
