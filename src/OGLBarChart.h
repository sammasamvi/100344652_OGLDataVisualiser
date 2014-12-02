#ifndef OGL_BAR_CHART_H
#define OGL_BAR_CHART_H

#include "OGLChart.h"
#include "OGLRectangle.h"

class OGLBarChart final : public OGLChart
{
	private:
		OGLRectangle* _background;
		Colour*       _axisColour;
		float         _axisWidth;

		virtual bool renderAxes();
		virtual bool renderBars();
		virtual bool renderScale();
		
	public:
		OGLBarChart(OGLScene& parent);

		bool close();
		bool render();
		void resize(int width, int height);
		void setAxisColour(int red, int green, int blue);
		void setAxisColour(Colour& colour);
		void setBackgroudColour(int red, int green, int blue);
		void setBackgroudColour(Colour& colour);
};

#endif