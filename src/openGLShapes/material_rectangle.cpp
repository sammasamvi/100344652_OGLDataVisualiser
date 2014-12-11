#include "material_rectangle.h"
#include <Windows.h>
#include <gl\GL.h>

material_rectangle::material_rectangle(const material_rectangle* parent) : material_renderable(*parent)
{
	_shadow = nullptr;
}

material_rectangle::material_rectangle(const renderable& parent) : material_renderable(parent)
{
	_shadow = new material_rectangle(this);
}

bool material_rectangle::render()
{
	material_renderable::render();

	glColor3f(_colour.get_colour_channel(Red),
		      _colour.get_colour_channel(Green),
		      _colour.get_colour_channel(Blue));

	glBegin(GL_POLYGON);
		glVertex2d(_coordinates.get_x(),          _coordinates.get_y());
		glVertex2d(_coordinates.get_x() + _width, _coordinates.get_y());
		glVertex2d(_coordinates.get_x() + _width, _coordinates.get_y() + _height);
		glVertex2d(_coordinates.get_x(),          _coordinates.get_y() + _height);
    glEnd();

	return true;
}

