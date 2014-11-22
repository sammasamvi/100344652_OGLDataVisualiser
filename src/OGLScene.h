#ifndef OGL_SCENE_H
#define OGL_SCENE_H

#include "OGLRenderable.h"

class OGLScene : public OGLRenderable
{
	public:
		virtual bool close()  = 0;
		virtual bool render() = 0;
};

#endif