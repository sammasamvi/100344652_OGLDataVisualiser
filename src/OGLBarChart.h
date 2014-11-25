#ifndef OGL_BAR_CHART_H
#define OGL_BAR_CHART_H

#include "OGLScene.h"

class OGLBarChart final : public OGLScene
{
	public:
		bool close();
		bool render();
};

#endif