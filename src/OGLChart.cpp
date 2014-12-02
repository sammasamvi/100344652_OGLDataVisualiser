#include "OGLChart.h"

OGLChart::OGLChart(OGLScene& parent)
{
	_parent              = &parent;
	_bColour             = &parent.getBackgroudColour();
	_width               = parent.getDimention(Width);
	_height              = parent.getDimention(Height);
	_dataRepresenters[0] = nullptr;
	_margin              = new Margin();
}

void OGLChart::setMargin(int left_right, int bottom_top)
{
	_margin = &Margin(left_right, bottom_top);
}

void OGLChart::setMargin(int left, int bottom, int right, int top)
{
	_margin = &Margin(left, bottom, right, top);
}

void OGLChart::setMargin(Margin& margin)
{
	_margin = &margin;
}