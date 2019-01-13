#include "../include/SpaceShip.h"
#include "../include/Objects.h"



SpaceShip::SpaceShip(const Vector3f& heading)
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 }, heading);
	Matrix3f m;
	
	
	//shape_.translate(Vector3f(-.5, -.5, -.5));
	//shape_.rotate(Vector3f(0, 0, 45));
	//shape_.translate(Vector3f(1, 2, 0));

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

