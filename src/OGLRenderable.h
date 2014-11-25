#ifndef OGL_RENDERABLE_H
#define OGL_RENDERABLE_H

#include <Windows.h>
#include <gl\GL.h>

class OGLRenderable
{
	public:
		virtual bool render() = 0;
};

#endif
