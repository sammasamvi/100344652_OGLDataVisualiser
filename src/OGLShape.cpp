#include "OGLShape.h"

OGLShape::OGLShape(int x, int y, int width, int height)
{
	_width    = width;
	_height   = height;
	_position = new homogenCoord(x, y, false);
	_colour   = new Colour();
	_margin   = new Margin();
}

void OGLShape::applyColour()
{
	glColor3f(_colour->getOGLColourVal(Red), 
              _colour->getOGLColourVal(Green), 
			  _colour->getOGLColourVal(Blue));
}

Colour* OGLShape::getColour() const
{
	return _colour;
}

int OGLShape::getCoordinate(ECoordinate coordinate) const
{
	switch (coordinate)
	{
	    case X:
	    	return _position->getX();
	    	break;
	    
	    case Y:
	    	return _position->getY();
	    	break;
	    
	    default:
	    	return _position->getZ();
	    	break;
	}
}

int OGLShape::getDimention(EDimention dimention) const
{
	switch (dimention)
	{
	    case Height:
			return _height;
	    	break;

	    case Width:
			return _width;
	    	break;
	    
	    default:
	    	return 0;
	    	break;
	}
}

int OGLShape::getMargin(EMargin margin) const
{
	switch (margin)
	{
	case Bottom:
		return _margin->getBottom();
		break;

	case Left:
		return _margin->getLeft();
		break;

	case Right:
		return _margin->getRight();
		break;

	default:
		return _margin->getTop();
		break;
	}
}

void OGLShape::move(int x, int y)
{
	int newX = x + _position->getX();
	int newY = x + _position->getY();

	_position = new homogenCoord(newX, newY, false);
}

void OGLShape::setColour(int red, int green, int blue)
{
	_colour = &Colour(red, green, blue);
}

void OGLShape::setColour(Colour& colour)
{
	_colour = &colour;
}

void OGLShape::setDimentions(int width, int height)
{
	_width  = width;
	_height = height;
}

void OGLShape::setMargin(int left_right, int bottom_top)
{
	_margin = &Margin(left_right, bottom_top);
}

void OGLShape::setMargin(int left, int bottom, int right, int top)
{
	_margin = &Margin(left, bottom, right, top);
}

void OGLShape::setMargin(Margin& margin)
{
	_margin = &margin;
}

void OGLShape::setPosition(int x, int y)
{
	_position = new homogenCoord(x, y, false);
}