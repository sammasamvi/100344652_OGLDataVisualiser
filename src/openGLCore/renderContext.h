#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include <Windows.h>
#include "renderable.h"

class renderContext final : public renderable
{
	private:
		renderable* _scene;
		HGLRC	    _renderingContextHandle;
		HDC		    _renderingDeviceContextHandle;
		HWND*	    _windowHandle;
	
		void set_ogl_vars();
		void assert_glClearColor();
	public:
		renderContext(HWND& windowHandle);
		~renderContext();
	
		void init_renderContext(int renderContextWidth, int renderContextHeight);
		bool render();
		bool resize(float width, float height);
		void set_colour(const colour& value);
		void set_colour(int red, int green, int blue, int alpha);
		void set_render_scene(renderable& windowHandle);
};

#endif