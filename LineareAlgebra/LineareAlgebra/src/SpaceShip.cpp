#include "../include/SpaceShip.h"



SpaceShip::SpaceShip()
{
	Matrix m1;
	Vector v1;
	v1.addNumber(1.f, 1.f, 1.f);
	Vector v2;
	v2.addNumber(1.f, 2.f, 1.5f);
	Vector v3;
	v3.addNumber(2.f, 2.f, 2.f);
	Vector v4;
	v4.addNumber(2.f, 1.f, 1.5f);

	m1.AddVector(v1, v2, v3, v4);
	m1 = m1.scale(3);
	shape_.addMatix(m1);
}


SpaceShip::~SpaceShip()
{
}