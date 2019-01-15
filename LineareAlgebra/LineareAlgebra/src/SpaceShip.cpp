#include "../include/SpaceShip.h"
#include "../include/Objects.h"



SpaceShip::SpaceShip(const Vector3f& heading)
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 }, heading);
	Matrix3f m;
	m.AddVector(Vector3f(0, 0, .5), Vector3f(0, 0, 1));
	shape_.addMatix(m);
	shape_.rotate(Vector3f(0,0 , 0));
	shape_.rotateOrigin(Vector3f(0, 45, 0));

}

void SpaceShip::moveForward()
{
	shape_.translate(shape_.heading());
}

std::unique_ptr<Shape> SpaceShip::shoot()
{
	auto bullet = std::make_unique<Shape>(Objects::cuboid(Vector3f{ 0,-1,2 }), Vector3f{ 0,-1,2 });
	bullet->heading(Vector3f(0, 0, 1));
	return bullet;
}


SpaceShip::~SpaceShip()
= default;

