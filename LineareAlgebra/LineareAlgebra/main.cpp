//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "../LineareAlgebra/include/Matrix.h"
#include <vector>


#ifdef main
#undef main
#endif /* main */

//Screen dimension constants
const int SCREEN_WIDTH = 1;
const int SCREEN_HEIGHT = 1;

int main(int argc, char* args[])
{
	Matrix m1;
	Vector v1;
	v1.addNumber(1.f, 1.f);
	Vector v2;
	v2.addNumber(1.f, 2.f);
	Vector v3;
	v3.addNumber(2.f, 2.f);
	Vector v4;
	v4.addNumber(2.f, 1.f);
	
	m1.AddVector(v1,v2,v3,v4);
	std::vector<Matrix> vectorMatrix;
	vectorMatrix.push_back(m1);

	//m1[3][0] = 5;
	
	Matrix m2;
	m2.AddVector(v1, v2, v3, v4);

	Vector v;
	v.addNumber(-1);
	v.addNumber(-1);
	//Matrix k1 = Matrix(2, 2, true);
	//Matrix k = m1.translateToOrgin();
	//Vector r = m1.getToOrginVector() * -1;
	//Matrix k = (k1 * 1 * m1.translateToOrgin()).translate(r);
	Matrix k = m1.scale(5);

	m2.AddVector(v5, v6);


	Matrix k = m1*m2;
	vectorMatrix.push_back(m2);
	vectorMatrix.push_back(k);

	Shape shape(vectorMatrix);
	
	Window window = Window(1000,500);
	window.addToDraw(shape);
	window.render();
	return 0;
}