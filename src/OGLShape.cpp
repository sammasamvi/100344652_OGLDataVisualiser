#include "OGLShape.h"

OGLShape::OGLShape(float width, float height, homogenCoord& position)
{
	_width    = width;
	_height   = height;
	_position = &position;
}

float OGLShape::getHeight()
{
	return _height;
}

homogenCoord& OGLShape::getPosition()
{
	return *_position;
}

float OGLShape::getWidth()
{
	return _width;
}

void OGLShape::move(homogenCoord& vector)
{
	*_position = *_position + *&vector;
}

void OGLShape::setDimentions(float width, float height)
{
	_width  = width;
	_height = height;
}

void OGLShape::setPosition(homogenCoord& point)
{
	_position = &point;
}