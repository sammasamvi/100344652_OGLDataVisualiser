#ifndef OGL_SCENE_H
#define OGL_SCENE_H

#include "Colour.h"
#include "EDimention.h"
#include "OGLRenderable.h"

class OGLScene : public OGLRenderable
{
    protected:
		Colour* _bColour;
		int     _height;
		int     _width;

		void assertColour(const Colour& colour) const;

	public:
		virtual bool close()                            = 0;
		Colour&      getBackgroudColour()               const;
		int          getDimention(EDimention dimention) const;
		virtual bool render()                           = 0;
		virtual void resize(int width, int height);
		virtual void setBackgroudColour(int red, int green, int blue);
		virtual void setBackgroudColour(Colour& colour);
};

#endif