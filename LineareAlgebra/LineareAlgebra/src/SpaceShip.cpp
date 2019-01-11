#include "../include/SpaceShip.h"
#include "../include/Objects.h"


SpaceShip::SpaceShip()
{
	shape_ = Shape(Objects::cube(Vector3f{ 0,0,0 }), Vector3f{ 0,0,0 });

	//shape_.translate(Vector3f(-.5, -.5, -.5));
	//shape_.rotate(Vector3f(0, 0, 45));
	//shape_.translate(Vector3f(1, 2, 0));
}


SpaceShip::~SpaceShip()
= default;