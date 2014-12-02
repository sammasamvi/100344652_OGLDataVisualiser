#ifndef OGL_SHAPE_H
#define OGL_SHAPE_H

#include "Colour.h"
#include "ECoordinate.h"
#include "EDimention.h"
#include "homogenCoord.h"
#include "Margin.h"
#include "OGLRenderable.h"

//Base class for drawing two-dimentional shapes in opengl
class OGLShape : public OGLRenderable
{
	private:
		Colour*       _colour;
		int	          _height;
		Margin*       _margin;
		int	          _width;
		homogenCoord* _position;

    protected:
        void applyColour();
	
	public:
		OGLShape(int x, int y, int width, int height);

		Colour*      getColour()                           const;
		int          getCoordinate(ECoordinate coordinate) const;
		int          getDimention(EDimention dimention)    const;
		int          getMargin(EMargin margin)             const;
		void         move(int x, int y);
		virtual bool render() = 0;
		void         setColour(int red, int green, int blue);
		void         setColour(Colour& colour);
		void         setDimentions(int width, int height);
		void         setMargin(int left_right, int bottom_top);
		void         setMargin(int left, int bottom, int right, int top);
		void         setMargin(Margin& margin);
		void         setPosition(int newX, int newY);
};

#endif