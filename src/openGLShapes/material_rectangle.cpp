#include "material_rectangle.h"
#include <Windows.h>
#include <gl\GL.h>

material_rectangle::material_rectangle(const renderable* parent) : material_renderable(parent) 
{
    _shadow = new drop_shadow(this);
}

bool material_rectangle::render()
{
	bool shadow_rendered = material_renderable::render();

	glColor3f(_colour.get_colour_channel(Red),
		      _colour.get_colour_channel(Green),
		      _colour.get_colour_channel(Blue));

	glBegin(GL_POLYGON);
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y(),           _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y(),           _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y() + _height, _coordinates.get_z());
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y() + _height, _coordinates.get_z());
    glEnd();

	if (shadow_rendered)
		render_outline();

	return true;
}

bool material_rectangle::render_outline()
{
	glLineWidth(0.5f);

	glColor3f(0.45f,
		      0.45f,
		      0.45f);

	glBegin(GL_LINES);
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y(),               _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y(),               _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y(),               _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y() + _height,     _coordinates.get_z());
		glVertex3f(_coordinates.get_x() + _width, _coordinates.get_y() + _height,     _coordinates.get_z());
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y() + _height,     _coordinates.get_z());
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y() + _height + 1, _coordinates.get_z()); // line not closing cleanly without + 1
		glVertex3f(_coordinates.get_x(),          _coordinates.get_y(),               _coordinates.get_z());
    glEnd();

	return true;
}

