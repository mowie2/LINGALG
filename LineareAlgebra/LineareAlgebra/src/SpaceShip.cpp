#include "../include/SpaceShip.h"



SpaceShip::SpaceShip()
{
	//voorkant
	Matrix m1;
	Vector v1;
	v1.addNumber(2.f, 1.f, 0.f);
	Vector v2;
	v2.addNumber(2.f, 2.f, 0.f);
	Vector v3;
	v3.addNumber(1.f, 2.f, 0.f);
	Vector v4;
	v4.addNumber(1.f, 1.f, 0.f);

	//zijkant rechts
	Matrix m2;
	Vector v5;
	v5.addNumber(2.f, 1.f, 0.f);
	Vector v6;
	v6.addNumber(2.f, 1.f, 1.f);
	Vector v7;
	v7.addNumber(2.f, 2.f, 1.f);
	Vector v8;
	v8.addNumber(2.f, 2.f, 0.f);
	
	Matrix m3;
	Vector v9;
	v9.addNumber(2.f, 1.f, 0.f);
	Vector v10;
	v10.addNumber(2.f, 2.f, 0.f);
	Vector v11;
	v11.addNumber(1.f, 2.f, 0.f);
	Vector v12;
	v12.addNumber(1.f, 1.f, 0.f);

	Vector t;
	t.addNumber(0.f, -1.f, 0.f);
	m3.AddVector(v9, v10, v11, v12);
	m3 = (m3.translateToOrgin()).translate(t);

	

	m1.AddVector(v1, v2, v3, v4);
	m2.AddVector(v5, v6, v7, v8);
	//m1 = m1.scale(1);
	//
	auto toOrgin = (m1.getToOrginVector() + m2.getToOrginVector()) * .5f;
	//auto returnV = toOrgin * -1;
	//m1 = (Matrix::getRotateYMatrix3d(45)* m1.translate(toOrgin).getTranslatable()).subSet(m1.getRows(),m1.getColumns()).translate(returnV);
	//m2 = (Matrix::getRotateYMatrix3d(45)* m2.translate(toOrgin).getTranslatable()).subSet(m2.getRows(), m2.getColumns()).translate(returnV);

	//m1 = (Matrix::getRotateYMatrix3d(45)* m1.translateToOrgin().getTranslatable()).subSet(m1.getRows(),m1.getColumns()).translate(k1);
	//m2 = (Matrix::getRotateYMatrix3d(45)* m2.translateToOrgin().getTranslatable()).subSet(m2.getRows(), m2.getColumns()).translate(k2);
	//m1 = Matrix::getRotateYMatrix3d(90)* m1.translateToOrgin().getTranslatable();
	
	shape_.setPos(toOrgin);
	shape_.addMatix(m1);
	shape_.addMatix(m2);
	//shape_.addMatix(m3);
}


SpaceShip::~SpaceShip()
{
}