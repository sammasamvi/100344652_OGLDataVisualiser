#include "OGLRectangle.h"

bool OGLRectangle::render()
{
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2d(getPosition().getX(),              getPosition().getY());
		glVertex2d(getPosition().getX() + getWidth(), getPosition().getY());
		glVertex2d(getPosition().getX() + getWidth(), getPosition().getY() + getHeight());
		glVertex2d(getPosition().getX(),			  getPosition().getY() + getHeight());
    glEnd();

	return true;
}