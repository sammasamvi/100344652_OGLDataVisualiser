#include "homogenCoord.h"

homogenCoord::homogenCoord(float x, float y, bool isVector) : homogenCoord(x, y, 0.0f, isVector)
{ }

homogenCoord::homogenCoord(float x, float y, float z, bool isVector)
{
	_w = isVector ? 0.0f:1.0f;
	_x = x;
	_y = y;
	_z = z;
}

homogenCoord::homogenCoord(const homogenCoord& original)
{
	_x = original._x;
	_y = original._y;
	_w = original._w;
}

homogenCoord& homogenCoord::operator+(const homogenCoord& rhs) const
{
	float newX = this->_x + rhs._x;
	float newY = this->_y + rhs._y;
	float newZ = this->_z + rhs._z;

	return homogenCoord(newX, newY, newZ, resultIsVector(this->_w, rhs._w));
}

homogenCoord& homogenCoord::operator-(const homogenCoord& rhs) const
{
	float newX = this->_x - rhs._x;
	float newY = this->_y - rhs._y;
	float newZ = this->_z - rhs._z;

	return homogenCoord(newX, newY, newZ, resultIsVector(this->_w, rhs._w));
}

homogenCoord& homogenCoord::operator=(const homogenCoord& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	return homogenCoord(rhs._x, rhs._y, rhs._z, resultIsVector(this->_w, rhs._w));
}

float homogenCoord::getW()
{
	return _w;
}

float homogenCoord::getX()
{
	return _x;
}

float homogenCoord::getY()
{
	return _y;
}

float homogenCoord::getZ()
{
	return _z;
}

bool homogenCoord::resultIsVector(float lhs_w, float rhs_w)
{
	// if either value is 1 the outcome will be a point
	if (lhs_w > 0 || rhs_w > 0)
	{
		return false;
	}

	return true;
}