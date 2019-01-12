#include "../include/SpaceShip.h"
#include "../include/Objects.h"


SpaceShip::SpaceShip()
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });
	shape_.heading(Vector3f(0.f, 0.f, 1.f));
	//shape_.translate(Vector3f(-.5, -.5, -.5));
	//shape_.rotate(Vector3f(0, 0, 45));
	//shape_.translate(Vector3f(1, 2, 0));

}

void SpaceShip::moveForward()
{
	shape_.translate(shape_.heading());
}

//std::unique_ptr<Shape> SpaceShip::shoot()
//{
//	auto bullet = std::make_unique<Shape>(Objects::cuboid(Vector3f{ 0,-1,2 }));
//	bullet->heading(Vector3f(0, 0, 1));
//	return bullet;
//}


SpaceShip::~SpaceShip()
= default;