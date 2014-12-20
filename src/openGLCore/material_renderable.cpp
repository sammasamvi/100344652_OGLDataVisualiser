#include "material_renderable.h"

material_renderable::material_renderable(const renderable* parent)
{
	_parent       = parent;
	_coordinates  = hCoordinate(_parent->get_coordinate(X),
		                        _parent->get_coordinate(Y),
								_parent->get_coordinate(Z) + 2);
	render_shadow = true;
	_shadow       = nullptr;
	_depth        = 1;
}

material_renderable::~material_renderable()
{
	_parent = nullptr;

	if (_shadow)
		delete _shadow;
}

const renderable& material_renderable::get_parent() const
{
	return *_parent;
}

bool material_renderable::render()
{
	if (render_shadow && _shadow)
		return _shadow->render();

	return false;
}

void material_renderable::set_coordinates(float x, float y, float z)
{
	_coordinates = hCoordinate(_parent->get_coordinate(X) + x,
		                       _parent->get_coordinate(Y) + y,
							   _coordinates.get_z());
}