#ifndef OGL_SHAPE_2D_H
#define OGL_SHAPE_2D_H

#include "OGLRenderable.h"

class OGLShape2D : public OGLRenderable
{
	private:
		float height;
		float width;
		float x;
		float y;

	public:
		OGLShape2D(int x, int y, float width, float height);

		virtual float getHeight();
		virtual float getWidth();
		virtual int   getX();
		virtual int   getY();
		virtual bool  render() = 0;
		virtual void  setDimentions(float width, float height);
		virtual void  setPosition(int x, int y);
};

#endif