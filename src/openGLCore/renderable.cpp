#include "renderable.h"

renderable::renderable()
{
	_depth  = 0.0f;
	_height = 0.0f;
	_render = true;
	_width  = 0.0f;
}

colour renderable::get_colour() const
{
	return _colour;
}

float renderable::get_coordinate(eHCoordinate coordinate) const
{
	switch (coordinate)
	{
	case W:
		return _coordinates.get_w();
		break;

	case X:
		return _coordinates.get_x();
		break;

	case Y:
		return _coordinates.get_y();
		break;

	case Z:
		return _coordinates.get_z();
		break;
	}
}

hCoordinate renderable::get_coordinates() const
{
	return _coordinates;
}

float renderable::get_dimention(eDimention dimention) const
{
	switch (dimention)
	{
	    case Depth:
			return _depth;
	    	break;
	    
	    case Height:
			return _height;
	    	break;
	    
	    case Width:
			return _width;
	    	break;
	}
}

bool renderable::resize(float width, float height)
{
	set_width(width);
	set_height(height);

	return true;
}

void renderable::set_colour(int red, int green, int blue, int alpha)
{
	_colour = colour(red, green, blue, alpha);
}

void renderable::set_colour(int red, int green, int blue)
{
	set_colour(red, green, blue, *(_colour.get_alpha()));
}

void renderable::set_colour_channel(eColour channel, int value)
{
	switch (channel)
    {
        case Alpha:
			set_colour(*(_colour.get_red()),
                       *(_colour.get_green()),
                       *(_colour.get_blue()),
                       value);
        	break;
    
        case Blue:
			set_colour(*(_colour.get_red()),
                       *(_colour.get_green()), 
                       value,
                       *(_colour.get_alpha()));
        	break;
    
        case Green:
			set_colour(*(_colour.get_red()),
                       value,
                       *(_colour.get_blue()), 
                       *(_colour.get_alpha()));
        	break;
    
        case Red:
			set_colour(value,
                       *(_colour.get_green()), 
                       *(_colour.get_blue()), 
                       *(_colour.get_alpha()));
        	break;
    }
}

void renderable::set_colour(const colour& value)
{
	_colour = colour(value);
}

void renderable::set_coordinates(const hCoordinate& value)
{
	set_coordinates(value.get_x(), 
		            value.get_y(), 
					value.get_z());
}

void renderable::set_coordinates(float x, float y, float z)
{
	_coordinates = hCoordinate(x, y, z);
}

void renderable::set_coordinates(float x, float y)
{
	set_coordinates(x, 
		            y, 
					_coordinates.get_z());
}

void renderable::set_depth(float depth)
{
	_depth = depth;
}

void renderable::set_height(float height)
{
	_height = height;
}

void renderable::set_width(float width)
{
	_width = width;
}