#include "../include/Objects.h"

std::vector<Matrix3f> Objects::cube(const Vector3f& vec)
{
	//TODO: Objectem worden niet goed gemaakt. De normaal vector staat de verkeerde kant op.
	Matrix3f square;
	square.AddVector(
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]));
	Matrix3f square2;
	square2.AddVector(
		Vector3f(0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]));
	Matrix3f square3;
	square3.AddVector(
		Vector3f(0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]));
	Matrix3f square4;
	square4.AddVector(
		Vector3f(0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]));
	Matrix3f square5;
	square5.AddVector(
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(-0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]));
	Matrix3f square6;
	square6.AddVector(
		Vector3f(0.5 + vec[0], -0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(0.5 + vec[0], 0.5 + vec[1], -0.5 + vec[2]),
		Vector3f(0.5 + vec[0], 0.5 + vec[1], 0.5 + vec[2]),
		Vector3f(0.5 + vec[0], -0.5 + vec[1], 0.5 + vec[2]));

	std::vector<Matrix3f> matrices;
	matrices.push_back(square);
	matrices.push_back(square2);
	matrices.push_back(square3);
	matrices.push_back(square4);
	matrices.push_back(square5);
	matrices.push_back(square6);
	return matrices;
}

std::vector<Matrix3f> Objects::cuboid(const Vector3f & vec)
{
	Matrix3f front;
	front.AddVector(
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]));
	Matrix3f back;
	back.AddVector(
		Vector3f(0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]));
	Matrix3f under;
	under.AddVector(
		Vector3f(0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]));
	Matrix3f up;
	up.AddVector(
		Vector3f(0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]));
	Matrix3f left;
	left.AddVector(
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(-0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]));
	Matrix3f right;
	right.AddVector(
		Vector3f(0.1 + vec[0], -0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(0.1 + vec[0], 0.1 + vec[1], -0.2 + vec[2]),
		Vector3f(0.1 + vec[0], 0.1 + vec[1], 0.2 + vec[2]),
		Vector3f(0.1 + vec[0], -0.1 + vec[1], 0.2 + vec[2]));

	std::vector<Matrix3f> matrices;
	matrices.push_back(front);
	matrices.push_back(back);
	matrices.push_back(under);
	matrices.push_back(up);
	matrices.push_back(left);
	matrices.push_back(right);
	return matrices;
}

std::vector<Matrix3f> Objects::pentagon(const Vector3f & vec)
{
	Matrix3f front;
	front.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(1, 0, 2),
		Vector3f(0, 1, 2),
		Vector3f(-1, 0, 2),
		Vector3f(-0.5, -1, 2)
	);
	Matrix3f back;
	back.AddVector(
		Vector3f(0.5, -1, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-1, 0, -2),
		Vector3f(0, 1, -2),
		Vector3f(1, 0, -2)
	);
	Matrix3f bottemRight;
	bottemRight.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(0.5, -1, -2),
		Vector3f(1, 0, -2),
		Vector3f(1, 0, 2)
	);
	Matrix3f topRight;
	topRight.AddVector(
		Vector3f(1, 0, 2),
		Vector3f(1, 0, -2),
		Vector3f(0, 1, -2),
		Vector3f(0, 1, 2)
	);
	Matrix3f topLeft;
	topLeft.AddVector(
		Vector3f(0, 1, 2),
		Vector3f(0, 1, -2),
		Vector3f(-1, 0, -2),
		Vector3f(-1, 0, 2)
	);
	Matrix3f bottemLeft;
	bottemLeft.AddVector(
		Vector3f(-1, 0, 2),
		Vector3f(-1, 0, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-0.5, -1, 2)
	);
	Matrix3f bottem;
	bottem.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(0.5, -1, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-0.5, -1, 2)
	);

	std::vector<Matrix3f> matrices;
	matrices.push_back(front);
	matrices.push_back(back);
	matrices.push_back(bottemRight);
	matrices.push_back(topRight);
	matrices.push_back(topLeft);
	matrices.push_back(topRight);
	matrices.push_back(bottem);
	return matrices;
}

std::vector<Matrix3f> Objects::louis(const Vector3f & vec)
{
	Matrix3f front;
	front.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(1, 0, 2),
		Vector3f(0, 1, 2),
		Vector3f(-1, 0, 2),
		Vector3f(-0.5, -1, 2)
	);
	Matrix3f back;
	back.AddVector(
		Vector3f(0.5, -1, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-1, 0, -2),
		Vector3f(0, 1, -2),
		Vector3f(1, 0, -2)
	);
	Matrix3f bottemRight;
	bottemRight.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(0.5, -1, -2),
		Vector3f(1, 0, -2),
		Vector3f(1, 0, 2)
	);
	Matrix3f topRight;
	topRight.AddVector(
		Vector3f(1, 0, 2),
		Vector3f(1, 0, -2),
		Vector3f(0, 1, -2),
		Vector3f(0, 1, 2)
	);
	Matrix3f topLeft;
	topLeft.AddVector(
		Vector3f(0, 1, 2),
		Vector3f(0, 1, -2),
		Vector3f(-1, 0, -2),
		Vector3f(-1, 0, 2)
	);
	Matrix3f bottemLeft;
	bottemLeft.AddVector(
		Vector3f(-1, 0, 2),
		Vector3f(-1, 0, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-0.5, -1, 2)
	);
	Matrix3f bottem;
	bottem.AddVector(
		Vector3f(0.5, -1, 2),
		Vector3f(0.5, -1, -2),
		Vector3f(-0.5, -1, -2),
		Vector3f(-0.5, -1, 2)
	);

	std::vector<Matrix3f> matrices;
	matrices.push_back(front);
	matrices.push_back(back);
	matrices.push_back(bottemRight);
	matrices.push_back(topRight);
	matrices.push_back(topLeft);
	matrices.push_back(topRight);
	matrices.push_back(bottem);
	return matrices;
}