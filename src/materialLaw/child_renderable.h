#ifndef CHILD_RENDERABLE_H
#define CHILD_RENDERABLE_H

#include "..\openGLCore\renderable.h"

class child_renderable : public renderable
{
    protected:
		const renderable* _parent;

		child_renderable(const renderable* parent);

    public:
		~child_renderable();

		const renderable* get_parent() const;
		virtual bool      render()     = 0;
		void              set_coordinates(float x, float y, float z);
};

#endif