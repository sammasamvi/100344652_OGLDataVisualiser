#ifndef DROP_SHADOW_H
#define DROP_SHADOW_H

#include "renderable.h"

class drop_shadow final
{
    private:
		const renderable* _gparent;
		float             _opacity;
		renderable*       _parent;
		colour            _parent_colour;
		hCoordinate       _parent_coordinates;
		float             _parent_depth;
		float             _parent_height;
		float             _parent_width;
		bool              _render_attempted;

		void store_parent_variables();
		void calc_shadow_variables();
		void restore_parent_variables();

    public:
		drop_shadow(renderable* parent);
		~drop_shadow();

		bool render();
		void set_opacity(float value);
};

#endif