#include "OGLDataRepresenter.h"

OGLDataRepresenter::OGLDataRepresenter()
{
	_colour     = nullptr;
	_renderable = nullptr;
}

OGLDataRepresenter::OGLDataRepresenter(Colour& colour, OGLRenderable& renderable)
{
	_colour     = &colour;
	_renderable = &renderable;
}

const Colour& OGLDataRepresenter::getColour() const
{
	return *_colour;
}

const OGLRenderable& OGLDataRepresenter::getRenderable() const
{
	return *_renderable;
}