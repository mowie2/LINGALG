#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Vector3f.h"
#include "Matrix4x4.h"

class Matrix3f
{
public:
	Matrix3f() = default;
	Matrix3f(unsigned int columns);
	Matrix3f(const Matrix& original);
	~Matrix3f() = default;
	
	template <typename F, typename... Vec>
	void AddVector(F &&f) {
		matrix_.AddVector(std::move(f.getVector()));
	}

	template <typename F, typename... Vec>
	void AddVector(F &&f, Vec &&... vectors) {
		static_assert(std::is_same_v<F, Vector3f&>|| std::is_same_v<F, Vector3f>, "First argument must be Vector3f");
		static_assert(((std::is_same_v<Vec, Vector3f&> || std::is_same_v<F, Vector3f>) && ...), "All arguments must be Vector3f");
		matrix_.AddVector(std::move(f.getVector()));
		AddVector(std::forward<Vec>(vectors)...);
	}



	Vector get_row(unsigned int row) const;
	Vector3f get_column(unsigned int column) const;
	unsigned int getColumns() const;
	Vector& operator[](unsigned int index);
	Matrix3f operator+(const Matrix3f&other) const;
	Matrix3f operator-(const Matrix3f&other) const;
	Matrix operator*(const Matrix&other) const;
	Vector3f operator*(const Vector3f&other) const;
	Matrix getTranslatable() const;
	//Matrix3f translate(const Vector3f& vec) const;
	//Matrix3f scale();
	Matrix getMatrix() const;


	static Matrix3f getIdentityMatrix();
private:
	Matrix matrix_;
};

