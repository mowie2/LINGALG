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
	Matrix m1 = Matrix(2);
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
	m1[3][0] = 5;
	
	Matrix m2 = Matrix(4);
	Vector v5;
	v5.addNumber(1);
	v5.addNumber(0);
	v5.addNumber(0);
	v5.addNumber(0);

	Vector v6;
	v6.addNumber(0);
	v6.addNumber(1);
	v6.addNumber(0);
	v6.addNumber(0);

	m2.AddVector(v5, v6);


	Matrix k = m1*m2;
	
	Window window = Window(1000,500);
	window.Draw(m1);	
	return 0;
}