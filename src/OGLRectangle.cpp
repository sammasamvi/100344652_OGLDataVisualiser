#include "OGLRectangle.h"

bool OGLRectangle::render()
{
	glBegin(GL_POLYGON);
	    applyColour();

		glVertex2d(getCoordinate(X) + getMargin(Left),                        getCoordinate(Y) + getMargin(Bottom));
		glVertex2d(getCoordinate(X) - getMargin(Right) + getDimention(Width), getCoordinate(Y) + getMargin(Bottom));
		glVertex2d(getCoordinate(X) - getMargin(Right) + getDimention(Width), getCoordinate(Y) - getMargin(Top) + getDimention(Height));
		glVertex2d(getCoordinate(X) + getMargin(Left),                        getCoordinate(Y) - getMargin(Top) + getDimention(Height));
    glEnd();

	return true;
}