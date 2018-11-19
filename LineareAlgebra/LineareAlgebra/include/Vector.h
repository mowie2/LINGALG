#pragma once
class Vector
{
private:
	float xCor, yCor;

public:
	//constructors
	Vector();
	Vector(const float xCor,const float yCor);

	//functions
	void setXCor(const float xCor);
	void setYCor(const float yCor);
	float getXCor() const;
	float getYCor() const;
	float getLength() const;
	Vector normalize() const;
	unsigned int getSize() const { return 2; }

	//operator overloads
	Vector operator+ (Vector const &obj) const;
	Vector operator- (Vector const &obj) const;
	Vector operator* (const int &multiplier) const;
	float operator* (Vector const &otherVector) const;

	virtual ~Vector();
};

