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
		colour       get_colour()                                                 const;
		float        get_coordinate(eHCoordinate coordinate)                      const;
		hCoordinate  get_coordinates()                                            const;
		float        get_dimention(eDimention dimention)                          const;
		virtual bool render()                                                            = 0;
		bool         resize(float width, float height);
		void         set_colour(const colour& value);
		void         set_colour(int red, int green, int blue);
		void         set_colour(int red, int green, int blue, int alpha);
		void         set_colour_channel(eColour channel, int value);
		void         set_coordinates(const hCoordinate& value);
		void         set_coordinates(float x, float y);
		void         set_coordinates(float x, float y, float z);
		void         set_depth(float depth);
		void         set_height(float height);
		void         set_width(float width);
};

#endif