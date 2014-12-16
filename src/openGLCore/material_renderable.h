#ifndef MATERIAL_RENDERABLE_SHAPE_H
#define MATERIAL_RENDERABLE_SHAPE_H

#include "..\openGLCore\renderable.h"

class material_renderable : public renderable
{
    protected:
		const renderable* _parent;
		renderable*       _shadow;
    
    public:
		material_renderable(const renderable& parent);
		~material_renderable();

		const renderable&  get_parent() const;
		renderable*        get_shadow() const;
		virtual bool       render();
		virtual bool       resize(float width, float height);
		virtual void       set_coordinates(const hCoordinate& value);
		virtual void       set_coordinates(float x, float y, float z);
};

#endif