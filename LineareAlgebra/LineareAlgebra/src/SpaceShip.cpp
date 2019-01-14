#include "../include/SpaceShip.h"
#include "../include/Objects.h"



SpaceShip::SpaceShip(const Vector3f& heading)
{
	shape_ = Shape(Objects::pentagon(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 }, heading);
	Matrix3f m;
}

void SpaceShip::moveForward()
{
	shape_.translate(shape_.heading());
}

std::unique_ptr<Shape> SpaceShip::shoot()
{
	auto pos = shape_.getPosition();
	auto bullet = std::make_unique<Shape>(Objects::cuboid(Vector3f{ shape_.heading()[0] + pos[0] + 0,shape_.heading()[1]+pos[1],shape_.heading()[2]+pos[0] }), Vector3f{ pos[0] + 0,pos[1] + -1,pos[0] });
	bullet->heading(Vector3f(shape_.heading()[0]*2, shape_.heading()[1]*2, shape_.heading()[2]*2));
	return bullet;
}


SpaceShip::~SpaceShip()
= default;

