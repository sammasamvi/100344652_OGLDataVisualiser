#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "colour.h"
#include "homogeneous_coordinate.h"
#include "enums\eDimention.h"
#include "enums\eHCoordinate.h"

class renderable
{
    protected:
		colour       _colour;
		float        _depth;
		hCoordinate  _coordinates;
		float        _height;
		bool         _render;
		float        _width;

		renderable();
    public:
		virtual colour      get_colour()                                                 const;
		virtual float       get_coordinate(eHCoordinate coordinate)                      const;
		virtual hCoordinate get_coordinates()                                            const;
		virtual float       get_dimention(eDimention dimention)                          const;
		virtual bool        render()                                                            = 0;
		virtual bool        resize(float width, float height);
		virtual void        set_colour(const colour& value);
		virtual void        set_colour(int red, int green, int blue);
		virtual void        set_colour(int red, int green, int blue, int alpha);
		virtual void        set_colour_channel(eColour channel, int value);
		virtual void        set_coordinates(const hCoordinate& value);
		virtual void        set_coordinates(float x, float y);
		virtual void        set_coordinates(float x, float y, float z);
		virtual void        set_depth(float depth);
		virtual void        set_height(float height);
		virtual void        set_width(float width);
};

#endif