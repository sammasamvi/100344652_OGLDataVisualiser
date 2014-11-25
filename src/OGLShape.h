#ifndef OGL_SHAPE_H
#define OGL_SHAPE_H

#include "homogenCoord.h"
#include "OGLRenderable.h"

//Base class for drawing two-dimentional shapes in opengl
class OGLShape : public OGLRenderable
{
	private:
		float	      _height;
		float	      _width;
		homogenCoord* _position;
	
	public:
		OGLShape(float width, float height, homogenCoord& position);
		
		float         getHeight();
		homogenCoord& getPosition();
		float         getWidth();
		void          move(homogenCoord& vector);
		virtual bool  render() = 0;
		void          setDimentions(float width, float height);
		void          setPosition(homogenCoord& poit);
};

#endif