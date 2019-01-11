#pragma once
#include "../include/Vector.h"
#include <vector>
class Matrix
{
public:
	Matrix();
	Matrix(unsigned int rows, unsigned int columns);

	template <typename F, typename... Vec>
	void AddVector(F &&f) {
		if (rows == 0 || f.getRows() == getRows()){
			rows = f.getRows();
			matrix.push_back(f);
			columns++;
		}
		else {
			throw std::invalid_argument("Rows must be the same");
		}
	}

	
	template <typename F, typename... Vec>
	void AddVector(F &&f, Vec&&... vectors) {
		static_assert(std::is_same_v<F, Vector&>, "First argument must be Vector");
		static_assert((std::is_same_v<Vec, Vector&> && ...), "All arguments must be Vector");
		if (rows == 0 ||f.getRows() == getRows()) {
			matrix.push_back(std::move(f));
			columns++;
		}
		else {
			throw std::invalid_argument("Rows must be the same");
		}
		AddVector(std::forward<Vec>(vectors)...);
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

	Matrix rotate3d(const Vector& rotate) const;
	static Matrix getRotateXMatrix3d(float degrees);
	static Matrix getRotateYMatrix3d(float degrees);
	static Matrix getRotateZMatrix3d(float degrees);
	float calculateInProduct(Vector& vec1, Vector& vec2);

	static Matrix getIdentityMatrix(unsigned int dimensions);
	~Matrix();
private:
	
	unsigned int rows = 0;
	unsigned int columns = 0;
	std::vector<Vector> matrix;
};

