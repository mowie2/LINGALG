#pragma once
#include "Shape.h"
#include "Vector.h"
#include <memory>

class SpaceShip
{
private:
	Shape shape_;
	Vector3f heading_;
public:
	SpaceShip(const Vector3f& heading);
	SpaceShip(const SpaceShip& other) = delete;
	SpaceShip& operator=(const SpaceShip& other) = delete;
	SpaceShip(SpaceShip&& other) = delete;
	SpaceShip& operator=(SpaceShip&& other) = delete;
	~SpaceShip();
	Vector3f heading() const { return heading_; }
	void rotate(const Vector3f& vec);
	Shape& const shape() { return shape_; }
	void moveForward();
	std::unique_ptr<Shape> shoot();
};

