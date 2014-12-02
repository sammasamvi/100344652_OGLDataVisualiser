#ifndef OGL_CHART_H
#define OGL_CHART_H

#include "Margin.h"
#include "OGLDataRepresenter.h"
#include "OGLScene.h"
#include <iostream>

class OGLChart : public OGLScene
{
	protected:
		OGLScene*           _parent;
		OGLDataRepresenter* _dataRepresenters[1];
		Margin*             _margin;
	
	public:
		OGLChart(OGLScene& parent);

		void loadData(std::string dataSource);
		void purgeData();
		void setMargin(int left_right, int bottom_top);
		void setMargin(int left, int bottom, int right, int top);
		void setMargin(Margin& margin);
};

#endif