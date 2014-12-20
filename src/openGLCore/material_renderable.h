#ifndef MATERIAL_RENDERABLE_H
#define MATERIAL_RENDERABLE_H

#include "renderable.h"
#include "drop_shadow.h"

class material_renderable : public renderable
{
private:
	const renderable*  _parent;

protected:
	drop_shadow* _shadow;
	colour       _outline_colour;

	material_renderable(const renderable* parent);
	~material_renderable();

public:
	bool render_shadow;

	const   renderable& get_parent()                   const;
	virtual bool render();
	virtual bool render_outline()                      = 0;
	void    set_coordinates(float x, float y, float z);
};

#endif