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
	Matrix m = Matrix(2);
	m.AddVector(Vector(1, 1));
	m.AddVector(Vector(2, 2));
	m.AddVector(Vector(3, 3));
	m.AddVector(Vector(4, 4));



	Window window = Window(1000,500);
	window.Draw();
	
	
	return 0;
}