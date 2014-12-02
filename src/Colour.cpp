#include "Colour.h"

Colour::Colour(int red, int green, int blue)
{
	_red   = boundInputVal(red);
	_green = boundInputVal(green);
	_blue  = boundInputVal(blue);
}

Colour::Colour()
{
	_red   = 0;
	_green = 0;
	_blue  = 0;
}

int Colour::boundInputVal(int value)
{
	if (value > 255)
	{
		return 255;
	}
	
	if (value < 0)
	{
		return 0;
	}

	return value;
}

int Colour::getColourVal(EColour colour) const
{
	switch (colour)
	{
	case Red:
		return _red;
		break;

	case Green:
		return _green;
		break;

	default:
		return _blue;
		break;
	}
}

float Colour::getOGLColourVal(EColour colour) const
{
	float value = getColourVal(colour) / 255;
	
	return value;
}