#ifndef MATERIAL_RECTANGLE_H
#define MATERIAL_RECTANGEL_H

#include "..\openGLCore\material_renderable.h"

class material_rectangle final : public material_renderable
{
    private:
		material_rectangle(const material_rectangle* parent);

    public:
		material_rectangle(const renderable& parent);

		bool render();
		bool resize(int width, int height);
};

#endif