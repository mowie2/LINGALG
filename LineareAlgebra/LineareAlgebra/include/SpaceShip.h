#pragma once
#include "Shape.h"

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

	Shape* const shape() { return &shape_; }
	void moveDown();
	void moveRight();
	void moveLeft();
	void moveUp();
};

