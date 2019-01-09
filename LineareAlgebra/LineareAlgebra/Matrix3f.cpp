#include "Matrix3f.h"


Matrix3f::Matrix3f(unsigned int columns)
{
	columns_ = columns;
	for(unsigned int i = 0;i< columns;i++)
	{
		matrix_.emplace_back(Vector());
	}
}

Vector Matrix3f::get_row(unsigned int row) const
{
	return Vector();
}

Matrix3f Matrix3f::get_identity_matrix()
{
	auto m = Matrix3f(3);
	for(auto i = 0;i<3;i++)
	{
		//m[i][i] = 1;
	}
	return m;

}
