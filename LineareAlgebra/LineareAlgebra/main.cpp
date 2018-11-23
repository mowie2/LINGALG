//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "Matrix.h"


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
	v2.addNumber(2);
	v2.addNumber(2);
	//m1.AddVector(v1,v2);
	m1.AddVector(v1, v2);

	Matrix m2 = Matrix(2);
	Vector v3;
	v3.addNumber(4);
	v3.addNumber(4);
	Vector v4;
	v4.addNumber(5);
	v4.addNumber(5);
	m2.AddVector(v3, v4);

	Matrix k = m1*m2;

	Window window = Window(1000,500);
	window.Draw();
	
	
	return 0;
}