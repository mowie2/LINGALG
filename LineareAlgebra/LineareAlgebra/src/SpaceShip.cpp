#include "../include/SpaceShip.h"



SpaceShip::SpaceShip()
{
	Matrix3f square;
	square.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 1, 0),
		Vector3f(0, 1, 0));
	Matrix3f square2;
	square2.AddVector(
		Vector3f(1, 0, 0),
		Vector3f(1, 0, 1),
		Vector3f(1, 1, 1),
		Vector3f(1, 1, 0));
	Matrix3f square3;
	square3.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(0, 0, 1),
		Vector3f(0, 1, 1),
		Vector3f(0, 1, 0));
	Matrix3f square4;
	square4.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 0, 1),
		Vector3f(0, 0, 1));
	Matrix3f square5;
	square5.AddVector(
		Vector3f(0, 1, 0),
		Vector3f(1, 1, 0),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));
	Matrix3f square6;
	square6.AddVector(
		Vector3f(0, 0, 1),
		Vector3f(1, 0, 1),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));

	std::vector<Matrix3f> matrices;
	matrices.push_back(square);
	matrices.push_back(square2);
	matrices.push_back(square3);
	matrices.push_back(square4);
	matrices.push_back(square5);
	matrices.push_back(square6);
	shape_ = Shape(matrices, Vector3f(.5, .5, .5));
}


SpaceShip::~SpaceShip()
= default;