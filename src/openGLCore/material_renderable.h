#ifndef MATERIAL_RENDERABLE_H
#define MATERIAL_RENDERABLE_H

#include "..\materialLaw\child_renderable.h"
#include "..\materialLaw\drop_shadow.h"

class material_renderable : public child_renderable
{
protected:
	drop_shadow* _shadow;
	colour       _outline_colour;

	material_renderable(const renderable* parent);
	~material_renderable();

public:
	bool render_shadow;

	virtual bool render();			 
	virtual bool render_outline()    = 0;
};

#endif