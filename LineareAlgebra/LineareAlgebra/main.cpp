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
	
	//Matrix kk(3,3);
	//Vector kkk;
	//kkk.addNumber(0.f, 0.f,1.f);
	//kk[0] = kkk;
	//Matrix3f k(4);
	//auto& kk = k.getMatrix();
	//m1[3][0] = 5;
	
	//Matrix m2;
	//m2.AddVector(v1, v2, v3, v4);

	Vector v;
	v.addNumber(-1);
	v.addNumber(-1);
	//Matrix k1 = Matrix(2, 2, true);
	//Matrix k = m1.translateToOrgin();
	//Vector r = m1.getToOrginVector() * -1;
	//Matrix k = (k1 * 1 * m1.translateToOrgin()).translate(r);
	//Matrix k = m1.scale(5);

	//vectorMatrix.push_back(m2);
	//vectorMatrix.push_back(k);

	//Shape shape(vectorMatrix);
	
	Window window = Window(1000,500);
	Matrix3f square;
	square.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 1, 0),
		Vector3f(0, 1, 0));
	Matrix3f square2;
	square2.AddVector(
		Vector3f(1, 0, 0), 
		Vector3f(1, 0, 1), 
		Vector3f(1, 1, 1), 
		Vector3f(1, 1, 0));
	Matrix3f square3;
	square3.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(0, 0, 1),
		Vector3f(0, 1, 1),
		Vector3f(0, 1, 0));
	Matrix3f square4;
	square4.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 0, 1),
		Vector3f(0, 0, 1));
	Matrix3f square5;
	square5.AddVector(
		Vector3f(0, 1, 0),
		Vector3f(1, 1, 0),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));
	Matrix3f square6;
	square6.AddVector(
		Vector3f(0, 0, 1),
		Vector3f(1, 0, 1),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));

	std::vector<Matrix3f> matrices;
	matrices.push_back(square);
	matrices.push_back(square2);
	matrices.push_back(square3);
	matrices.push_back(square4);
	matrices.push_back(square5);
	matrices.push_back(square6);



	Shape s(matrices,Vector3f(.5,.5,0));
	s.translate(Vector3f(1, 1, 0));
	Shape s2(s);
	s.rotate(Vector3f(45, 45, 45));
	s.translate(Vector3f(1, 1, 0));
	//s.rotate(Vector3f(0, 45, 45));
	//s2.translate(Vector3f(1, 1, 0));
	//s2.rotate(Vector3f(0, 0, 45));
	//s2.translate(Vector3f(1, 1, 0));
	window.addToShapes(&s);
	window.addToShapes(&s2);
	window.render2();

	//window.addToShapes(shape);
	//window.render();
	return 0;
}