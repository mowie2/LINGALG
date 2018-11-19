#pragma once
#include "include/Vector.h"
#include <vector>
class Matrix
{
public:
	Matrix(unsigned int rows);
	/*
	template <typename F, typename... Vector>
	void AddVector(F &&f) {
		if (f.getSize() != _rows){
			matrix.push_back(std::move(f));
			_columns++;
		}
	}

	template <typename F, typename... Vector>
	void AddVector(F &&f, Vector &&... fs) {
		if (f.getSize() != _rows && typeid(f) == typeid(Vector)) {
			matrix.push_back(std::move(f));
			_columns++;
		}
		AddVector(std::forward<Vector>(fs)...);
	}*/

	void AddVector(Vector && vector);

	Matrix operator+ (const Matrix &other) const;
	Matrix operator- (const Matrix &other) const;
	Matrix operator* (const Matrix &other) const;

	~Matrix();
private:
	unsigned int _rows = 0;
	unsigned int _columns = 0;
	std::vector<Vector> matrix;
};

