#pragma once
class Vector
{
private:
	int xCor, yCor;

public:
	//constructors
	Vector();
	Vector(const int xCor,const int yCor);

	//functions
	void setXCor(const int xCor);
	void setYCor(const int yCor);
	int getXCor() const;
	int getYCor() const;
	float getLength() const;
	Vector normalize() const;

	//operator overloads
	Vector operator+ (Vector const &obj) const;
	Vector operator- (Vector const &obj) const;
	Vector operator* (const int &multiplier) const;

	virtual ~Vector();
};

