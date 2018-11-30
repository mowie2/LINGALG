#pragma once
#include <vector>
class Vector;
class Shape
{
public:
	Shape() = default;
	Shape(std::vector<int> m);
	~Shape() = default;
	void Translate();
	void Rotate();
	void Scale();


private:
	std::vector<int> matrices;
};
