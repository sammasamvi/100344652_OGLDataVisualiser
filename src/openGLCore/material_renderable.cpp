#include "material_renderable.h"

material_renderable::material_renderable(const renderable* parent) : child_renderable(parent)
{
	render_shadow = true;
	_shadow       = nullptr;
}

material_renderable::~material_renderable()
{
	_parent = nullptr;

	if (_shadow)
		delete _shadow;
}

bool material_renderable::render()
{
	bool rendered = true;

	if (render_shadow && _shadow)
		rendered = _shadow->render();

	if (rendered)
		rendered = render_fill();

	if (rendered)
		return render_outline();

	return rendered;
}