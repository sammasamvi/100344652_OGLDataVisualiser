#include "OGLBarChart.h"

OGLBarChart::OGLBarChart(OGLScene& parent) : OGLChart(parent)
{
	_axisWidth  = 4.0f;
	_axisColour = new Colour();
	*_margin    = Margin(20, 20);
	_background = new OGLRectangle(0, 0, _width, _height);

	_background->setMargin(*_margin);
}

bool OGLBarChart::close()
{
	return false;
}

bool OGLBarChart::render()
{
	_background->render();
	renderAxes();
	renderScale();
	renderBars();

	return false;
}

bool OGLBarChart::renderAxes()
{
	glLineWidth(_axisWidth);
	assertColour(*_axisColour);
	
	glBegin(GL_LINES);
	    glVertex2d(_margin->getLeft() + (_axisWidth - 2), _height - _margin->getTop());
	    glVertex2d(_margin->getLeft() + (_axisWidth - 2), _margin->getBottom());
	    glVertex2d(_margin->getLeft(),                    _margin->getBottom() + (_axisWidth - 2));
		glVertex2d(_width - _margin->getRight(),          _margin->getBottom() + (_axisWidth - 2));
	glEnd();

	assertColour(_parent->getBackgroudColour());
	glLineWidth(1.0f);

	return false;
}

bool OGLBarChart::renderBars()
{
	return false;
}

bool OGLBarChart::renderScale()
{
	return false;
}

void OGLBarChart::resize(int width, int height)
{
	OGLScene::resize(width, height);
	_background->setDimentions(_width, _height);
}

void OGLBarChart::setBackgroudColour(int red, int green, int blue)
{
	OGLScene::setBackgroudColour(red, green, blue);
	_background->setColour(*_bColour);
}

void OGLBarChart::setBackgroudColour(Colour& colour)
{
	OGLScene::setBackgroudColour(colour);
	_background->setColour(*_bColour);
}