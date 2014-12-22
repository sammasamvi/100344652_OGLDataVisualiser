#include "child_renderable.h"

child_renderable::child_renderable(const renderable* parent)
{
	_depth        = 1;
	_parent       = parent;
	
	set_coordinates(0, 0, 1);
}

child_renderable::~child_renderable()
{
	_parent = nullptr;
}

const renderable* child_renderable::get_parent() const
{
	return _parent;
}

void child_renderable::set_coordinates(float x, float y, float z)
{
	float _x = x + _parent->get_coordinate(X);
	float _y = y + _parent->get_coordinate(Y);
	float _z = z + _parent->get_coordinate(Z);

	_x = (_x - _parent->get_coordinate(X)) > 0.00f ? _x : 0.0f;
	_x = (_y - _parent->get_coordinate(Y)) > 0.00f ? _y : 0.0f;
	_z = (_z - _parent->get_coordinate(Z)) > 0.99f ? _z : 1.0f;

	_coordinates = hCoordinate(_x, _y, _z);
}