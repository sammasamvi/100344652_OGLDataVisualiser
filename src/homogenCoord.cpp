#include "homogenCoord.h"

homogenCoord::homogenCoord(int x, int y, bool isVector)
             :homogenCoord(x, y, 0, isVector ? 0:1)
             {}

homogenCoord::homogenCoord(int x, int y, int z, bool isVector)
             :homogenCoord(x, y, z, isVector ? 0:1)
             {}

homogenCoord::homogenCoord(int x, int y, int z, int w)
{
	if (w > 0)
	{
		_w = 1;
	}
	else
	{
		_w = 0;
	}
	_x = x;
	_y = y;
	_z = z;
}

void homogenCoord::copy(const homogenCoord& original)
{
	_w = original.getW();
	_x = original.getX();
	_y = original.getY();
	_z = original.getZ();
}

homogenCoord::homogenCoord(const homogenCoord& original)
{
	copy(original);
}

int homogenCoord::getW() const
{
	return _w;
}

int homogenCoord::getX() const
{
	return _x;
}

int homogenCoord::getY() const
{
	return _y;
}

int homogenCoord::getZ() const
{
	return _z;
}

int homogenCoord::isVector(int rhs) const
{
	if (rhs > 0 || this->_w > 0)
	{
		return 1;
	}

	return 0;
}

homogenCoord homogenCoord::operator+(const homogenCoord& rhs) const
{
	int newX = this->_x + rhs.getX();
	int newY = this->_y + rhs.getY();
	int newZ = this->_z + rhs.getZ();

	return homogenCoord(newX, newY, newZ, isVector(rhs._w));
}

homogenCoord homogenCoord::operator-(const homogenCoord& rhs) const
{
	int newX = this->_x - rhs.getX();
	int newY = this->_y - rhs.getY();
	int newZ = this->_z - rhs.getZ();

	return homogenCoord(newX, newY, newZ, isVector(rhs._w));
}

void homogenCoord::operator=(const homogenCoord& rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
}