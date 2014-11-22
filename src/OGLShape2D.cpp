#include "OGLShape2D.h"

// todo: add colour fill support

OGLShape2D::OGLShape2D(int x, int y, float width, float height)
{
	setPosition(x, y);
	setDimentions(width, height);
}

float OGLShape2D::getHeight()
{
	return height;
}

float OGLShape2D::getWidth()
{
	return width;
}

int OGLShape2D::getX()
{
	return x;
}

int OGLShape2D::getY()
{
	return y;
}

void OGLShape2D::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void OGLShape2D::setDimentions(float width, float height)
{
	this->width  = width;
	this->height = height;
}