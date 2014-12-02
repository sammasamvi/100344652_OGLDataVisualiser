#ifndef OGL_DATA_REPRESENTER_H
#define OGL_DATA_REPRESENTER_H

#include "Colour.h"
#include "OGLRenderable.h"

class OGLDataRepresenter final
{
	private:
		Colour*        _colour;
		OGLRenderable* _renderable;

    public:
		OGLDataRepresenter();
		OGLDataRepresenter(Colour& colour, OGLRenderable& renderable);

		const Colour&        getColour()     const;
		const OGLRenderable& getRenderable() const;
};

#endif