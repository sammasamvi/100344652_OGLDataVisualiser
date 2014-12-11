#include "material_renderable.h"

material_renderable::material_renderable(const renderable& parent)
{
	_parent = &parent;
    set_coordinates(_parent->get_coordinates());
}

material_renderable::~material_renderable()
{
	_parent = nullptr;
	delete _shadow;
}

const renderable& material_renderable::get_parent() const
{
	return *_parent;
}

renderable* material_renderable::get_shadow() const
{
	return _shadow;
}

bool material_renderable::render()
{
	if (_shadow)
		_shadow->render();

	return true;
}

bool material_renderable::resize(float width, float height)
{
    if (_shadow)
    	_shadow->resize(width, height);

	return true;
}

void material_renderable::set_coordinates(const hCoordinate& value)
{
	set_coordinates(value.get_x(), value.get_y(), value.get_z());
}

void material_renderable::set_coordinates(float x, float y, float z)
{
	hCoordinate p_coords = _parent->get_coordinates();

	_coordinates = hCoordinate(x + p_coords.get_x(),
		                       y + p_coords.get_y(),
					           z + p_coords.get_z());
}