#include "OGLScene.h"

void OGLScene::assertColour(const Colour& colour) const
{
	glColor3f(colour.getOGLColourVal(Red),
              colour.getOGLColourVal(Green),
			  colour.getColourVal(Blue));
}

Colour& OGLScene::getBackgroudColour() const
{
	return *_bColour;
}

int OGLScene::getDimention(EDimention dimention) const
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
	}
}

void OGLScene::resize(int width, int height)
{
	_width  = width;
	_height = height;
}

void OGLScene::setBackgroudColour(int red, int green, int blue)
{
	_bColour = new Colour(red, green, blue);
}

void OGLScene::setBackgroudColour(Colour& colour)
{
	_bColour = &colour;
}