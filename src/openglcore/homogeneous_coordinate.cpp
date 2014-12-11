#include "homogeneous_coordinate.h"

hCoordinate::hCoordinate(float x, float y, float z, bool w)
{
	_w = w;
	_x = x;
	_y = y;
	_z = z;

	_oGLVArray_length = 3;
	_oGLVArray        = new float[_oGLVArray_length];
}

hCoordinate::hCoordinate(float x, float y, float z) : hCoordinate(x, y, z, true)
{ }

hCoordinate::hCoordinate(float x, float y) : hCoordinate(x, y, 0, true)
{
	_oGLVArray_length = 2;
}

hCoordinate::hCoordinate(const hCoordinate& original)
{
	assign_from(original);
}

hCoordinate::~hCoordinate()
{
	delete[] _oGLVArray;
}

hCoordinate::hCoordinate() : hCoordinate(0, 0, 0, true)
{ }

void hCoordinate::assign_from(const hCoordinate& src)
{
	_w = (src.get_w() == 1);
	_x = src.get_x();
	_y = src.get_y();
	_z = src.get_z();

	_oGLVArray_length = src.get_oGLVArray_length();
	_oGLVArray        = src.get_oGLVArray();
}

float* hCoordinate::get_oGLVArray() const
{
	return _oGLVArray;
}

const int hCoordinate::get_oGLVArray_length() const
{
	return _oGLVArray_length;
}

const int hCoordinate::get_w() const
{
	return _w ? 1 : 0;
}

const float hCoordinate::get_x() const
{
	return _x;
}

const float hCoordinate::get_y() const
{
	return _y;
}

const float hCoordinate::get_z() const
{
	return _z;
}

const hCoordinate* hCoordinate::operator+(const hCoordinate& rhs)
{
	return new hCoordinate(_x + rhs.get_x(),
		                   _y + rhs.get_y(),
						   _z + rhs.get_z(),
						   resutl_is_not_vector(rhs.get_w()));
}

const hCoordinate* hCoordinate::operator-(const hCoordinate& rhs)
{
	return new hCoordinate(_x - rhs.get_x(),
		                   _y - rhs.get_y(),
						   _z - rhs.get_z(),
						   resutl_is_not_vector(rhs.get_w()));
}

void hCoordinate::operator=(const hCoordinate& rhs)
{
	if (this != &rhs)
	{
		assign_from(rhs);
	}
}

bool hCoordinate::resutl_is_not_vector(int rhs_w)
{
	if (rhs_w == 0 && !_w)
	{
		return false;
	}

	return true;
}