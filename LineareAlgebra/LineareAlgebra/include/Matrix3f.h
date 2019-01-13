#pragma once
#include "Vector.h"
#include "Matrix.h"
#include "Vector3f.h"
#include "Matrix4x4.h"

/// <summary>
/// Matrix3f class
/// </summary>
/// <remarks>
/// This class can add, subtract and multiply.
/// </remarks>
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

	/// <summary>
	/// Addes a Vecfor3F to the matrix.
	/// </summary>
	template <typename F, typename... Vec>
	void AddVector(F &&f, Vec &&... vectors) {
		static_assert(std::is_same_v<F, Vector3f&>|| std::is_same_v<F, Vector3f>, "First argument must be Vector3f");
		static_assert(((std::is_same_v<Vec, Vector3f&> || std::is_same_v<F, Vector3f>) && ...), "All arguments must be Vector3f");
		matrix_.AddVector(std::move(f.getVector()));
		AddVector(std::forward<Vec>(vectors)...);
	}


	/// <summary>
	/// returns the row of a matrix3f.
	/// </summary>
	Vector get_row(unsigned int row) const;
	/// <summary>
	/// returns the column of a matrix3f.
	/// </summary>
	Vector3f get_column(unsigned int column) const;
	/// <summary>
	/// returns how many Columns the Martix3f has.
	/// </summary>
	unsigned int getColumns() const;
	/// <summary>
	/// returns a refrence to the vector at the index position.
	/// </summary>
	Vector& operator[](unsigned int index);
	/// <summary>
	/// Addes a Matrix3f to the current Matrix3f.
	/// </summary>
	Matrix3f operator+(const Matrix3f&other) const;
	/// <summary>
	/// Substracts a Matrix3f from the current Matrix3f.
	/// </summary>
	Matrix3f operator-(const Matrix3f&other) const;
	/// <summary>
	/// Multiplies a Matrix3f with the current Matrix3f.
	/// </summary>
	Matrix operator*(const Matrix&other) const;
	Matrix4x4f getTranslatable() const;
	//Matrix3f translate(const Vector3f& vec) const;
	//Matrix3f scale();
	Matrix getMatrix() const;


	static Matrix3f getIdentityMatrix();
private:
	Matrix matrix_;
};

