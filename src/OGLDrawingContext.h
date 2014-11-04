#ifndef OGL_DRAWING_CONTEXT_H
#define OGL_DRAWING_CONTECT_H

#include <Windows.h>
#include <gl\GL.h>
#include "OGLScene.h"

class OGLDrawingContext final
{
	private:
		OGLScene* Scene;
		HDC		  deviceContextHandle;
		HGLRC	  renderingContextHandle;
		HWND	  winHandle;
		int		  width;
		int		  height;
	
	public:
		OGLDrawingContext(HWND windowHandle);
		~OGLDrawingContext();

		void assignScene(OGLScene* Scene);
		void initOGLRenderContext(int width, int height);
		void render();
		void resize(int width, int height);
};

#endif