#pragma once
#include "../include/Vector.h"
#include <vector>
class Matrix
{
public:
	Matrix();
	Matrix(unsigned int rows, unsigned int columns, bool eenheidsMatrix);

	template <typename F, typename... Vector>
	void AddVector(F &&f) {
		if (rows == 0 || f.getRows() == getRows()){
			rows = f.getRows();
			matrix.push_back(std::move(f));
			columns++;
		}
		else {
			throw std::out_of_range("Invalid");
		}
	}

	
	template <typename F, typename... Vector>
	void AddVector(F &&f, Vector &&... fs) {
		if (rows == 0 ||f.getRows() == getRows()) {
			matrix.push_back(std::move(f));
			columns++;
			
		}
		else {
			throw std::out_of_range("Invalid");
		}
		AddVector(std::forward<Vector>(fs)...);
	}
	
	//void AddVector(const Vector & vector);

	Matrix operator+ (const Matrix &other) const;
	Matrix operator- (const Matrix &other) const;
	Matrix operator* (const Matrix &other) const;
	Matrix operator* (float scalar) const;
	Matrix subSet(unsigned int rows, unsigned int columns) const;
	Matrix getTranslatable() const;

	Matrix scale (float scalar) const;
	void scaleThis(float scalar);

	Vector operator[] (unsigned int index) const;
	Vector& operator[] (unsigned int index);
	Vector getToOrginVector() const;
	unsigned int getRows() const;
	unsigned int getColumns() const;
	

	Matrix translate(const Vector& translation) const;
	Matrix translateToOrgin() const;
	void translateThis(const Vector& translation);

	Matrix rotate(const Vector& rotate) const;

	~Matrix();
private:
	
	unsigned int rows = 0;
	unsigned int columns = 0;
	std::vector<Vector> matrix;
};

