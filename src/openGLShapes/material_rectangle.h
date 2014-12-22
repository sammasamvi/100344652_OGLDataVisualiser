#ifndef MATERIAL_RECTANGLE_H
#define MATERIAL_RECTANGEL_H

#include "..\openGLCore\material_renderable.h"

class material_rectangle final : public material_renderable
{
    public:
		material_rectangle(const renderable* parent);

		bool render_fill();
		bool render_outline();
};

#endif