#include "drop_shadow.h"
#include "material_renderable.h"

drop_shadow::drop_shadow(renderable* parent)
{
	_parent           = parent;
	_gparent          = &(static_cast<material_renderable*>(_parent)->get_parent());
	_render_attempted = false;
	_opacity          = 0.70f;
}

drop_shadow::~drop_shadow()
{
	_parent = nullptr;
}

bool drop_shadow::render()
{
	if (!_render_attempted)
	{
		_render_attempted = true;

		store_parent_variables();
		calc_shadow_variables();

		_parent->render();

		restore_parent_variables();

		_render_attempted = false;
	}

	return !_render_attempted;
}

void drop_shadow::calc_shadow_variables()
{
	colour _gparent_colour = _gparent->get_colour();

	_parent->set_colour((*(_gparent_colour.get_red()) * _opacity),
		                (*(_gparent_colour.get_green()) * _opacity), 
						(*(_gparent_colour.get_green()) * _opacity),
						255.0f);

	float z_difference = _parent_coordinates.get_z() - _gparent->get_coordinate(Z);

	if (z_difference >= 1)
	{
		_parent->set_coordinates(_parent_coordinates.get_x() + (1.5f * z_difference),
                                 _parent_coordinates.get_y() - (1.5f * z_difference),
                                 _gparent->get_coordinate(Z));

		_parent->set_depth(0);
		_parent->set_height(_parent_height);
		_parent->set_width(_parent_width);
	}
	else if (z_difference <= 0)
	{
		_parent->set_coordinates(_parent_coordinates.get_x() - 1.5f,
                                 _parent_coordinates.get_y() - 1.5f,
                                 _gparent->get_coordinate(Z));

		_parent->set_depth(0);
		_parent->set_height(_parent_height + 3.0f);
		_parent->set_width(_parent_width + 3.0f);
	}
}

void drop_shadow::restore_parent_variables()
{
	_parent->set_colour(_parent_colour);
	_parent->set_coordinates(_parent_coordinates);
	_parent->set_depth(_parent_depth);
	_parent->set_height(_parent_height);
	_parent->set_width(_parent_width);
}

void drop_shadow::set_opacity(float value)
{
	if (value > 1.0f)
	{
		_opacity = 1.0f;
	}
	else if (value < 0.0f)
	{
		_opacity = 0.0f;
	}
	else
	{
		_opacity = value;
	}
}

void drop_shadow::store_parent_variables()
{
	_parent_colour      = _parent->get_colour();
	_parent_coordinates = _parent->get_coordinates();
	_parent_depth       = _parent->get_dimention(Depth);
	_parent_height      = _parent->get_dimention(Height);
	_parent_width       = _parent->get_dimention(Width);
}