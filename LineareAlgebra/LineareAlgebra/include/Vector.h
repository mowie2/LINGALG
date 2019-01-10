#pragma once
#include <vector>
class Vector
{
public:
	Vector() = default;
	Vector(unsigned int rows);

	template <typename F>
	void addNumber(F &&f) {
		vector_.push_back(f);
	}

	template <typename F, typename... Float>
	void addNumber(F &&f, Float&&... number) {
		static_assert(std::is_same_v<F, float>, "First argument must be float");
		static_assert((std::is_same_v<Float, float> && ...), "All arguments must be floats");
		vector_.push_back(std::move(f));

		addNumber(std::forward<Float>(number)...);
	}

	~Vector();
	unsigned int getRows() const;
	
	//void addNumber(float number);
	
	void normalize();
	float operator[](unsigned index) const;
	float& operator[](unsigned index);
	Vector& operator=(const Vector& other);
	float operator*(const Vector &other) const;
	float getLength() const;
	Vector operator+(const Vector &other) const;
	Vector operator-(const Vector &other) const;
	Vector operator*(float number) const;
private:
	std::vector<float> vector_;
};

