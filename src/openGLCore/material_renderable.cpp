#include "material_renderable.h"

material_renderable::material_renderable(const renderable& parent)
{
	_parent = &parent;
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