#include "../include/SpaceShip.h"
#include "../include/Objects.h"



SpaceShip::SpaceShip(const Vector3f& heading)
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 }, heading);
	Matrix3f m;
}

void SpaceShip::moveForward()
{
	shape_.translate(shape_.heading());
}

std::unique_ptr<Shape> SpaceShip::shoot()
{
	auto pos = shape_.getPosition();
	auto bullet = std::make_unique<Shape>(Objects::cuboid(Vector3f{ pos[0] + 0,pos[1] + -1,pos[0] + 2 }), Vector3f{ pos[0] + 0,pos[1] + -1,pos[0] + 2 });
	bullet->heading(Vector3f(0, 0, 1));
	return bullet;
}


SpaceShip::~SpaceShip()
= default;

