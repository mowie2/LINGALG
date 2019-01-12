#pragma once
#include "Shape.h"
#include "Vector.h"
#include <memory>

class SpaceShip
{
private:
	Shape shape_;

public:
	SpaceShip();
	SpaceShip(const SpaceShip& other) = delete;
	SpaceShip& operator=(const SpaceShip& other) = delete;
	SpaceShip(SpaceShip&& other) = delete;
	SpaceShip& operator=(SpaceShip&& other) = delete;
	~SpaceShip();

	Shape& const shape() { return shape_; }
	void moveForward();
	/*std::unique_ptr<Shape> shoot();*/
};

