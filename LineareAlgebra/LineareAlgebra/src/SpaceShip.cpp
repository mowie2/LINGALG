#include "../include/SpaceShip.h"
#include "../include/Objects.h"



SpaceShip::SpaceShip(const Vector3f& heading) : heading_(heading)
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 }, Vector3f(0.f, 0.f, 1.f));
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

void SpaceShip::rotate(const Vector3f & vec)
{
	shape_.rotateOrigin(vec);
	//auto h2t = heading_.getVector();
	//h2t.addNumber(1);
	//heading_ = ((Matrix4x4f::getXRotationMatrix(vec[0])*Matrix4x4f::getYRotationMatrix(vec[1])*Matrix4x4f::getZRotationMatrix(vec[2])).getMatrix()*h2t).subset(0,3);
	//heading_.normalize();
}
