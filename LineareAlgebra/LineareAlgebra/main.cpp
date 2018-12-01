//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "../LineareAlgebra/include/Matrix.h"


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
	v1.addNumber(1);
	v1.addNumber(1);
	Vector v2;
	v2.addNumber(1);
	v2.addNumber(2);
	Vector v3;
	v3.addNumber(2);
	v3.addNumber(2);
	Vector v4;
	v4.addNumber(2);
	v4.addNumber(1);

	
	m1.AddVector(v1,v2,v3,v4);
	
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

	Window window = Window(1000,500);
	window.Draw(k);
	window.Draw(m2);
	return 0;
}