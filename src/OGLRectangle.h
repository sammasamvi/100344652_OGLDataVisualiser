#ifndef OGL_Rectangle_H
#define OGL_Rectangle_H

#include "OGLShape.h"

class OGLRectangle : public OGLShape
{
	public:
		OGLRectangle(float width, float height, homogenCoord& position) :OGLShape(width, height, position) {}

		bool render();
};

#endif