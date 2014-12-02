#ifndef OGL_Rectangle_H
#define OGL_Rectangle_H

#include "OGLShape.h"

class OGLRectangle final : public OGLShape
{
	public:
		OGLRectangle(int x, int y, int width, int height) :OGLShape(x, y, width, height) {}

		bool render();
};

#endif