#include "colour.h"

#define MAX_COLOUR_VAL 255

colour::colour(int red, int green, int blue, int alpha)
{
	set_value(Alpha, alpha);
	set_value(Blue,  blue);
	set_value(Green, green);
	set_value(Red,   red);
}

colour::colour(int red, int green, int blue) : colour(red, green, blue, 0)
{
	
}

colour::colour(const colour& original)
{
	set_value(Alpha, original._alpha);
	set_value(Blue,  original._alpha);
	set_value(Green, original._alpha);
	set_value(Red,   original._alpha);
}

colour::colour() : colour(0, 0, 0, 0)
{

}

const int* colour::get_alpha()
{
	return &_alpha;
}

float colour::get_colour_channel(eColour colour)
{
	switch (colour)
	{
	    case Alpha:
			return (float)_alpha / MAX_COLOUR_VAL;
	    	break;

	    case Blue:
			return (float)_blue / MAX_COLOUR_VAL;
	    	break;

	    case Green:
			return (float)_green / MAX_COLOUR_VAL;
	    	break;

	    case Red:
			return (float)_red / MAX_COLOUR_VAL;
	    	break;

		default:
			return 0.0f;
			break;
	}
}

const int* colour::get_blue()
{
	return &_blue;
}

const int* colour::get_green()
{
	return &_green;
}

const int* colour::get_red()
{
	return &_red;
}

void colour::set_value(eColour colour, const int& value)
{
	int c_value = value;

	if (value < 0)
	{
		c_value = 0;
	}

	if (value > MAX_COLOUR_VAL)
	{
		c_value = MAX_COLOUR_VAL;
	}

	switch (colour)
	{
	    case Alpha:
			_alpha = c_value;
	    	break;

	    case Blue:
			_blue  = c_value;
	    	break;

	    case Green:
			_green = c_value;
	    	break;

	    case Red:
			_red   = c_value;
	    	break;
	}
}