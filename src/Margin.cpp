#include "Margin.h"

Margin::Margin(int left, int bottom, int right, int top)
{
	_bottom = bottom;
	_left   = left;
	_right  = right;
	_top    = top;
}

Margin::Margin(int left_right, int bottom_top) : Margin(left_right, bottom_top, left_right, bottom_top)
{ }

Margin::Margin() : Margin(0, 0)
{ }

int Margin::getBottom() const
{
	return _bottom;
}

int Margin::getLeft() const
{
	return _left;
}

int Margin::getRight() const
{
	return _right;
}

int Margin::getTop() const
{
	return _top;
}